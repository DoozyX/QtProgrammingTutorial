#ifndef MYCLIENT_H
#define MYCLIENT_H

#include <QObject>
#include <QThreadPool>
#include <QTcpSocket>
#include <mytask.h>

class MyClient : public QObject
{
    Q_OBJECT
private:
    QTcpSocket *socket;
public:
    MyClient(QObject *parent = 0);
    void setSocket(qintptr handle);
public slots:
    void connected();
    void disconneced();
    void readyRead();
    void taskFinished(int number);
};

#endif // MYCLIENT_H
