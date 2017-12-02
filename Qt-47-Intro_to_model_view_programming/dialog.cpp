#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    model = new QStringListModel(this);

    QStringList list;

    list << "avocado" << "banana" << "coconut";

    model->setStringList(list);

    ui->listView->setModel(model);
    ui->comboBox->setModel(model);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_btnAdd_clicked()
{
    int count = model->rowCount();
    model->insertRow(count);

    QModelIndex index = model->index(count);

    ui->listView->setCurrentIndex(index);
    ui->listView->edit(index);
}

void Dialog::on_btnInsert_clicked()
{
    int count = ui->listView->currentIndex().row() + 1;
    model->insertRow(count);

    QModelIndex index = model->index(count);

    ui->listView->setCurrentIndex(index);
    ui->listView->edit(index);
}

void Dialog::on_btnDelete_clicked()
{
    int count = ui->listView->currentIndex().row();
    model->removeRow(count);

    QModelIndex index = model->index(count);

    ui->listView->setCurrentIndex(index);
}
