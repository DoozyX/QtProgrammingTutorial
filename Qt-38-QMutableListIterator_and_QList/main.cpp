#include <QCoreApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QList<int> list;

    for (int i = 0; i<10; ++i) {
        list.append(i);
    }

    QMutableListIterator<int> iter(list);
    iter.toBack();

    while (iter.hasPrevious()) {
        int i = iter.previous();

        if (i == 1) {
            iter.remove();
        }
    }
    iter.toBack();
    while (iter.hasPrevious()) {
        qDebug() << iter.previous();
    }

    return a.exec();
}
