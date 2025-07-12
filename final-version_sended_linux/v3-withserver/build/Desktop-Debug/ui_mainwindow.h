/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.13
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QStackedWidget *stackedWidget;
    QWidget *loginPage;
    QVBoxLayout *verticalLayout_2;
    QSpacerItem *verticalSpacer;
    QLabel *label_loginTitle;
    QLineEdit *usernameLineEdit;
    QLineEdit *passwordLineEdit;
    QPushButton *loginButton;
    QPushButton *signUpButton;
    QPushButton *forgotPasswordButton;
    QSpacerItem *verticalSpacer_2;
    QWidget *signUpPage;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_signUpTitle;
    QLineEdit *signUpNameLineEdit;
    QLineEdit *signUpLastNameLineEdit;
    QLineEdit *signUpPhoneNumberLineEdit;
    QLineEdit *signUpEmailLineEdit;
    QLineEdit *signUpUsernameLineEdit;
    QLineEdit *signUpPasswordLineEdit;
    QPushButton *registerButton;
    QPushButton *backToLoginButton;
    QWidget *mainMenuPage;
    QVBoxLayout *verticalLayout_4;
    QSpacerItem *verticalSpacer_3;
    QLabel *label_mainMenuTitle;
    QLabel *label_welcomeUser;
    QPushButton *startGameButton;
    QPushButton *editProfileButton;
    QPushButton *gameHistoryButton;
    QPushButton *logoutButton;
    QSpacerItem *verticalSpacer_4;
    QWidget *editProfilePage;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_editProfileTitle;
    QFormLayout *formLayout;
    QLabel *label_name;
    QLineEdit *editNameLineEdit;
    QLabel *label_lastName;
    QLineEdit *editLastNameLineEdit;
    QLabel *label_phoneNumber;
    QLineEdit *editPhoneNumberLineEdit;
    QLabel *label_email;
    QLineEdit *editEmailLineEdit;
    QLabel *label_username;
    QLineEdit *editUsernameLineEdit;
    QLabel *label_password;
    QLineEdit *editPasswordLineEdit;
    QLabel *label_confirmPassword;
    QLineEdit *editConfirmPasswordLineEdit;
    QSpacerItem *verticalSpacer_5;
    QHBoxLayout *horizontalLayout;
    QPushButton *saveProfileButton;
    QPushButton *cancelProfileButton;
    QWidget *gameHistoryPage;
    QVBoxLayout *verticalLayout_6;
    QLabel *label_historyTitle;
    QPlainTextEdit *gameHistoryTextEdit;
    QPushButton *backToMainMenuFromHistoryButton;
    QWidget *gamePage;
    QVBoxLayout *verticalLayout_7;
    QLabel *label_gameTitle;
    QLabel *label_opponentHand;
    QLabel *label_playerHand;
    QPushButton *selectCardButton;
    QPushButton *requestExchangeButton;
    QPushButton *stopResumeButton;
    QPlainTextEdit *gameLogTextEdit;
    QPushButton *exitGameButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(400, 650);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        loginPage = new QWidget();
        loginPage->setObjectName(QString::fromUtf8("loginPage"));
        verticalLayout_2 = new QVBoxLayout(loginPage);
        verticalLayout_2->setSpacing(15);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(20, 50, 20, 50);
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);

        label_loginTitle = new QLabel(loginPage);
        label_loginTitle->setObjectName(QString::fromUtf8("label_loginTitle"));
        QFont font;
        font.setPointSize(24);
        font.setBold(true);
        label_loginTitle->setFont(font);
        label_loginTitle->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label_loginTitle);

        usernameLineEdit = new QLineEdit(loginPage);
        usernameLineEdit->setObjectName(QString::fromUtf8("usernameLineEdit"));

        verticalLayout_2->addWidget(usernameLineEdit);

        passwordLineEdit = new QLineEdit(loginPage);
        passwordLineEdit->setObjectName(QString::fromUtf8("passwordLineEdit"));
        passwordLineEdit->setEchoMode(QLineEdit::Password);

        verticalLayout_2->addWidget(passwordLineEdit);

        loginButton = new QPushButton(loginPage);
        loginButton->setObjectName(QString::fromUtf8("loginButton"));

        verticalLayout_2->addWidget(loginButton);

        signUpButton = new QPushButton(loginPage);
        signUpButton->setObjectName(QString::fromUtf8("signUpButton"));

        verticalLayout_2->addWidget(signUpButton);

        forgotPasswordButton = new QPushButton(loginPage);
        forgotPasswordButton->setObjectName(QString::fromUtf8("forgotPasswordButton"));

        verticalLayout_2->addWidget(forgotPasswordButton);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_2);

        stackedWidget->addWidget(loginPage);
        signUpPage = new QWidget();
        signUpPage->setObjectName(QString::fromUtf8("signUpPage"));
        verticalLayout_3 = new QVBoxLayout(signUpPage);
        verticalLayout_3->setSpacing(10);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(20, 20, 20, 20);
        label_signUpTitle = new QLabel(signUpPage);
        label_signUpTitle->setObjectName(QString::fromUtf8("label_signUpTitle"));
        QFont font1;
        font1.setPointSize(20);
        font1.setBold(true);
        label_signUpTitle->setFont(font1);
        label_signUpTitle->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(label_signUpTitle);

        signUpNameLineEdit = new QLineEdit(signUpPage);
        signUpNameLineEdit->setObjectName(QString::fromUtf8("signUpNameLineEdit"));

        verticalLayout_3->addWidget(signUpNameLineEdit);

        signUpLastNameLineEdit = new QLineEdit(signUpPage);
        signUpLastNameLineEdit->setObjectName(QString::fromUtf8("signUpLastNameLineEdit"));

        verticalLayout_3->addWidget(signUpLastNameLineEdit);

        signUpPhoneNumberLineEdit = new QLineEdit(signUpPage);
        signUpPhoneNumberLineEdit->setObjectName(QString::fromUtf8("signUpPhoneNumberLineEdit"));

        verticalLayout_3->addWidget(signUpPhoneNumberLineEdit);

        signUpEmailLineEdit = new QLineEdit(signUpPage);
        signUpEmailLineEdit->setObjectName(QString::fromUtf8("signUpEmailLineEdit"));

        verticalLayout_3->addWidget(signUpEmailLineEdit);

        signUpUsernameLineEdit = new QLineEdit(signUpPage);
        signUpUsernameLineEdit->setObjectName(QString::fromUtf8("signUpUsernameLineEdit"));

        verticalLayout_3->addWidget(signUpUsernameLineEdit);

        signUpPasswordLineEdit = new QLineEdit(signUpPage);
        signUpPasswordLineEdit->setObjectName(QString::fromUtf8("signUpPasswordLineEdit"));
        signUpPasswordLineEdit->setEchoMode(QLineEdit::Password);

        verticalLayout_3->addWidget(signUpPasswordLineEdit);

        registerButton = new QPushButton(signUpPage);
        registerButton->setObjectName(QString::fromUtf8("registerButton"));

        verticalLayout_3->addWidget(registerButton);

        backToLoginButton = new QPushButton(signUpPage);
        backToLoginButton->setObjectName(QString::fromUtf8("backToLoginButton"));

        verticalLayout_3->addWidget(backToLoginButton);

        stackedWidget->addWidget(signUpPage);
        mainMenuPage = new QWidget();
        mainMenuPage->setObjectName(QString::fromUtf8("mainMenuPage"));
        verticalLayout_4 = new QVBoxLayout(mainMenuPage);
        verticalLayout_4->setSpacing(20);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(30, 50, 30, 50);
        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer_3);

        label_mainMenuTitle = new QLabel(mainMenuPage);
        label_mainMenuTitle->setObjectName(QString::fromUtf8("label_mainMenuTitle"));
        QFont font2;
        font2.setPointSize(26);
        font2.setBold(true);
        label_mainMenuTitle->setFont(font2);
        label_mainMenuTitle->setAlignment(Qt::AlignCenter);

        verticalLayout_4->addWidget(label_mainMenuTitle);

        label_welcomeUser = new QLabel(mainMenuPage);
        label_welcomeUser->setObjectName(QString::fromUtf8("label_welcomeUser"));
        QFont font3;
        font3.setPointSize(14);
        label_welcomeUser->setFont(font3);
        label_welcomeUser->setAlignment(Qt::AlignCenter);

        verticalLayout_4->addWidget(label_welcomeUser);

        startGameButton = new QPushButton(mainMenuPage);
        startGameButton->setObjectName(QString::fromUtf8("startGameButton"));
        startGameButton->setMinimumSize(QSize(0, 40));
        QFont font4;
        font4.setPointSize(12);
        font4.setBold(true);
        startGameButton->setFont(font4);

        verticalLayout_4->addWidget(startGameButton);

        editProfileButton = new QPushButton(mainMenuPage);
        editProfileButton->setObjectName(QString::fromUtf8("editProfileButton"));
        editProfileButton->setMinimumSize(QSize(0, 40));
        QFont font5;
        font5.setPointSize(12);
        editProfileButton->setFont(font5);

        verticalLayout_4->addWidget(editProfileButton);

        gameHistoryButton = new QPushButton(mainMenuPage);
        gameHistoryButton->setObjectName(QString::fromUtf8("gameHistoryButton"));
        gameHistoryButton->setMinimumSize(QSize(0, 40));
        gameHistoryButton->setFont(font5);

        verticalLayout_4->addWidget(gameHistoryButton);

        logoutButton = new QPushButton(mainMenuPage);
        logoutButton->setObjectName(QString::fromUtf8("logoutButton"));
        logoutButton->setMinimumSize(QSize(0, 40));
        logoutButton->setFont(font5);

        verticalLayout_4->addWidget(logoutButton);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer_4);

        stackedWidget->addWidget(mainMenuPage);
        editProfilePage = new QWidget();
        editProfilePage->setObjectName(QString::fromUtf8("editProfilePage"));
        verticalLayout_5 = new QVBoxLayout(editProfilePage);
        verticalLayout_5->setSpacing(10);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(20, 20, 20, 20);
        label_editProfileTitle = new QLabel(editProfilePage);
        label_editProfileTitle->setObjectName(QString::fromUtf8("label_editProfileTitle"));
        label_editProfileTitle->setFont(font1);
        label_editProfileTitle->setAlignment(Qt::AlignCenter);

        verticalLayout_5->addWidget(label_editProfileTitle);

        formLayout = new QFormLayout();
        formLayout->setSpacing(10);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        label_name = new QLabel(editProfilePage);
        label_name->setObjectName(QString::fromUtf8("label_name"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label_name);

        editNameLineEdit = new QLineEdit(editProfilePage);
        editNameLineEdit->setObjectName(QString::fromUtf8("editNameLineEdit"));

        formLayout->setWidget(0, QFormLayout::FieldRole, editNameLineEdit);

        label_lastName = new QLabel(editProfilePage);
        label_lastName->setObjectName(QString::fromUtf8("label_lastName"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_lastName);

        editLastNameLineEdit = new QLineEdit(editProfilePage);
        editLastNameLineEdit->setObjectName(QString::fromUtf8("editLastNameLineEdit"));

        formLayout->setWidget(1, QFormLayout::FieldRole, editLastNameLineEdit);

        label_phoneNumber = new QLabel(editProfilePage);
        label_phoneNumber->setObjectName(QString::fromUtf8("label_phoneNumber"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_phoneNumber);

        editPhoneNumberLineEdit = new QLineEdit(editProfilePage);
        editPhoneNumberLineEdit->setObjectName(QString::fromUtf8("editPhoneNumberLineEdit"));

        formLayout->setWidget(2, QFormLayout::FieldRole, editPhoneNumberLineEdit);

        label_email = new QLabel(editProfilePage);
        label_email->setObjectName(QString::fromUtf8("label_email"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_email);

        editEmailLineEdit = new QLineEdit(editProfilePage);
        editEmailLineEdit->setObjectName(QString::fromUtf8("editEmailLineEdit"));

        formLayout->setWidget(3, QFormLayout::FieldRole, editEmailLineEdit);

        label_username = new QLabel(editProfilePage);
        label_username->setObjectName(QString::fromUtf8("label_username"));

        formLayout->setWidget(4, QFormLayout::LabelRole, label_username);

        editUsernameLineEdit = new QLineEdit(editProfilePage);
        editUsernameLineEdit->setObjectName(QString::fromUtf8("editUsernameLineEdit"));

        formLayout->setWidget(4, QFormLayout::FieldRole, editUsernameLineEdit);

        label_password = new QLabel(editProfilePage);
        label_password->setObjectName(QString::fromUtf8("label_password"));

        formLayout->setWidget(5, QFormLayout::LabelRole, label_password);

        editPasswordLineEdit = new QLineEdit(editProfilePage);
        editPasswordLineEdit->setObjectName(QString::fromUtf8("editPasswordLineEdit"));
        editPasswordLineEdit->setEchoMode(QLineEdit::Password);

        formLayout->setWidget(5, QFormLayout::FieldRole, editPasswordLineEdit);

        label_confirmPassword = new QLabel(editProfilePage);
        label_confirmPassword->setObjectName(QString::fromUtf8("label_confirmPassword"));

        formLayout->setWidget(6, QFormLayout::LabelRole, label_confirmPassword);

        editConfirmPasswordLineEdit = new QLineEdit(editProfilePage);
        editConfirmPasswordLineEdit->setObjectName(QString::fromUtf8("editConfirmPasswordLineEdit"));
        editConfirmPasswordLineEdit->setEchoMode(QLineEdit::Password);

        formLayout->setWidget(6, QFormLayout::FieldRole, editConfirmPasswordLineEdit);


        verticalLayout_5->addLayout(formLayout);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_5->addItem(verticalSpacer_5);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        saveProfileButton = new QPushButton(editProfilePage);
        saveProfileButton->setObjectName(QString::fromUtf8("saveProfileButton"));

        horizontalLayout->addWidget(saveProfileButton);

        cancelProfileButton = new QPushButton(editProfilePage);
        cancelProfileButton->setObjectName(QString::fromUtf8("cancelProfileButton"));

        horizontalLayout->addWidget(cancelProfileButton);


        verticalLayout_5->addLayout(horizontalLayout);

        stackedWidget->addWidget(editProfilePage);
        gameHistoryPage = new QWidget();
        gameHistoryPage->setObjectName(QString::fromUtf8("gameHistoryPage"));
        verticalLayout_6 = new QVBoxLayout(gameHistoryPage);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        label_historyTitle = new QLabel(gameHistoryPage);
        label_historyTitle->setObjectName(QString::fromUtf8("label_historyTitle"));
        label_historyTitle->setFont(font1);
        label_historyTitle->setAlignment(Qt::AlignCenter);

        verticalLayout_6->addWidget(label_historyTitle);

        gameHistoryTextEdit = new QPlainTextEdit(gameHistoryPage);
        gameHistoryTextEdit->setObjectName(QString::fromUtf8("gameHistoryTextEdit"));
        gameHistoryTextEdit->setReadOnly(true);

        verticalLayout_6->addWidget(gameHistoryTextEdit);

        backToMainMenuFromHistoryButton = new QPushButton(gameHistoryPage);
        backToMainMenuFromHistoryButton->setObjectName(QString::fromUtf8("backToMainMenuFromHistoryButton"));

        verticalLayout_6->addWidget(backToMainMenuFromHistoryButton);

        stackedWidget->addWidget(gameHistoryPage);
        gamePage = new QWidget();
        gamePage->setObjectName(QString::fromUtf8("gamePage"));
        verticalLayout_7 = new QVBoxLayout(gamePage);
        verticalLayout_7->setSpacing(15);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        verticalLayout_7->setContentsMargins(20, 20, 20, 20);
        label_gameTitle = new QLabel(gamePage);
        label_gameTitle->setObjectName(QString::fromUtf8("label_gameTitle"));
        label_gameTitle->setFont(font);
        label_gameTitle->setAlignment(Qt::AlignCenter);

        verticalLayout_7->addWidget(label_gameTitle);

        label_opponentHand = new QLabel(gamePage);
        label_opponentHand->setObjectName(QString::fromUtf8("label_opponentHand"));

        verticalLayout_7->addWidget(label_opponentHand);

        label_playerHand = new QLabel(gamePage);
        label_playerHand->setObjectName(QString::fromUtf8("label_playerHand"));

        verticalLayout_7->addWidget(label_playerHand);

        selectCardButton = new QPushButton(gamePage);
        selectCardButton->setObjectName(QString::fromUtf8("selectCardButton"));

        verticalLayout_7->addWidget(selectCardButton);

        requestExchangeButton = new QPushButton(gamePage);
        requestExchangeButton->setObjectName(QString::fromUtf8("requestExchangeButton"));

        verticalLayout_7->addWidget(requestExchangeButton);

        stopResumeButton = new QPushButton(gamePage);
        stopResumeButton->setObjectName(QString::fromUtf8("stopResumeButton"));

        verticalLayout_7->addWidget(stopResumeButton);

        gameLogTextEdit = new QPlainTextEdit(gamePage);
        gameLogTextEdit->setObjectName(QString::fromUtf8("gameLogTextEdit"));
        gameLogTextEdit->setReadOnly(true);

        verticalLayout_7->addWidget(gameLogTextEdit);

        exitGameButton = new QPushButton(gamePage);
        exitGameButton->setObjectName(QString::fromUtf8("exitGameButton"));

        verticalLayout_7->addWidget(exitGameButton);

        stackedWidget->addWidget(gamePage);

        verticalLayout->addWidget(stackedWidget);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 400, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Poffer Game", nullptr));
        label_loginTitle->setText(QCoreApplication::translate("MainWindow", "Poffer Game Login", nullptr));
        usernameLineEdit->setPlaceholderText(QCoreApplication::translate("MainWindow", "Username", nullptr));
        passwordLineEdit->setPlaceholderText(QCoreApplication::translate("MainWindow", "Password", nullptr));
        loginButton->setText(QCoreApplication::translate("MainWindow", "Login", nullptr));
        signUpButton->setText(QCoreApplication::translate("MainWindow", "Sign Up", nullptr));
        forgotPasswordButton->setText(QCoreApplication::translate("MainWindow", "Forgot Password?", nullptr));
        label_signUpTitle->setText(QCoreApplication::translate("MainWindow", "Create New Account", nullptr));
        signUpNameLineEdit->setPlaceholderText(QCoreApplication::translate("MainWindow", "Name", nullptr));
        signUpLastNameLineEdit->setPlaceholderText(QCoreApplication::translate("MainWindow", "Last Name", nullptr));
        signUpPhoneNumberLineEdit->setPlaceholderText(QCoreApplication::translate("MainWindow", "Phone Number (e.g., 09xxxxxxxxx)", nullptr));
        signUpEmailLineEdit->setPlaceholderText(QCoreApplication::translate("MainWindow", "Email Address", nullptr));
        signUpUsernameLineEdit->setPlaceholderText(QCoreApplication::translate("MainWindow", "Username", nullptr));
        signUpPasswordLineEdit->setPlaceholderText(QCoreApplication::translate("MainWindow", "Password (min 8 characters)", nullptr));
        registerButton->setText(QCoreApplication::translate("MainWindow", "Register", nullptr));
        backToLoginButton->setText(QCoreApplication::translate("MainWindow", "Back to Login", nullptr));
        label_mainMenuTitle->setText(QCoreApplication::translate("MainWindow", "Poffer Game", nullptr));
        label_welcomeUser->setText(QCoreApplication::translate("MainWindow", "Welcome, Player!", nullptr));
        startGameButton->setText(QCoreApplication::translate("MainWindow", "Start Game", nullptr));
        editProfileButton->setText(QCoreApplication::translate("MainWindow", "Edit Profile", nullptr));
        gameHistoryButton->setText(QCoreApplication::translate("MainWindow", "Game History", nullptr));
        logoutButton->setText(QCoreApplication::translate("MainWindow", "Logout", nullptr));
        label_editProfileTitle->setText(QCoreApplication::translate("MainWindow", "Edit Profile", nullptr));
        label_name->setText(QCoreApplication::translate("MainWindow", "Name:", nullptr));
        label_lastName->setText(QCoreApplication::translate("MainWindow", "Last Name:", nullptr));
        label_phoneNumber->setText(QCoreApplication::translate("MainWindow", "Phone Number:", nullptr));
        editPhoneNumberLineEdit->setPlaceholderText(QCoreApplication::translate("MainWindow", "e.g., 09xxxxxxxxx", nullptr));
        label_email->setText(QCoreApplication::translate("MainWindow", "Email Address:", nullptr));
        label_username->setText(QCoreApplication::translate("MainWindow", "Username:", nullptr));
        label_password->setText(QCoreApplication::translate("MainWindow", "New Password:", nullptr));
        editPasswordLineEdit->setPlaceholderText(QCoreApplication::translate("MainWindow", "min 8 characters", nullptr));
        label_confirmPassword->setText(QCoreApplication::translate("MainWindow", "Confirm Password:", nullptr));
        saveProfileButton->setText(QCoreApplication::translate("MainWindow", "Save Changes", nullptr));
        cancelProfileButton->setText(QCoreApplication::translate("MainWindow", "Cancel", nullptr));
        label_historyTitle->setText(QCoreApplication::translate("MainWindow", "Game History", nullptr));
        gameHistoryTextEdit->setPlaceholderText(QCoreApplication::translate("MainWindow", "Your past game history will appear here (max 3 games).", nullptr));
        backToMainMenuFromHistoryButton->setText(QCoreApplication::translate("MainWindow", "Back to Main Menu", nullptr));
        label_gameTitle->setText(QCoreApplication::translate("MainWindow", "Poffer Game in Progress", nullptr));
        label_opponentHand->setText(QCoreApplication::translate("MainWindow", "Opponent's Hand: [Cards placeholder]", nullptr));
        label_playerHand->setText(QCoreApplication::translate("MainWindow", "Your Hand: [Cards placeholder]", nullptr));
        selectCardButton->setText(QCoreApplication::translate("MainWindow", "Select Card", nullptr));
        requestExchangeButton->setText(QCoreApplication::translate("MainWindow", "Request Card Exchange", nullptr));
        stopResumeButton->setText(QCoreApplication::translate("MainWindow", "Stop/Resume Game", nullptr));
        gameLogTextEdit->setPlaceholderText(QCoreApplication::translate("MainWindow", "Game log and chat messages will appear here...", nullptr));
        exitGameButton->setText(QCoreApplication::translate("MainWindow", "Exit Game", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
