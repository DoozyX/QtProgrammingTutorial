#include "myudp.h"

MyUDP::MyUDP(QObject *parent) : QObject(parent)
{
    socket = new QUdpSocket(this);
    socket->bind(QHostAddress::LocalHost, 8080);
    connect(socket, SIGNAL(readyRead()), this, SLOT(readyRead()));
}

void MyUDP::helloWorld()
{
    QByteArray data;
    data.append("Hello World!");
    socket->writeDatagram(data, QHostAddress::LocalHost, 8080);
}

void MyUDP::readyRead()
{
    QByteArray buffer;
    buffer.resize(socket->pendingDatagramSize());

    QHostAddress address;
    quint16 port;
    socket->readDatagram(buffer.data(),buffer.size(), &address, &port);

    qDebug() << "Message: " << buffer << " from: " << address.toString() << " : " << port;
}
