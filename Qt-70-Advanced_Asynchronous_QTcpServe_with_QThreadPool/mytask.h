#ifndef MYTASK_H
#define MYTASK_H

#include <QObject>
#include <QRunnable>

class MyTask : public QObject, public QRunnable
{
    Q_OBJECT
public:
    MyTask();

    // QRunnable interface
public:
    void run();
signals:
    void finished(int number);
};

#endif // MYTASK_H
