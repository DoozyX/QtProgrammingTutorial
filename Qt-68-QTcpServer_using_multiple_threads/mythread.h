#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QObject>
#include <QThread>
#include <QTcpSocket>
#include <QDebug>

class MyThread : public QThread
{
    Q_OBJECT
private:
    qintptr id;
    QTcpSocket *socket;
protected:
    void run();
public:
    explicit MyThread(qintptr id, QObject *parent = 0);
signals:
   void error(QTcpSocket::SocketError socketError);
public slots:
    void disconnected();
    void readyRead();
};
#endif // MYTHREAD_H
