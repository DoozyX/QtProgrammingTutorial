#include "myrunnable.h"

MyRunnable::MyRunnable(qintptr id) : id(id)
{
}

void MyRunnable::run()
{
    qDebug() << id << "Runnable started";
    QTcpSocket socket;
    if(!socket.setSocketDescriptor(id)) {
        qDebug() << "Failed socket";
        return;
    }
    socket.write("Hello World");
    socket.flush();
    socket.waitForBytesWritten(5000);
    socket.close();
    qDebug() << id << "Runnable ended";
}
