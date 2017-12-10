#ifndef DIALOG_H
#define DIALOG_H

#include <QFileDialog>
#include "countriespopup.h"
#include <QStringRef>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

private:
	int j = 0;
	Ui::Dialog *ui;
	QStandardItemModel *model;
	CountriesPopup *countriesPopup;
	QList<QStandardItem*> standardItemList;
	QTableView *tableViewCounries;
	void read_model();
public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();

private slots:
    void check_string(QString &temp, QChar character = 0);
    void on_pbArrow_clicked();
    void on_pbFlag_clicked();
	
    void on_lineEditPhoneNumber_editingFinished() const;

    void on_textEditMessage_textChanged() const;

};

#endif // DIALOG_H
