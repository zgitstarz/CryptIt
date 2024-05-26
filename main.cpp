#include "mainwindow.h"

#include <cryptopp/cryptlib.h>
#include <cryptopp/base64.h>


#include <QApplication>
#include <QPalette>
#include <QLinearGradient>

#include "globalcustomstyle.h"


QPalette default_palette()
{
    QPalette palette;

    palette.setColor(QPalette::Window, QColor(0x54, 0x54, 0x54));

    palette.setColor(QPalette::Base, QColor(0x54, 0x54, 0x54));

    palette.setColor(QPalette::AlternateBase, QColor(0x54, 0x54, 0x54));

    return palette;
}





int main(int argc, char *argv[])
{

    CryptoPP::Base64Encoder enc;


    QApplication a(argc, argv);
    MainWindow w;
    w.show();


    a.setPalette(default_palette());
    a.setStyle(new GlobalCustomStyle);
    return a.exec();
}









