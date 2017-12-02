#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    dirModel = new QFileSystemModel(this);
    dirModel->setRootPath(QDir::currentPath());
    dirModel->setFilter(QDir::NoDotAndDotDot | QDir::Dirs);
    ui->treeView->setModel(dirModel);

    fileModel = new QFileSystemModel(this);
    fileModel->setRootPath(QDir::currentPath());
    fileModel->setFilter(QDir::NoDotAndDotDot | QDir::Files);
    ui->listView->setModel(fileModel);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_treeView_clicked(const QModelIndex &index)
{
    fileModel->setRootPath(fileModel->fileInfo(index).absoluteFilePath());
    ui->listView->setRootIndex(fileModel->index(fileModel->rootPath()));
}
