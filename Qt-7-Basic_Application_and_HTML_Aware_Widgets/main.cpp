#include <QApplication>
#include <QLabel>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    QLabel *label = new QLabel("<h1><b>Hello</b> <font color=red><i>world<i></font><h1>");
    label->show();

    return app.exec();
}
