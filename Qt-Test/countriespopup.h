#ifndef COUNTRIESPOPUP_H
#define COUNTRIESPOPUP_H

#include <QDialog>
#include <QDebug>
#include <QStandardItemModel>
#include <QLineEdit>
#include <QPainter>
#include <QPushButton>
#include <QTableView>

namespace Ui {
class CountriesPopup;
}

class CountriesPopup : public QDialog
{
    Q_OBJECT

public:
    explicit CountriesPopup(QWidget *parent = nullptr, QStandardItemModel *model = nullptr, QLineEdit *line_edit_phone_number = nullptr, QPushButton *pb_country_select = nullptr);
    void display(QWidget *parent = nullptr);
	void select_row(int i) const;
    ~CountriesPopup();
private slots:
    void on_tableViewCounries_clicked(const QModelIndex &index);

private:
    Ui::CountriesPopup *ui;
    QStandardItemModel *model;
    QPoint *offset;
    QLineEdit *lineEditPhoneNumber;
    QPushButton *pbCountrySelect;
};

#endif // COUNTRIESPOPUP_H
