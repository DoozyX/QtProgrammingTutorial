#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    model = new QStandardItemModel(4, 4, this);
    delegate = new Delegate(this);

    for(int i = 0; i < 4; ++i) {
        for(int j = 0; j < 4; ++j) {
            QModelIndex index = model->index(i,j);
            model->setData(index, 0);
        }
    }

    ui->tableView->setModel(model);
    ui->tableView->setItemDelegate(delegate);
}

Dialog::~Dialog()
{
    delete ui;
}
