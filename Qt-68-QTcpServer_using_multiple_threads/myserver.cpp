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
    MyThread *thread = new MyThread(handle, this);
    connect(thread, SIGNAL(finished()), thread, SLOT(deleteLater()));
    thread->start();
}

