#include <QApplication>
#include <QtWidgets>
#include <QtCore>

int main(int argc, char* argv[]) {
    QApplication app(argc, argv);

    QGridLayout  *layout = new QGridLayout();

    QWidget *window = new QWidget();
    window->setWindowTitle("Doozy");
    window->setLayout(layout);

    QLabel *label = new QLabel("Hello:");
    layout->addWidget(label, 0, 0);

    QLineEdit *name = new QLineEdit();
    layout->addWidget(name, 0, 1);

    QLabel *label1 = new QLabel("Hello:");
    layout->addWidget(label1, 1, 0);

    QLineEdit *name1 = new QLineEdit();
    layout->addWidget(name1, 1, 1);

    QPushButton *btn = new QPushButton("OK");
    layout->addWidget(btn, 2,0,1,2);

    window->show();
    return app.exec();
}
