#include "countriespopup.h"
#include "ui_countriespopup.h"

CountriesPopup::CountriesPopup(QWidget* parent, QStandardItemModel* model, QLineEdit* line_edit_phone_number,
								QPushButton* pb_country_select) :
	QDialog(parent),
	ui(new Ui::CountriesPopup) {
	ui->setupUi(this);
	offset = new QPoint(11, 71);
	ui->tableViewCounries->setSelectionBehavior(QAbstractItemView::SelectRows);
	this->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);

	this->model = model;
	ui->tableViewCounries->setModel(model);

	this->lineEditPhoneNumber = line_edit_phone_number;
	this->pbCountrySelect = pb_country_select;

	QHeaderView* header_view = ui->tableViewCounries->horizontalHeader();
	header_view->swapSections(2, 1);

	ui->tableViewCounries->setColumnHidden(3, true);
	ui->tableViewCounries->setColumnWidth(0, 30);
	ui->tableViewCounries->setColumnWidth(2, 280);
	ui->tableViewCounries->setColumnWidth(1, 50);
}

void CountriesPopup::display(QWidget* parent) {
	move(parent->frameGeometry().topLeft() + *offset);
	this->show();
}

void CountriesPopup::select_row(const int i) const {
	ui->tableViewCounries->selectRow(i);
}

void CountriesPopup::on_tableViewCounries_clicked(const QModelIndex& index) {
	lineEditPhoneNumber->setText(model->item(index.row(), 1)->text());
	pbCountrySelect->setIcon(model->item(index.row(), 0)->icon());
	this->close();
}


CountriesPopup::~CountriesPopup() {
	delete ui;
}
