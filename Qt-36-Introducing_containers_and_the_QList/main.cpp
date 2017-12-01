#include <QCoreApplication>
#include <QDebug>
#include <QList>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QList<QString> list;

    for (int i = 0; i < 10; ++i) {
        list.append("D" + QString::number(i));
    }

    list.removeOne("D6");
    list.removeAt(1);

    for (QString i : list) {
        qDebug() << i << endl;
    }

    return a.exec();
}
