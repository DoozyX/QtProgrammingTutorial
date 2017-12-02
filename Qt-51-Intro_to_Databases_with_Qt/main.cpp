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
        db.close();
    } else {
        qDebug() << "ERROR = " << db.lastError();
    }

    return a.exec();
}
