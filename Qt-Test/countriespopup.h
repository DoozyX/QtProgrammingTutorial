#ifndef COUNTRIESPOPUP_H
#define COUNTRIESPOPUP_H

#include <QDialog>

namespace Ui {
class CountriesPopup;
}

class CountriesPopup : public QDialog
{
    Q_OBJECT

public:
    explicit CountriesPopup(QWidget *parent = 0);
    ~CountriesPopup();

private:
    Ui::CountriesPopup *ui;
};

#endif // COUNTRIESPOPUP_H
