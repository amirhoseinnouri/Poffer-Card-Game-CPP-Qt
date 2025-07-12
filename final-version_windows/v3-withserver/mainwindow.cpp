#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMessageBox>
#include <QRegularExpression>
#include <QCryptographicHash>
#include <QByteArray>
#include <QTcpSocket>
#include <QHostAddress>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , clientSocket(new QTcpSocket(this))
{
    ui->setupUi(this);

    connect(ui->loginButton, &QPushButton::clicked, this, &MainWindow::on_loginButton_clicked);
    connect(ui->signUpButton, &QPushButton::clicked, this, &MainWindow::on_signUpButton_clicked);
    connect(ui->forgotPasswordButton, &QPushButton::clicked, this, &MainWindow::on_forgotPasswordButton_clicked);
    connect(ui->registerButton, &QPushButton::clicked, this, &MainWindow::on_registerButton_clicked);
    connect(ui->backToLoginButton, &QPushButton::clicked, this, &MainWindow::on_backToLoginButton_clicked);

    connect(ui->startGameButton, &QPushButton::clicked, this, &MainWindow::on_startGameButton_clicked);
    connect(ui->editProfileButton, &QPushButton::clicked, this, &MainWindow::on_editProfileButton_clicked);
    connect(ui->gameHistoryButton, &QPushButton::clicked, this, &MainWindow::on_gameHistoryButton_clicked);
    connect(ui->logoutButton, &QPushButton::clicked, this, &MainWindow::on_logoutButton_clicked);

    connect(ui->saveProfileButton, &QPushButton::clicked, this, &MainWindow::on_saveProfileButton_clicked);
    connect(ui->cancelProfileButton, &QPushButton::clicked, this, &MainWindow::on_cancelProfileButton_clicked);

    connect(ui->backToMainMenuFromHistoryButton, &QPushButton::clicked, this, &MainWindow::on_backToMainMenuFromHistoryButton_clicked);

    connect(ui->selectCardButton, &QPushButton::clicked, this, &MainWindow::on_selectCardButton_clicked);
    connect(ui->requestExchangeButton, &QPushButton::clicked, this, &MainWindow::on_requestExchangeButton_clicked);
    connect(ui->stopResumeButton, &QPushButton::clicked, this, &MainWindow::on_stopResumeButton_clicked);
    connect(ui->exitGameButton, &QPushButton::clicked, this, &MainWindow::on_exitGameButton_clicked);

    connect(clientSocket, &QTcpSocket::connected, this, &MainWindow::on_socketConnected);
    connect(clientSocket, &QTcpSocket::disconnected, this, &MainWindow::on_socketDisconnected);
    connect(clientSocket, &QTcpSocket::readyRead, this, &MainWindow::on_socketReadyRead);
    connect(clientSocket, QOverload<QAbstractSocket::SocketError>::of(&QAbstractSocket::errorOccurred), this, &MainWindow::on_socketError);

    ui->stackedWidget->setCurrentIndex(0);
}

MainWindow::~MainWindow()
{
    if (clientSocket->state() == QAbstractSocket::ConnectedState) {
        clientSocket->disconnectFromHost();
        clientSocket->waitForDisconnected(1000);
    }
    delete clientSocket;
    delete ui;
}
bool MainWindow::validateEmail(const QString& email) {
    QRegularExpression emailRegex("\\b[A-Z0-9._%+-]+@[A-Z0-9.-]+\\.[A-Z]{2,4}\\b", QRegularExpression::CaseInsensitiveOption);
    return emailRegex.match(email).hasMatch();
}
bool MainWindow::validatePhoneNumber(const QString& phoneNumber) {
    QRegularExpression phoneRegex("^09\\d{9}$");
    return phoneRegex.match(phoneNumber).hasMatch();
}
void MainWindow::on_loginButton_clicked()
{
    QString username = ui->usernameLineEdit->text();
    QString password = ui->passwordLineEdit->text();

    if (username.isEmpty() || password.isEmpty())
    {
        QMessageBox::warning(this, "Login Error", "لطفاً نام کاربری و رمز عبور را وارد کنید.");
    }
    else
    {
        QMessageBox::information(this, "Login Attempt", "در حال تلاش برای ورود با نام کاربری: " + username);

        currentUsername = username;

        if (clientSocket->state() == QAbstractSocket::UnconnectedState) {
            clientSocket->connectToHost(QHostAddress("192.168.73.99"), 5555);
        } else if (clientSocket->state() == QAbstractSocket::ConnectedState) {
            QByteArray hashedPassword = QCryptographicHash::hash(password.toUtf8(), QCryptographicHash::Sha256).toHex();
            clientSocket->write(QString("LOGIN;%1;%2\n").arg(username, QString(hashedPassword)).toUtf8());
        } else {
            QMessageBox::warning(this, "Connection Status", "وضعیت اتصال به سرور نامشخص است. لطفاً دوباره تلاش کنید.");
        }
    }
}

