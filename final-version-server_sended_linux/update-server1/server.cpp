#include "server.h"
#include <QTcpServer>
#include <QTcpSocket>
#include <QNetworkInterface>
#include <QDebug>
#include <QCryptographicHash>
#include <QFile>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>

Server::Server(QObject* parent) : QObject(parent) {
    m_tcpServer = new QTcpServer(this);
    connect(m_tcpServer, &QTcpServer::newConnection, this, &Server::handleConnection);
    qDebug() << "Server initializing...";
    loadUserFromFile();
}

void Server::start(quint16 port)
{
    if(!m_tcpServer->listen(QHostAddress::Any, port))
    {
        qDebug() << "Error: Could not start the server. Check if port" << port << "is already in use or if you have necessary permissions.";
        return;
    }

    QString ipAddress;
    const QList<QHostAddress> ipAddressList = QNetworkInterface::allAddresses();
    for(const QHostAddress &addr : ipAddressList)
    {
        if(addr != QHostAddress::LocalHost && addr.toIPv4Address())
        {
            ipAddress = addr.toString();
            break;
        }
    }
    if(ipAddress.isEmpty())
    {
        ipAddress = QHostAddress(QHostAddress::LocalHost).toString();
    }
    qDebug() << "Server is listening on IP" << ipAddress << "Port:" << port;
}

