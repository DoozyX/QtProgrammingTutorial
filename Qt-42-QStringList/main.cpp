#include <QCoreApplication>
#include <QDebug>
#include <QStringList>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QStringList list;

    QString line = "a,b,c";

    list = line.split(',');
    list.replaceInStrings("a", "avocado");
    list.replace(1, "banana");
    list.replace(2, "coconut");

    for (auto str : list) {
        qDebug() << str;
    }

    QString join = list.join(" n ");
    qDebug() << join;

    return a.exec();
}
