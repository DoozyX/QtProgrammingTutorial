#include <QCoreApplication>
#include "signalsocket.h"
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    SignalSocket signalSocket;
    signalSocket.connectTo();

    return a.exec();
}