void MainWindow::on_signUpButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
    ui->signUpNameLineEdit->clear();
    ui->signUpLastNameLineEdit->clear();
    ui->signUpPhoneNumberLineEdit->clear();
    ui->signUpEmailLineEdit->clear();
    ui->signUpUsernameLineEdit->clear();
    ui->signUpPasswordLineEdit->clear();
}

void MainWindow::on_forgotPasswordButton_clicked()
{
    QMessageBox::information(this, "Forgot Password", "لطفاً شماره تلفن خود را برای تغییر رمز عبور وارد کنید. (عملکرد بازنشانی رمز عبور واقعی پیاده‌سازی خواهد شد).");
}

void MainWindow::on_registerButton_clicked()
{
    QString name = ui->signUpNameLineEdit->text();
    QString lastName = ui->signUpLastNameLineEdit->text();
    QString phoneNumber = ui->signUpPhoneNumberLineEdit->text();
    QString email = ui->signUpEmailLineEdit->text();
    QString username = ui->signUpUsernameLineEdit->text();
    QString password = ui->signUpPasswordLineEdit->text();

    if (name.isEmpty() || lastName.isEmpty() || phoneNumber.isEmpty() || email.isEmpty() || username.isEmpty() || password.isEmpty())
    {
        QMessageBox::warning(this, "Registration Error", "همه فیلدها الزامی هستند. لطفاً آن‌ها را پر کنید.");
        return;
    }

    if (password.length() < 8)
    {
        QMessageBox::warning(this, "Registration Error", "رمز عبور برای امنیت بالا باید حداقل ۸ کاراکتر باشد.");
        return;
    }

    if (!validateEmail(email)) {
        QMessageBox::warning(this, "Registration Error", "لطفاً یک آدرس ایمیل معتبر وارد کنید.");
        return;
    }

    if (!validatePhoneNumber(phoneNumber)) {
        QMessageBox::warning(this, "Registration Error", "لطفاً یک شماره تلفن معتبر وارد کنید (مثال: 09xxxxxxxxx).");
        return;
    }

    QByteArray hashedPassword = QCryptographicHash::hash(password.toUtf8(), QCryptographicHash::Sha256).toHex();

    QMessageBox::information(this, "Registration Attempt",
                             "در حال تلاش برای ثبت نام کاربر جدید:\n"
                             "نام کاربری: " + username + "\n"
                                              "هش رمز عبور (مثال): " + QString(hashedPassword) + "\n"
                                                             " (بررسی وجود نام کاربری و ذخیره سازی سمت سرور انجام می‌شود)");

    if (clientSocket->state() == QAbstractSocket::ConnectedState) {
        clientSocket->write(QString("SIGNUP;%1;%2;%3;%4;%5;%6\n")
                                .arg(name, lastName, phoneNumber, email, username, QString(hashedPassword))
                                .toUtf8());
    } else {
        QMessageBox::warning(this, "Registration Error", "به سرور متصل نیستید. لطفاً ابتدا اتصال را برقرار کنید.");
        return;
    }

    QMessageBox::information(this, "Registration Successful", "درخواست ثبت نام ارسال شد. لطفاً پس از تأیید سرور وارد شوید.");
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_backToLoginButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_startGameButton_clicked()
{
    if (clientSocket->state() == QAbstractSocket::ConnectedState) {
        clientSocket->write(QString("START_GAME;%1\n").arg(currentUsername).toUtf8());
        ui->gameLogTextEdit->appendPlainText("درخواست شروع بازی ارسال شد. منتظر بازیکنان دیگر...");
        ui->stackedWidget->setCurrentIndex(5);
    } else {
        QMessageBox::warning(this, "Game Start Error", "به سرور متصل نیستید. لطفاً ابتدا وارد شوید.");
    }
}
void MainWindow::on_editProfileButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}
void MainWindow::on_gameHistoryButton_clicked()
{
    QMessageBox::information(this, "Game History", "در حال بارگذاری تاریخچه بازی‌های گذشته (حداکثر 3 بازی).");
    ui->stackedWidget->setCurrentIndex(4);

    ui->gameHistoryTextEdit->setPlainText("بازی ۱: بازیکن الف در مقابل بازیکن ب - برد (تاریخ)\n"
                                          "بازی ۲: بازیکن الف در مقابل بازیکن ج - باخت (تاریخ)\n"
                                          "بازی ۳: بازیکن الف در مقابل بازیکن د - برد (تاریخ)");
}
void MainWindow::on_logoutButton_clicked()
{
    QMessageBox::information(this, "Logout", "شما با موفقیت از حساب کاربری خود خارج شدید.");
    if (clientSocket->state() == QAbstractSocket::ConnectedState) {
        clientSocket->write(QString("LOGOUT;%1\n").arg(currentUsername).toUtf8());
    }
    currentUsername.clear();
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_saveProfileButton_clicked()
{
    QString name = ui->editNameLineEdit->text();
    QString lastName = ui->editLastNameLineEdit->text();
    QString phoneNumber = ui->editPhoneNumberLineEdit->text();
    QString email = ui->editEmailLineEdit->text();
    QString username = ui->editUsernameLineEdit->text();
    QString password = ui->editPasswordLineEdit->text();
    QString confirmPassword = ui->editConfirmPasswordLineEdit->text();

    if (name.isEmpty() || lastName.isEmpty() || phoneNumber.isEmpty() || email.isEmpty() || username.isEmpty() || password.isEmpty() || confirmPassword.isEmpty())
    {
        QMessageBox::warning(this, "Profile Edit Error", "همه فیلدها الزامی هستند. لطفاً آن‌ها را پر کنید.");
        return;
    }

    if (password != confirmPassword) {
        QMessageBox::warning(this, "Profile Edit Error", "رمز عبور جدید و تأیید آن با هم مطابقت ندارند.");
        return;
    }

    if (password.length() < 8)
    {
        QMessageBox::warning(this, "Profile Edit Error", "رمز عبور جدید باید حداقل ۸ کاراکتر باشد.");
        return;
    }

    if (!validateEmail(email)) {
        QMessageBox::warning(this, "Profile Edit Error", "لطفاً یک آدرس ایمیل معتبر وارد کنید.");
        return;
    }

    if (!validatePhoneNumber(phoneNumber)) {
        QMessageBox::warning(this, "Profile Edit Error", "لطفاً یک شماره تلفن معتبر وارد کنید (مثال: 09xxxxxxxxx).");
        return;
    }

    QByteArray hashedPassword = QCryptographicHash::hash(password.toUtf8(), QCryptographicHash::Sha256).toHex();

    QMessageBox::information(this, "Profile Update",
                             "در حال تلاش برای به‌روزرسانی پروفایل:\n"
                             "نام کاربری جدید: " + username + "\n"
                                              "هش رمز عبور جدید (مثال): " + QString(hashedPassword) + "\n"
                                                             " (بررسی وجود نام کاربری و به‌روزرسانی سمت سرور انجام می‌شود)");

    if (clientSocket->state() == QAbstractSocket::ConnectedState) {
        clientSocket->write(QString("UPDATE_PROFILE;%1;%2;%3;%4;%5;%6\n")
                                .arg(name, lastName, phoneNumber, email, username, QString(hashedPassword))
                                .toUtf8());
    } else {
        QMessageBox::warning(this, "Profile Update Error", "به سرور متصل نیستید.");
        return;
    }

    QMessageBox::information(this, "Profile Update Successful", "درخواست به‌روزرسانی پروفایل ارسال شد.");
    currentUsername = username;
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_cancelProfileButton_clicked()
{
    QMessageBox::information(this, "Profile Edit Cancelled", "تغییرات پروفایل لغو شد.");
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_backToMainMenuFromHistoryButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_selectCardButton_clicked()
{
    if (clientSocket->state() == QAbstractSocket::ConnectedState) {
        QString selectedCardID = "Card_ID_Placeholder";
        clientSocket->write(QString("SELECT_CARD;%1\n").arg(selectedCardID).toUtf8());
        ui->gameLogTextEdit->appendPlainText("شما کارتی را انتخاب کردید. منتظر حرکت حریف باشید...");
    } else {
        ui->gameLogTextEdit->appendPlainText("خطا: به سرور متصل نیستید.");
    }
}

void MainWindow::on_requestExchangeButton_clicked()
{
    if (clientSocket->state() == QAbstractSocket::ConnectedState) {
        clientSocket->write("REQUEST_EXCHANGE\n");
        ui->gameLogTextEdit->appendPlainText("درخواست تعویض کارت ارسال شد. منتظر پاسخ حریف...");
    } else {
        ui->gameLogTextEdit->appendPlainText("خطا: به سرور متصل نیستید.");
    }
}

void MainWindow::on_stopResumeButton_clicked()
{
    if (clientSocket->state() == QAbstractSocket::ConnectedState) {
        if (ui->stopResumeButton->text() == "Stop/Resume Game") {
            clientSocket->write("PAUSE_GAME\n");
            ui->gameLogTextEdit->appendPlainText("درخواست توقف بازی ارسال شد. بازی متوقف خواهد شد.");
            ui->stopResumeButton->setText("Resume Game");
        } else {
            clientSocket->write("RESUME_GAME\n");
            ui->gameLogTextEdit->appendPlainText("درخواست ادامه بازی ارسال شد. بازی از سر گرفته خواهد شد.");
            ui->stopResumeButton->setText("Stop/Resume Game");
        }
    } else {
        ui->gameLogTextEdit->appendPlainText("خطا: به سرور متصل نیستید.");
    }
}

void MainWindow::on_exitGameButton_clicked()
{
    if (clientSocket->state() == QAbstractSocket::ConnectedState) {
        clientSocket->write(QString("EXIT_GAME;%1\n").arg(currentUsername).toUtf8());
    }
    QMessageBox::information(this, "Exit Game", "شما از بازی خارج شدید. این اقدام ممکن است منجر به باخت شما شود.");
    ui->stackedWidget->setCurrentIndex(2);
    ui->gameLogTextEdit->clear();
}

void MainWindow::on_socketConnected() {
    ui->gameLogTextEdit->appendPlainText("به سرور متصل شدید.");
    QMessageBox::information(this, "Connected", "اتصال به سرور برقرار شد!");

    if (!currentUsername.isEmpty()) {
        QString password = ui->passwordLineEdit->text(); 
        QByteArray hashedPassword = QCryptographicHash::hash(password.toUtf8(), QCryptographicHash::Sha256).toHex();
        clientSocket->write(QString("LOGIN;%1;%2\n").arg(currentUsername, QString(hashedPassword)).toUtf8());
    }
}

void MainWindow::on_socketDisconnected() {
    ui->gameLogTextEdit->appendPlainText("از سرور قطع شدید.");
    QMessageBox::warning(this, "Connection Lost", "ارتباط با سرور قطع شد. لطفاً دوباره وارد شوید.");
    // ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_socketReadyRead() {
    QByteArray data = clientSocket->readAll();
    QString message = QString::fromUtf8(data).trimmed();
    ui->gameLogTextEdit->appendPlainText("پیام از سرور: " + message);

    if (message.startsWith("LOGIN_SUCCESS")) {
        ui->stackedWidget->setCurrentIndex(2);
        ui->label_welcomeUser->setText("Welcome, " + currentUsername + "!");
        QMessageBox::information(this, "Login Successful", "ورود موفقیت‌آمیز بود!");
    } else if (message.startsWith("LOGIN_FAIL_WRONG_PASSWORD")) {
        QMessageBox::critical(this, "Login Failed", "ورود ناموفق: رمز عبور اشتباه است.");
        ui->stackedWidget->setCurrentIndex(0);
    } else if (message.startsWith("LOGIN_FAIL_USER_NOT_FOUND")) {
        QMessageBox::critical(this, "Login Failed", "ورود ناموفق: نام کاربری یافت نشد.");
        ui->stackedWidget->setCurrentIndex(0);
    } else if (message.startsWith("SIGNUP_SUCCESS")) {
        QMessageBox::information(this, "Sign Up Success", "ثبت نام با موفقیت انجام شد. می‌توانید وارد شوید.");
        ui->stackedWidget->setCurrentIndex(0);
    } else if (message.startsWith("SIGNUP_FAIL_USERNAME_TAKEN")) {
        QMessageBox::warning(this, "Sign Up Failed", "ثبت نام ناموفق: نام کاربری تکراری است.");
    } else if (message.startsWith("UPDATE_PROFILE_SUCCESS")) {
        QMessageBox::information(this, "Profile Update", "پروفایل شما با موفقیت به‌روزرسانی شد!");
        ui->stackedWidget->setCurrentIndex(2);
    } else if (message.startsWith("UPDATE_PROFILE_FAIL_USERNAME_TAKEN")) {
        QMessageBox::warning(this, "Profile Update Failed", "به‌روزرسانی ناموفق: نام کاربری جدید تکراری است.");
    } else if (message.startsWith("GAME_STARTING;")) {
        QString opponentUsername = message.mid(14);
        ui->gameLogTextEdit->appendPlainText(QString("بازی در حال شروع با %1").arg(opponentUsername));
    } else if (message.startsWith("WAITING_FOR_OPPONENT")) {
        ui->gameLogTextEdit->appendPlainText("منتظر حریف هستید...");
    } else if (message.startsWith("DEAL_CARDS;")) {
        QString cardsString = message.mid(11);
        ui->label_playerHand->setText("دست شما: " + cardsString);
    } else if (message.startsWith("OPPONENT_MOVED;")) {
        QString opponentMove = message.mid(15);
        ui->gameLogTextEdit->appendPlainText("حریف حرکت کرد: " + opponentMove);
    } else if (message.startsWith("YOUR_TURN")) {
        ui->gameLogTextEdit->appendPlainText("نوبت شماست! لطفاً کارتی را انتخاب کنید.");
    } else if (message.startsWith("GAME_OVER;")) {
        QString winner = message.mid(10);
        ui->gameLogTextEdit->appendPlainText("بازی تمام شد. برنده: " + winner);
        QMessageBox::information(this, "Game Over", "بازی تمام شد. برنده: " + winner);
        ui->stackedWidget->setCurrentIndex(2);
    } else if (message.startsWith("CHAT_MESSAGE;")) {
        ui->gameLogTextEdit->appendPlainText("چت: " + message.mid(13));
    } else if (message.startsWith("ERROR:")) {
        QMessageBox::critical(this, "Server Error", "خطای سرور: " + message.mid(6));
    }
}

void MainWindow::on_socketError(QAbstractSocket::SocketError socketError) {
    QMessageBox::critical(this, "Network Error", "خطای شبکه: " + clientSocket->errorString());
    ui->gameLogTextEdit->appendPlainText("خطای شبکه: " + clientSocket->errorString());
    if (clientSocket->state() == QAbstractSocket::ConnectedState) {
        clientSocket->disconnectFromHost();
    }
}
