#include "countriespopup.h"
#include "ui_countriespopup.h"

CountriesPopup::CountriesPopup(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CountriesPopup)
{
    ui->setupUi(this);
}

CountriesPopup::~CountriesPopup()
{
    delete ui;
}
