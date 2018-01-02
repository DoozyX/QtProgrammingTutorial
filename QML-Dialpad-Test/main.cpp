#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QDebug>
#include <QStandardItemModel>
#include <QPainter>
#include <qqmlengine.h>
#include <qqmlcontext.h>
#include <qqml.h>
#include <QtQuick/qquickitem.h>
#include <QtQuick/qquickview.h>
#include "mymodel.h"


QStandardItemModel* modelFromCSV() {
    MyModel *model = new MyModel();
    QList<QStandardItem*> standardItemList;
    int j = 0;
    // file operations
    QFile file(":/resources/countries/countries.txt");
    if(file.open(QIODevice::ReadOnly)) {

        QTextStream stream(&file);
        // loop forever macro
        forever {
            QString line = stream.readLine();
            // test for null string 'String()'
            if(line.isNull()) {
                break;
            }
            // test for empty string 'QString("")'
            if(line.isEmpty()) {
                continue;
            }
            // for each loop to iterate over containers
            j = 0;
            QStandardItem *item;
            foreach(const QString& cell, line.split(",")) {                
                if (j == 0) {
                    item = new QStandardItem("Country");
                    const QString path = QString("qrc:/resources/countries/flags/%1.jpg").arg(cell.trimmed());
                    item->setData(path, Qt::UserRole + 1);
                } else if (j == 1) {
                    item->setData(QString("+" + cell.trimmed()), Qt::UserRole + 2);
                } else if (j == 2){
                    item->setData(cell.trimmed(), Qt::UserRole + 3);
                } else {
                    standardItemList << item;
                }

                ++j;
            }
            model->appendRow(standardItemList);
            standardItemList.clear();
        }
        //qDebug() << "nig" << model->item(1,2)->data(Qt::DisplayRole).toString();

    } else {
        qDebug() << "Can't open File";
    }
    return model;
}

int main(int argc, char *argv[])
{
#if defined(Q_OS_WIN)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif

    QGuiApplication app(argc, argv);

    QStandardItemModel *model = modelFromCSV();

    QQmlApplicationEngine engine;

    //TODO: Scoped pointer 149 tuto
    engine.rootContext()->setContextProperty("myModel", model);

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;


    return app.exec();
}
