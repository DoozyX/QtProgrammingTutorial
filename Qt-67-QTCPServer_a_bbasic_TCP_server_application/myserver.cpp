#include "myserver.h"

MyServer::MyServer(QObject *parent) : QObject(parent)
{
    server = new QTcpServer(this);

    connect(server, SIGNAL(newConnection()),this,SLOT(newConnection()));

    if (server->listen(QHostAddress::Any, 8080)) {
        qDebug() << "Server started";
    } else {
        qDebug() << "Failed to start server";
    }
}

void MyServer::newConnection()
{
    qDebug() << "New Connection";
    QTcpSocket *socket = server->nextPendingConnection();

    socket->write("Hello");
    socket->flush();
    socket->waitForBytesWritten();

    socket->close();
}
