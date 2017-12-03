#include "sockettest.h"

SocketTest::SocketTest(QObject *parent) : QObject(parent)
{

}

void SocketTest::connect()
{
    socket = new QTcpSocket(this);

    socket->connectToHost("voidrealms.com", 80);

    if (socket->waitForConnected()) {
        qDebug() << "Connected";

        socket->write("Hello\r\n\r\n\r\n");
        socket->waitForBytesWritten();
        socket->waitForReadyRead();
        qDebug() << "Reading: " << socket->bytesAvailable();

        qDebug() << socket->readAll();
        socket->close();
    } else {
        qDebug() << "Not Connected";
    }

}
