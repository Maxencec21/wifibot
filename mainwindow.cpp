#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "MyRobot.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    wifibot.doConnect();
    wifibot.MyTimerSlot();
    ui->gridLayout->addWidget(wifibot.cameraStream("192.168.1.106", "8080"));

}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_boutton_avancer_clicked()
{
    qDebug()<< "test";
    wifibot.avancer();
}


void MainWindow::on_boutton_droite_clicked()
{
    wifibot.allerDroite();
}


void MainWindow::on_boutton_reculer_clicked()
{
    wifibot.reculer();
}


void MainWindow::on_boutton_gauche_2_clicked()
{
    wifibot.allerGauche();
}


