#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QtCore>
#include <QtGui>
#include <QFileSystemModel>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();

private slots:
    void on_btnMakeDir_clicked();

    void on_btnDel_clicked();

private:
    Ui::Dialog *ui;
    QFileSystemModel *model;
};

#endif // DIALOG_H
