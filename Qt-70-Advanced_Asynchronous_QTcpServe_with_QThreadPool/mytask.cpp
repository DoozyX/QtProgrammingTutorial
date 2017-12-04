#include "mytask.h"

MyTask::MyTask()
{

}

void MyTask::run()
{
    //qDebug() << "Task started";
    int number = 0;
    for(int i = 1; i <= 10000; ++i) {
        number += i;
    }

    //qDebug() << "Task Finished";

    emit finished(number);

}
