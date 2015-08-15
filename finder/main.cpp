#include <QApplication>
#include <QLabel>
#include <QPushButton>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QPushButton *pushButton = new QPushButton("Quit To Exit");
    QObject::connect(pushButton,SIGNAL(clicked()),&a, SLOT(quit()));
    pushButton->show();
    return a.exec();
}
