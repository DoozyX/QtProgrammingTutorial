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


QStandardItemModel* modelFromCSV() {
    QStandardItem* item;
    QStandardItemModel *model = new QStandardItemModel();
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
            foreach(const QString& cell, line.split(",")) {
                if (j == 0) {
                    const QString path = QString("qrc:/resources/countries/flags/%1.jpg").arg(cell.trimmed());
                    item = new QStandardItem();
                    item->setData(QIcon(path), Qt::DecorationRole);
                } else if (j == 1) {
                    item = new QStandardItem("+" + cell.trimmed());
                } else {
                    item = new QStandardItem(cell.trimmed());
                }
                standardItemList.append(item);
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
