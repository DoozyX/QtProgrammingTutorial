#include "mythread.h"

MyThread::MyThread(qintptr id, QObject *parent) :
    QThread(parent), id(id)
{
}

void MyThread::run()
{
    qDebug() << id << " Started";
    socket = new QTcpSocket();

    if(!socket->setSocketDescriptor(id)) {
        emit error(socket->error());
        return;
    }

    connect(socket,SIGNAL(readyRead()),this,SLOT(readyRead()),Qt::DirectConnection);
    connect(socket,SIGNAL(disconnected()),this,SLOT(disconnected()),Qt::DirectConnection);
    exec();
}

void MyThread::readyRead()
{
    QByteArray data = socket->readAll();
    qDebug() << id << "Data: " << data;
    socket->write(data);
}

void MyThread::disconnected()
{
    qDebug() << id << " Disconected";
    socket->deleteLater();
    exit(0);
}
