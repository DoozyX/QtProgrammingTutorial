#include <QCoreApplication>
#include <QDir>
#include <QString>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QDir mDir;

    for (auto myDrive : mDir.drives())
    {
        qDebug() << myDrive.absoluteFilePath();
    }

    QString path = "D:/Doozy/hello";
    QDir mDir1(path);

    if (mDir1.exists()) {
        qDebug() << "Already exist";
    } else {
        mDir1.mkpath(path);
        qDebug() << "Created dir: " << mDir1.absoluteFilePath(path);
    }

    path = "D:/Doozy";
    QDir mDir2(path);

    for( auto file : mDir2.entryInfoList()) {
        if (file.isDir()) {
            qDebug() << "Dir:  "  << file.absoluteFilePath();
        } else {
            qDebug() << "File: " << file.absoluteFilePath();
        }

    }


    return a.exec();
}
