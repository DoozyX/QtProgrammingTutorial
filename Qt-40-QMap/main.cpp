#include <QCoreApplication>
#include <QMap>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QMap<QString, QString> map;

    map.insert("Doozy", "Hello");
    map.insert("Hello", "World");

    QMapIterator<QString, QString> mInt(map);

    while (mInt.hasNext()) {
        mInt.next();
        qDebug() << mInt.key() << " - " << mInt.value();
    }

    for(QString string : map.keys()) {
        //qDebug() << map[string];
        qDebug() << map.value(string);
    }

    return a.exec();
}