void Server::handleConnection()
{
    qDebug() << "A new client is trying to connect...";
    QTcpSocket* clientSocket = m_tcpServer->nextPendingConnection();
    if(!clientSocket)
    {
        qDebug() << "Failed to get next pending connection. Client socket is null.";
        return;
    }
    qDebug() << "Client connected successfully from IP:" << clientSocket->peerAddress().toString() << "Port:" << clientSocket->peerPort();

    connect(clientSocket, &QTcpSocket::readyRead, [this, clientSocket]()
    {
        QByteArray data = clientSocket->readAll();
        QString message = QString::fromUtf8(data).trimmed();
        qDebug() << "Received raw message from client:" << clientSocket->peerAddress().toString() << ":" << message;

        QStringList parts = message.split(';');
        if(parts.isEmpty())
        {
            qDebug() << "Received empty message or invalid format (no parts). Message:" << message;
            return;
        }
        QString command = parts[0];
        qDebug() << "Parsed command:" << command;

        if(command == "SIGNUP")
        {
            if(parts.size() < 7)
            {
                qDebug() << "Not enough data for SIGNUP. Expected 7 parts (cmd;first;last;phone;email;username;hashedpass), got:" << parts.size();
                clientSocket->write("SIGNUP_FAIL;INVALID_DATA\n");
                return;
            }
            QString newUsername = parts[5];
            bool usernameExists = false;
            for(const User &user : m_users)
            {
                if(user.username == newUsername)
                {
                    usernameExists = true;
                    break;
                }
            }
            if(usernameExists)
            {
                qDebug() << "Username" << newUsername << "is already taken.";
                clientSocket->write("SIGNUP_FAIL;USERNAME_TAKEN\n");
            }
            else
            {
                qDebug() << "Username" << newUsername << "is available. Registering user...";
                User newUser;
                newUser.firstName = parts[1];
                newUser.lastname = parts[2];
                newUser.phoneNumber = parts[3];
                newUser.email = parts[4];
                newUser.username = parts[5];
                newUser.passwordHash = parts[6];

                m_users.append(newUser);
                saveUsersToFile();
                clientSocket->write("SIGNUP_SUCCESS\n");
                qDebug() << "User" << newUsername << "registered successfully.";
            }
        }
        else if(command == "LOGIN")
        {
            qDebug() << "LOGIN command received.";
            if(parts.size() < 3)
            {
                qDebug() << "Not enough data for LOGIN. Expected 3 parts (cmd;username;hashedpass), got:" << parts.size();
                clientSocket->write("LOGIN_FAIL;INVALID_DATA\n");
                return;
            }
            QString username = parts[1];
            QString hashedPasswordFromClient = parts[2];

            bool userFound = false;
            bool passwordMatch = false;
            for(const User &user : m_users)
            {
                if(user.username == username)
                {
                    userFound = true;
                    if(user.passwordHash == hashedPasswordFromClient)
                    {
                        passwordMatch = true;
                    }
                    break;
                }
            }

            if(userFound && passwordMatch)
            {
                qDebug() << "User" << username << "logged in successfully.";
                m_connectedClients[clientSocket] = username;
                clientSocket->write("LOGIN_SUCCESS\n");
            }
            else if(userFound)
            {
                qDebug() << "Incorrect password for user:" << username;
                clientSocket->write("LOGIN_FAIL;WRONG_PASSWORD\n");
            }
            else
            {
                qDebug() << "User" << username << "not found.";
                clientSocket->write("LOGIN_FAIL;USER_NOT_FOUND\n");
            }
        }
        else if(command == "START_GAME")
        {
            qDebug()<<"Received START_GAME command.";
            QString requestingUsername = m_connectedClients.value(clientSocket);
            if (requestingUsername.isEmpty()) {
                qDebug() << "START_GAME request from unknown client (not logged in).";
                clientSocket->write("ERROR;NOT_LOGGED_IN\n");
                return;
            }

            if(m_waitingForGame.contains(clientSocket))
            {
                qDebug()<<"The player" << requestingUsername << "is already in the waiting list.";
                clientSocket->write("ALREADY_IN_WAITING_LIST\n");
                return;
            }

            m_waitingForGame.append(clientSocket);
            qDebug()<<"Added player" << requestingUsername << "to waiting list. Current waiting players:" << m_waitingForGame.size();

            if(m_waitingForGame.size() == 2)
            {
                qDebug()<<"Two players found, let's start the game!";
                QTcpSocket* player1 = m_waitingForGame.takeFirst();
                QTcpSocket* player2 = m_waitingForGame.takeFirst();
                QString p1_username = m_connectedClients[player1];
                QString p2_username = m_connectedClients[player2];

                player1->write(QString("GAME_STARTING;%1\n").arg(p2_username).toUtf8());
                player2->write(QString("GAME_STARTING;%1\n").arg(p1_username).toUtf8());

                qDebug() << "GameSession creation and start logic would go here.";
            }
            else
            {
                clientSocket->write("WAITING_FOR_OPPONENT\n");
            }
        }
        else if (command == "LOGOUT") {
            qDebug() << "Received LOGOUT command.";
            QString usernameLoggingOut = m_connectedClients.value(clientSocket);
            if (!usernameLoggingOut.isEmpty()) {
                m_connectedClients.remove(clientSocket); 
                                                        
                qDebug() << "User" << usernameLoggingOut << "logged out.";
                clientSocket->write("LOGOUT_SUCCESS\n");
            } else {
                qDebug() << "Logout request from unknown client. No user associated with this socket.";
                clientSocket->write("LOGOUT_FAIL\n");
            }
        }
        else if (command == "UPDATE_PROFILE") {
            if (parts.size() < 7) {
                qDebug() << "Not enough data for profile update. Expected 7 parts, got:" << parts.size();
                clientSocket->write("UPDATE_PROFILE_FAIL;INVALID_DATA\n");
                return;
            }
            QString oldUsername = m_connectedClients.value(clientSocket);
            if (oldUsername.isEmpty()) {
                qDebug() << "Profile update from unknown client. Not logged in.";
                clientSocket->write("ERROR;NOT_LOGGED_IN\n");
                return;
            }

            QString newFirstName = parts[1];
            QString newLastName = parts[2];
            QString newPhoneNumber = parts[3];
            QString newEmail = parts[4];
            QString newUsername = parts[5];
            QString newHashedPassword = parts[6];

            bool usernameTaken = false;
            for (const User &user : m_users) {
                if (user.username == newUsername && user.username != oldUsername) {
                    usernameTaken = true;
                    break;
                }
            }

            if (usernameTaken) {
                qDebug() << "New username" << newUsername << "is already taken by another user.";
                clientSocket->write("UPDATE_PROFILE_FAIL;USERNAME_TAKEN\n");
            } else {
                bool userUpdated = false;
                for (User &user : m_users) {
                    if (user.username == oldUsername) {
                        user.firstName = newFirstName;
                        user.lastname = newLastName;
                        user.phoneNumber = newPhoneNumber;
                        user.email = newEmail;
                        user.username = newUsername;
                        user.passwordHash = newHashedPassword;
                        userUpdated = true;
                        if (oldUsername != newUsername) {
                            m_connectedClients.insert(clientSocket, newUsername);
                        }
                        break;
                    }
                }

                if (userUpdated) {
                    saveUsersToFile();
                    qDebug() << "Profile for user" << oldUsername << "updated successfully to username:" << newUsername;
                    clientSocket->write("UPDATE_PROFILE_SUCCESS\n");
                } else {
                    qDebug() << "Could not find user" << oldUsername << "to update profile (internal error).";
                    clientSocket->write("UPDATE_PROFILE_FAIL;INTERNAL_ERROR\n");
                }
            }
        }
        else
        {
            qDebug()<<"Unknown command received:"<<command;
            clientSocket->write("ERROR;UNKNOWN_COMMAND\n");
        }
    });

    connect(clientSocket, &QTcpSocket::disconnected, [this, clientSocket]()
            {
        QString disconnectedUsername = m_connectedClients.value(clientSocket, "Unknown");
        qDebug()<<"Client" << disconnectedUsername << "disconnected from" << clientSocket->peerAddress().toString();
        m_connectedClients.remove(clientSocket);
        m_waitingForGame.removeOne(clientSocket);
        clientSocket->deleteLater(); 
    });
}

