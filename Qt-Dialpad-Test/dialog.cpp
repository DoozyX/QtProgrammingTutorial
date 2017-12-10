#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget* parent) :
	QDialog(parent),
	ui(new Ui::Dialog) {
	ui->setupUi(this);

	model = new QStandardItemModel(this);

	read_model();

	countriesPopup = new CountriesPopup(this, model, ui->lineEditPhoneNumber, ui->pbFlag);
	ui->lineEditPhoneNumber->setFrame(false);
}

void Dialog::read_model() {
	QFile file(":/countries/resources/countries/countries.txt");
	if (file.open(QIODevice::ReadOnly)) {
		QString data = file.readAll();
		data.remove(QRegExp("\r")); //remove all ocurrences of CR (Carriage Return)
		QString temp;
		QChar character;
		QTextStream textStream(&data);
		while (!textStream.atEnd()) {
			textStream >> character;
			if (character == ',') {
				check_string(temp, character);
			} else if (character == '\n') {
				check_string(temp, character);
			} else if (textStream.atEnd()) {
				temp.append(character);
				check_string(temp);
			} else {
				temp.append(character);
			}
		}
	}
}

void Dialog::check_string(QString& temp, const QChar character) {
	QStandardItem* item;
	if (j == 0) {
		QString str = temp.simplified();
		str.replace(" ", "");
		const QString path = QString(":/countries/flags/resources/countries/flags/%1.jpg").arg(str);
		item = new QStandardItem();
		item->setData(QIcon(path), Qt::DecorationRole);
	} else if (j == 1) {
		auto str = temp.simplified();
		str.replace(" ", "");
		item = new QStandardItem("+" + str);
	} else {
		item = new QStandardItem(temp);
	}

	++j;
	standardItemList.append(item);


	if (character != QChar(',')) {
		model->appendRow(standardItemList);
		j = 0;
		standardItemList.clear();
	}

	temp.clear();
}

void Dialog::on_pbArrow_clicked() {
	countriesPopup->display(this);
}

void Dialog::on_pbFlag_clicked() {
	countriesPopup->display(this);
}

void Dialog::on_lineEditPhoneNumber_editingFinished() const {
	auto text = ui->lineEditPhoneNumber->text();
	const auto n = model->rowCount();
	for (int i = 0; i < n; ++i) {
		auto country = model->item(i, 1)->text();
		const auto country_len = country.size();
		const QStringRef text_code(&text, 0, country_len);
		if (country == text_code) {
			countriesPopup->select_row(i);
			ui->pbFlag->setIcon(model->item(i, 0)->icon());
			break;
		}
	}
}

void Dialog::on_textEditMessage_textChanged() const {
	const int n = ui->textEditMessage->toPlainText().length();
	ui->lblNumberOfMessages->setText(QString::number(n / 160 + 1));
	ui->lblMessageCharCount->setText(QString::number(160 - (n % 160)));
}

Dialog::~Dialog() {
	delete ui;
}