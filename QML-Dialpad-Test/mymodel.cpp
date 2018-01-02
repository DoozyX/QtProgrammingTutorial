#include "mymodel.h"

QHash<int, QByteArray> MyModel::roleNames() const {
    QHash<int, QByteArray> roles;
    roles[flagURL] = "flagURL";
    roles[countryCode] = "countryCode";
    roles[countryName] = "countryName";

    return roles;
}

void MyModel::setModelProperty(int index, QString property, QVariant value) {
    qDebug() << "TestModel::setModelProperty index:" << index << " property:" << property
             << " value:" << value;
    if (property == "name")
        setData(QStandardItemModel::index(index, 0), value, Qt::UserRole+1);
}

QString MyModel::getFlagURLfromPhone(QString phone) {
    const auto n = this->rowCount();
    for (int i = 0; i < n; ++i) {
        auto country = this->item(i, 0)->data(Qt::UserRole+2).toString();
        const auto country_len = country.size();
        const QStringRef text_code(&phone, 0, country_len);
        if (country == text_code) {
            return this->item(i, 0)->data(Qt::UserRole+1).toString();
        }
    }
    return "qrc:/resources/countries/flags/1.jpg";
}

QString MyModel::getFlagURLfromIndex(QString index) {
    return this->item(index.toInt(), 0)->data(Qt::UserRole+1).toString();
}

QString MyModel::getPhoneFromIndex(QString index) {
    return this->item(index.toInt(), 0)->data(Qt::UserRole+2).toString();
}
