#include <QCoreApplication>
#include <QDebug>
#include <QLinkedList>
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QLinkedList<int> list;

    list << 1 << 2 << 3 << 4 << 5;

    QLinkedListIterator<int> iter(list);
    iter.toBack();

    iter.toBack();
    while (iter.hasPrevious()) {
        qDebug() << iter.previous();
    }

    return a.exec();
}
