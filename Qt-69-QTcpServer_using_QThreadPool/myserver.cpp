#include "myserver.h"

MyServer::MyServer(QObject *parent) :
    QTcpServer(parent)
{
    threadPool = new QThreadPool(this);
    threadPool->setMaxThreadCount(5);
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
    MyRunnable *task = new MyRunnable(handle);
    task->setAutoDelete(true);
    threadPool->start(task);
    qDebug() << handle << "Disconnected";
}

