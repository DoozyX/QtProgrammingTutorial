#include "myclient.h"

MyClient::MyClient(QObject *parent) : QObject(parent)
{
    QThreadPool::globalInstance()->setMaxThreadCount(10);

}

void MyClient::setSocket(qintptr handle)
{
    socket = new QTcpSocket(this);
    qDebug() << "Client socket connected";
    connect(socket, SIGNAL(connected()), this, SLOT(connected()));
    connect(socket, SIGNAL(disconnected()), this, SLOT(disconneced()));
    connect(socket, SIGNAL(readyRead()), this, SLOT(readyRead()));
    socket->setSocketDescriptor(handle);
}

void MyClient::connected()
{
    qDebug() << "Client socket connected";
}

void MyClient::disconneced()
{
    qDebug() << "Client socket disconnected";
}

void MyClient::readyRead()
{
    qDebug() << "Client socket read: " << socket->readAll();

    MyTask *myTask = new MyTask();
    connect(myTask, SIGNAL(finished(int)), this, SLOT(taskFinished(int)),Qt::QueuedConnection);
    myTask->setAutoDelete(true);

    QThreadPool::globalInstance()->start(myTask);
}

void MyClient::taskFinished(int number)
{
    QByteArray data;
    data.append("\r\nTask Result: ").append(QString::number(number));
    socket->write(data);
}
