#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QRegularExpression> 
#include <QCryptographicHash> 
#include <QByteArray>         
#include <QTcpSocket>         
#include <QHostAddress>       

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT 

public:
    
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_loginButton_clicked();
    void on_signUpButton_clicked();
    void on_forgotPasswordButton_clicked();
    void on_registerButton_clicked();
    void on_backToLoginButton_clicked();
    void on_startGameButton_clicked();
    void on_editProfileButton_clicked();
    void on_gameHistoryButton_clicked();
    void on_logoutButton_clicked();
    void on_saveProfileButton_clicked();
    void on_cancelProfileButton_clicked();
    void on_backToMainMenuFromHistoryButton_clicked();
    void on_selectCardButton_clicked();
    void on_requestExchangeButton_clicked();
    void on_stopResumeButton_clicked();
    void on_exitGameButton_clicked();
    void on_socketConnected();  
    void on_socketDisconnected(); 
    void on_socketReadyRead();
    void on_socketError(QAbstractSocket::SocketError socketError);


private:
    Ui::MainWindow *ui; 
    QTcpSocket *clientSocket;
    QString currentUsername;
    bool validateEmail(const QString& email);
    bool validatePhoneNumber(const QString& phoneNumber);
};
#endif
