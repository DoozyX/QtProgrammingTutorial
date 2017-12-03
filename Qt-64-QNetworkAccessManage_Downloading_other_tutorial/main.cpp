#include <QCoreApplication>
#include <QDebug>
#include "downloader.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    qDebug() << "Hello World";

    Downloader downloader;
    downloader.doDownload();
    return a.exec();
}
