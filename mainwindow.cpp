#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}




void MainWindow::on_Bouton_avancer_clicked()
{
    wifibot.avancer();
}


void MainWindow::on_Bouton_reculer_clicked()
{
    wifibot.reculer();
}

