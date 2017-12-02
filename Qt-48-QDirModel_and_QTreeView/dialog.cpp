#include "dialog.h"
#include "ui_dialog.h"
#include <QInputDialog>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    model = new QFileSystemModel(this);
    model->setRootPath(QDir::currentPath());
    model->setReadOnly(false);

    ui->treeView->setModel(model);

    QModelIndex index = model->index(0,0);
    ui->treeView->expand(index);
    ui->treeView->scrollTo(index);
    ui->treeView->setCurrentIndex(index);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_btnMakeDir_clicked()
{
    QModelIndex index = ui->treeView->currentIndex();
    if (!index.isValid()) {
        return;
    }

    QString name = QInputDialog::getText(this, "Enter Name", "Name:");

    if (name.isEmpty()) {
        return;
    }

    model->mkdir(index, name);
}

void Dialog::on_btnDel_clicked()
{
    QModelIndex index = ui->treeView->currentIndex();
    if (!index.isValid()) {
        return;
    }

    if (model->fileInfo(index).isDir()) {
        model->rmdir(index);
    } else {
        model->remove(index);
    }
}
