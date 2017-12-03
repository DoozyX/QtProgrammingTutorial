#include "signalsocket.h"

SignalSocket::SignalSocket(QObject *parent) : QObject(parent)
{

}

void SignalSocket::connectTo()
{
    socket = new QTcpSocket(this);

    connect(socket, SIGNAL(connected()), this, SLOT(connected()));
    connect(socket, SIGNAL(disconnected()), this, SLOT(disconnected()));
    connect(socket, SIGNAL(bytesWritten(qint64)),this, SLOT(bytesWritten(qint64)));
    connect(socket, SIGNAL(readyRead()), this, SLOT(readyRead()));
    qDebug() << "Connecting...";
    socket->connectToHost("google.com", 80);

    if (!socket->waitForConnected()) {
        qDebug() << "Couldn't connect: " << socket->errorString();
    }

}

void SignalSocket::connected()
{
    qDebug() << "Connected";
    socket->write("HEAD / HTTP/1.0\r\n\r\n\r\n");

}

void SignalSocket::disconnected()
{
    qDebug() << "Disconected";
}

void SignalSocket::bytesWritten(qint64 bytes)
{
    qDebug() << "Bytes Writen: " << bytes;
}

void SignalSocket::readyRead()
{
    qDebug() << "Reading: " << socket->readAll();
}
