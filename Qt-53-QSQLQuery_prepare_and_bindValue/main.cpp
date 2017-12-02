#include <QCoreApplication>
#include <QtSql>
#include <QDebug>
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");

    db.setConnectOptions();
    db.setDatabaseName("DRIVER={SQL SERVER};SERVER=DOOZY;DATABASE=QtTutorial;Trusted_Connection=Yes");

    if(db.open()) {
        qDebug() << "Connect - OK";

        QString command = "INSERT INTO People (Name, Surname) VALUES (:name, :surname)";
        QSqlQuery query;

        query.prepare(command);
        query.bindValue(":name", "Doozy4");
        query.bindValue(":surname", "Dzx4");

        if (query.exec()) {
            qDebug() << "Query - OK";
        } else {
            qDebug() << "Query - ERROR   = " << db.lastError();
        }

        qDebug() << "Connect - Closing...";
        db.close();
    } else {
        qDebug() << "Connect - ERROR = " << db.lastError();
    }

    return a.exec();
}
