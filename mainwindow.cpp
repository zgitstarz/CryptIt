#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QFileDialog>
#include <QString>
#include <QMessageBox>



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setWindowTitle("CryptIt");

    // set warning messages
    labelinfo = ui->RSAInfoLabel;
    aeslabelinfo = ui->AESInfoLabel;
    labelinfo->hide();
    aeslabelinfo->hide();


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


void MainWindow::on_RsaKeyGen_clicked()
{
    if(ui->PathLineEdit->text() == nullptr || ui->FileNameLineEdit->text() == nullptr ||
        ui->PassPhraseLine->text() == nullptr || ui->NameLineEdit->text() == nullptr ||
        ui->EmailLineEdit->text() == nullptr )
    {
        labelinfo->show();

    }        
    else{
        labelinfo->hide();
    }
}


void MainWindow::on_AESGenerateButton_clicked()
{
    if(ui->AESPathLineEdit->text() == nullptr || ui->FileNameLineEditAES->text() == nullptr)
    {
        aeslabelinfo->show();

    }
    else{
        aeslabelinfo->hide();
    }
}


void MainWindow::on_ClearButton_clicked()
{
    ui->PathLineEdit->clear();
    ui->FileNameLineEdit->clear();
    ui->PassPhraseLine->clear();
    ui->NameLineEdit->clear();
    ui->EmailLineEdit->clear();
}


void MainWindow::on_AESClearButton_clicked()
{
    ui->AESPathLineEdit->clear();
    ui->FileNameLineEditAES->clear();
}

