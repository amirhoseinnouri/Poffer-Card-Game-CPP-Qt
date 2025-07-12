#include <QCoreApplication>
#include <QDebug>
#include "server.h"
// شامل کلاس Server
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    qDebug()<<"Poffer Game Server is starting...";
    Server myServer; myServer.start(5555);
    return a.exec();
}
