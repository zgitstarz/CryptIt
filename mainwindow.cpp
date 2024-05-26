#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QFileDialog>
#include <QString>
#include <QMessageBox>


#include "FileAPI.h"



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

void MainWindow::on_AESChoosePathButton_2_clicked()
{
    QString path = QFileDialog().getExistingDirectory(this, "CryptIt");

    ui->AESPathLineEdit->setText(path);
}

void MainWindow::on_RsaKeyGen_clicked()
{
    ui->PublicKeyText->clear();
    ui->PrivateKeyText->clear();
    get_rsa_keys(&key, ui->KeySizeCombo->currentText().toInt());

    ui->PublicKeyText->setText(key.pub.data());

    ui->PrivateKeyText->setText(key.priv.data());

}


void MainWindow::on_AESGenerateButton_clicked()
{

    aes_key.clear();

    get_aes_key(aes_key, ui->KeySizeComboAES->currentText().toInt(), ui->EncodingCombo->currentIndex());

    ui->AESTextEdit->clear();
    ui->AESTextEdit->setText(aes_key.data());

}


void MainWindow::on_ClearButton_clicked()
{
    ui->PathLineEdit->clear();
    ui->FileNameLineEdit->clear();
    ui->RSAInfoLabel->hide();
    ui->PublicKeyText->clear();
    ui->PrivateKeyText->clear();
}


void MainWindow::on_AESClearButton_clicked()
{
    ui->AESPathLineEdit->clear();
    ui->FileNameLineEditAES->clear();
    ui->AESInfoLabel->hide();
    ui->AESTextEdit->clear();
}

#include <fstream>


void MainWindow::saveFile(int alg)
{
    if(alg == CRSA)
    {
        QString pubfile = ui->PathLineEdit->displayText().append("/").append(ui->FileNameLineEdit->displayText().append(".pub"));


        QString privfile = ui->PathLineEdit->displayText().append("/").append(ui->FileNameLineEdit->displayText().append(".priv"));


        // Public
        QFile file(pubfile);

        file.open(QFile::WriteOnly);

        file.write(key.pub.data());

        file.close();

        // Private

        file.setFileName(privfile);

        file.open(QFile::WriteOnly);

        file.write(key.priv.data());

        file.close();
    }
    else
    {
        QString pubfile = ui->AESPathLineEdit->displayText().append("/").append(ui->FileNameLineEditAES->displayText().append(".pub"));

        QFile file(pubfile);
        file.open(QFile::WriteOnly);

        file.write(aes_key.data());
        file.close();

    }

}





void MainWindow::on_RSA_SaveKey_Button_clicked()
{
    if(ui->PathLineEdit->text() == nullptr || ui->FileNameLineEdit->text() == nullptr)
    {
        labelinfo->show();

    }
    else{
        labelinfo->hide();

        saveFile(CRSA);

    }
}

void MainWindow::on_AESSaveKeyButton_clicked()
{
    if(ui->AESPathLineEdit->text() == nullptr || ui->FileNameLineEditAES->text() == nullptr)
    {
        aeslabelinfo->show();

    }
    else
    {
        aeslabelinfo->hide();
        saveFile(CAES);

    }

}

