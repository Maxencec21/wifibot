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

void MainWindow::keyPressed(QKeyEvent *event)
{
    // Récupérez la touche enfoncée
    int key = event->key();

    // Vérifiez quelle touche a été enfoncée et envoyez la commande correspondante
    switch (key) {
    case Qt::Key_Up:
        // Commande pour avancer
        wifibot.avancer();
        break;
    case Qt::Key_Down:
        // Commande pour reculer
        wifibot.reculer();
        break;
    case Qt::Key_Left:
        // Commande pour tourner à gauche
        wifibot.allerGauche();
        break;
    case Qt::Key_Right:
        // Commande pour tourner à droite
        wifibot.allerDroite();
        break;
        // Ajoutez d'autres cases pour gérer d'autres touches du clavier selon vos besoins
    }
    wifibot.stop();
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


