#include "myserver.h"

MyServer::MyServer(QObject *parent) :
    QTcpServer(parent)
{
}

void MyServer::startServer()
{
    if(this->listen(QHostAddress::Any, 8080)){
        qDebug() << "Server started";
    } else {
        qDebug() << "Clould not start server";

    }
}


void MyServer::incomingConnection(qintptr handle)
{
    qDebug() << handle << "Connected";
    MyClient *client = new MyClient(this);
    client->setSocket(handle);
    qDebug() << handle << "Disconnected";
}

