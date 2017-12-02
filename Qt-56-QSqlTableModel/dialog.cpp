#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    db = QSqlDatabase::addDatabase("QODBC");
    db.setHostName("DOOZY");
    db.setDatabaseName("mydsn32");

    if(db.open()) {
        qDebug() << "OK";

        model = new QSqlTableModel(this);
        model->setTable("People");
        model->select();

        if (model->lastError().isValid()) {
              qDebug() << model->lastError();
        }
        ui->tableView->setModel(model);
    } else {
        qDebug() << "ERROR = " << db.lastError();
    }
}

Dialog::~Dialog()
{
    qDebug() << "Closing...";
    db.close();
    delete ui;
}