void Server::saveUsersToFile()
{
    qDebug() << "Saving users to users.json...";
    QJsonArray usersArray;
    for(const User &user : m_users)
    {
        QJsonObject userObject;
        userObject["username"] = user.username;
        userObject["passwordHash"] = user.passwordHash;
        userObject["email"] = user.email;
        userObject["phoneNumber"] = user.phoneNumber;
        userObject["firstName"] = user.firstName;
        userObject["lastName"] = user.lastname;

        QJsonArray historyArray;
        for(const GameHistory &history : user.gameHistory)
        {
            QJsonObject historyObject;
            historyObject["opponent"] = history.opponentUsername;
            historyObject["date"] = history.gameDate;
            historyObject["result"] = history.finalResult;
            historyArray.append(historyObject);
        }
        userObject["gameHistory"] = historyArray;

        usersArray.append(userObject);
    }

    QJsonDocument doc(usersArray);
    QFile file("users.json");
    if(!file.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Truncate))
    {
        qDebug() << "Error: Could not open users.json for writing:" << file.errorString();
        return;
    }
    file.write(doc.toJson(QJsonDocument::Indented));
    file.close();
    qDebug() << "Users data saved successfully to users.json. Total users:" << m_users.size();
}

void Server::loadUserFromFile()
{
    qDebug() << "Loading users from users.json...";
    QFile file("users.json");
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug() << "Warning: Could not open users.json for reading or file does not exist. A new file will be created on first save.";
        m_users.clear();
        return;
    }
    QByteArray fileData = file.readAll();
    file.close();
    QJsonDocument doc = QJsonDocument::fromJson(fileData);
    if(!doc.isArray())
    {
        qDebug() << "Warning: User data file is empty or corrupted (not a JSON array). Starting with an empty user list.";
        m_users.clear();
        return;
    }
    QJsonArray usersArray = doc.array();
    m_users.clear();
    for(const QJsonValue &value : usersArray)
    {
        QJsonObject userObject = value.toObject();
        User user;
        user.username = userObject["username"].toString();
        user.passwordHash = userObject["passwordHash"].toString();
        user.email = userObject["email"].toString();
        user.phoneNumber = userObject["phoneNumber"].toString();
        user.firstName = userObject["firstName"].toString();
        user.lastname = userObject["lastName"].toString();

        if(userObject.contains("gameHistory") && userObject["gameHistory"].isArray())
        {
            QJsonArray historyArray = userObject["gameHistory"].toArray();
            for(const QJsonValue &historyValue : historyArray)
            {
                QJsonObject historyObject = historyValue.toObject();
                GameHistory history;
                history.opponentUsername = historyObject["opponent"].toString();
                history.gameDate = historyObject["date"].toString();
                history.finalResult = historyObject["result"].toString();
                history.roundResults.clear();
                user.gameHistory.append(history);
            }
        }
        m_users.append(user);
    }
    qDebug() << "Loaded users from users.json successfully. Total users:" << m_users.size();
}

void Server::GameFinished(const QString &player1username, const GameHistory& historyP1, const QString player2username, const GameHistory& historyP2)
{
    qDebug()<<"Received finished game signal, saving history...";
    bool player1Found = false;
    bool player2Found = false;

    for(User &user : m_users)
    {
        if(user.username == player1username)
        {
            user.gameHistory.prepend(historyP1);
            while (user.gameHistory.size() > 3) {
                user.gameHistory.removeLast();
            }
            player1Found = true;
        }
        else if (user.username == player2username)
        {
            user.gameHistory.prepend(historyP2);
            while (user.gameHistory.size() > 3) {
                user.gameHistory.removeLast();
            }
            player2Found = true;
        }
        if (player1Found && player2Found) {
            break;
        }
    }
    saveUsersToFile();
    qDebug()<<"Game history saved for players.";
}