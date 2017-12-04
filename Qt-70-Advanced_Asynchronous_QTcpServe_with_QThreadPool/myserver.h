#ifndef MYSERVER_H
#define MYSERVER_H

#include <QObject>
#include <QTcpServer>
#include "myclient.h"

class MyServer : public QTcpServer
{
    Q_OBJECT
private:
    QThreadPool *threadPool;
protected:
    void incomingConnection(qintptr handle);
public:
    explicit MyServer(QObject *parent = 0);
    void startServer();
signals:
public slots:
};

#endif // MYSERVER_H
