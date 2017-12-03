#ifndef MYRUNNABLE_H
#define MYRUNNABLE_H

#include <QRunnable>
#include <QTcpSocket>

class MyRunnable : public QRunnable
{
private:
    qintptr id;
public:
    MyRunnable(qintptr id);
public:
    void run();
};



#endif // MYRUNNABLE_H
