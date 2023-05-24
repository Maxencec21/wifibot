#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->gridLayout->addWidget(wifibot.cameraStream("192.168.1.106", "8080"));
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

