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
        qDebug() << "OK";
        QSqlQuery query;

        if (query.exec("SELECT * FROM People")) {
            while (query.next()) {
                qDebug() << query.value(1).toString() << query.value(2).toString();
            }

        } else {
            qDebug() << "ERROR   = " << db.lastError();
        }

        qDebug() << "Closing...";
        db.close();
    } else {
        qDebug() << "ERROR = " << db.lastError();
    }

    return a.exec();
}
