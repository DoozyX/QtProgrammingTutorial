#ifndef MYUDP_H
#define MYUDP_H

#include <QObject>
#include <QUdpSocket>

class MyUDP : public QObject
{
    Q_OBJECT
private:
    QUdpSocket *socket;
public:
    explicit MyUDP(QObject *parent = 0);
    void helloWorld();
signals:

public slots:
    void readyRead();
};

#endif // MYUDP_H
