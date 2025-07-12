#ifndef SERVER_H
#define SERVER_H

#include <QObject>
#include <QList>
#include <QVector>
#include <QMap>
#include <QDateTime>
struct GameHistory
{
    QString opponentUsername;
    QString gameDate;
    QList<QString> roundResults;
    QString finalResult;
};
struct User{
    QString username;
    QString passwordHash;
    QString email;
    QString phoneNumber;
    QString firstName;
    QString lastname;
    QList<GameHistory> gameHistory;
};

class QTcpServer;
class QTcpSocket;
class Server: public QObject
{
    Q_OBJECT
private:
    QTcpServer* m_tcpServer;
    QMap<QTcpSocket*, QString> m_connectedClients;
    QVector<User>m_users;
    QList<QTcpSocket*> m_waitingForGame;
   void saveUsersToFile();
    void loadUserFromFile();
public:
    Server(QObject* parent=nullptr);
    void start(quint16 port);
private slots:
    void handleConnection();
    void GameFinished(const QString & player1username,const GameHistory& historyP1,const QString player2username,const GameHistory& historyP2);

};

#endif
