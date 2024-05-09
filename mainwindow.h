#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE


enum StackPages{
    RSA_PAGE = 0,
    AES_PAGE
};



class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_RSA_Page_clicked();

    void on_AES_Page_clicked();

    void on_ChoosePathButton_clicked();

    void on_RsaKeyGen_clicked();




    void on_AESGenerateButton_clicked();

    void on_ClearButton_clicked();

    void on_AESClearButton_clicked();

private:
    QLabel* labelinfo;
    QLabel* aeslabelinfo;
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
