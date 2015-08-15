#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QTextStream>
//#include <QtCore/QFile>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    getTextFile();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_findButton_clicked()
{
    QString selectedWord = ui->lineEdit->text();
    ui->textEdit->find(selectedWord,QTextDocument::FindWholeWords);
}

void MainWindow::getTextFile(){
    QFile myFile(":/VijaySample.txt");
    myFile.open(QIODevice::ReadOnly);
    QTextStream textStream(&myFile);
    QString storeString = textStream.readAll();
    myFile.close();
    ui->textEdit->setPlainText(storeString);
    QTextCursor textCursor = ui->textEdit->textCursor();
    textCursor.movePosition(QTextCursor::Start,QTextCursor::MoveAnchor,1);
}
