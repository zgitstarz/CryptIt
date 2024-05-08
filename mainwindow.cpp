#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QFileDialog>
#include <QString>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setWindowTitle("CryptIt");


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_RSA_Page_clicked()
{
    ui->GeneralStack->setCurrentIndex(StackPages::RSA_PAGE);
}


void MainWindow::on_AES_Page_clicked()
{
    ui->GeneralStack->setCurrentIndex(StackPages::AES_PAGE);
}



void MainWindow::on_ChoosePathButton_clicked()
{
    QString path = QFileDialog().getExistingDirectory(this, "CryptIt");

    ui->PathLineEdit->setText(path);



}

