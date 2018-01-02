#ifndef MYMODEL_H
#define MYMODEL_H

#include <QObject>
#include <QStandardItemModel>
#include <QDebug>

class MyModel : public QStandardItemModel
{
    Q_OBJECT
public:
    enum Role {
        flagURL= Qt::UserRole + 1,
        countryCode,
        countryName
    };
    explicit MyModel(QObject * parent = 0): QStandardItemModel(parent) {}
    explicit MyModel( int rows, int columns, QObject * parent = 0 ): QStandardItemModel(rows, columns, parent) {}

    QHash<int, QByteArray> roleNames() const;

    Q_INVOKABLE void setModelProperty(int index, QString property, QVariant value);

    Q_INVOKABLE QString getFlagURLfromPhone(QString phone);

    Q_INVOKABLE QString getFlagURLfromIndex(QString index);

    Q_INVOKABLE QString getPhoneFromIndex(QString index);


};

#endif // MYMODEL_H
