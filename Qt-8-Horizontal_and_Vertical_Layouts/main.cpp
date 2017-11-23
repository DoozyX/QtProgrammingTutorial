#include <QApplication>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>

int main(int argc, char*argv[]) {
    QApplication app(argc, argv);

    QWidget *window = new QWidget();
    window->setWindowTitle("Doozy");

    QPushButton *btn1 = new QPushButton("Doozy1");
    QPushButton *btn2 = new QPushButton("Doozy2");
    QPushButton *btn3 = new QPushButton("Doozy3");

    //QVBoxLayout *vLayout = new QVBoxLayout();
    QHBoxLayout *hLayout = new QHBoxLayout();

    hLayout->addWidget(btn1);
    hLayout->addWidget(btn2);
    hLayout->addWidget(btn3);

    //    vLayout->addWidget(btn1);
    //    vLayout->addWidget(btn2);
    //    vLayout->addWidget(btn3);

    //window->setLayout(vLayout);
    window->setLayout(hLayout);

    window->show();
    return app.exec();
}
