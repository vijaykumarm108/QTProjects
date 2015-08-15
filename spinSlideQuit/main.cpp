#include <QApplication>
#include <QHBoxLayout>
#include <QPushButton>
#include <QSlider>
#include <QSpinBox>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QWidget *thisIsMain= new QWidget();
    thisIsMain->setWindowTitle("Select number of Pints");

   QPushButton *button = new QPushButton("Order and Quit");
   QObject::connect(button,SIGNAL(clicked()),&a, SLOT(quit()));

   QSlider *slider = new QSlider(Qt::Horizontal);
   QSpinBox *spinner =new QSpinBox;
   spinner->setRange(1,25);
   slider->setRange(1,25);

   QObject::connect(slider,SIGNAL(valueChanged(int)),spinner,SLOT(setValue(int)));
   QObject::connect(spinner,SIGNAL(valueChanged(int)),slider,SLOT(setValue(int)));
    slider->setValue(4);
   QHBoxLayout *boxLayout = new QHBoxLayout;
   boxLayout->addWidget(slider);
   boxLayout->addWidget(spinner);
   boxLayout->addWidget(button);

   thisIsMain->setLayout(boxLayout);
   thisIsMain->show();

    return a.exec();
}
