#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QtCore>
#include <QtGui>

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
    void on_btnAdd_clicked();

    void on_btnInsert_clicked();

    void on_btnDelete_clicked();

private:
    Ui::Dialog *ui;
    QStringListModel *model;
};

#endif // DIALOG_H
