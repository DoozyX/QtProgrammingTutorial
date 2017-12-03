#ifndef SIGNALSOCKET_H
#define SIGNALSOCKET_H

#include <QObject>
#include <QObject>
#include <QTcpSocket>
#include <QDebug>
#include <QAbstractSocket>

class SignalSocket : public QObject
{
    Q_OBJECT
private:
    QTcpSocket *socket;
public:
    explicit SignalSocket(QObject *parent = 0);
    void connectTo();
signals:

public slots:
    void connected();
    void disconnected();
    void bytesWritten(qint64 bytes);
    void readyRead();
};

#endif // SIGNALSOCKET_H
