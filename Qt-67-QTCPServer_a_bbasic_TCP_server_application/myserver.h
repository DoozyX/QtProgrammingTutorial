#ifndef MYSERVER_H
#define MYSERVER_H

#include <QObject>
#include <QDebug>
#include <QTcpServer>
#include <QTcpSocket>

class MyServer : public QObject
{
    Q_OBJECT
private:
   QTcpServer *server;
public:
    explicit MyServer(QObject *parent = 0);
signals:

public slots:
   void newConnection();
};

#endif // MYSERVER_H
