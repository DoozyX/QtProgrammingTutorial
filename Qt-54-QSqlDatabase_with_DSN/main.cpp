#include <QCoreApplication>
#include <QtSql>
#include <QDebug>
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setHostName("DOOZY");
    db.setDatabaseName("mydsn32");


    if(db.open()) {
        qDebug() << "Connect - OK";

        qDebug() << "Connect - Closing...";
        db.close();
    } else {
        qDebug() << "Connect - ERROR = " << db.lastError();
    }

    return a.exec();
}
