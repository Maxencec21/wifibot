#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)

{
    ui->setupUi(this);
    ui->gridLayout->addWidget(wifibot.cameraStream("192.168.1.106", "8080"));
    connect(&wifibot, SIGNAL(batteryUpdate(int)), this, SLOT(on_progressBar_valueChanged(int)));
    wifibot.doConnect();
    wifibot.MyTimerSlot();

    //connect(&wifibot, SIGNAL(readyRead(const QByteArray)), this, SLOT(updateUi(const QByteArray)));
}



void MainWindow::updateUi(const QByteArray array)
{
    ui->progressBar->setValue(array[2]);
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_boutton_avancer_pressed()
{
    wifibot.avancer();
}


void MainWindow::on_boutton_droite_pressed()
{
    wifibot.allerDroite();
}


void MainWindow::on_boutton_reculer_pressed()
{
    wifibot.reculer();
}


void MainWindow::on_boutton_gauche_2_pressed()
{
    wifibot.allerGauche();
}



void MainWindow::keyPressEvent(QKeyEvent *event)
{

    // Vérifiez quelle touche a été enfoncée et envoyez la commande correspondante
    if(event->key() == Qt::Key_Z) {
        // Commande pour avancer
        wifibot.avancer();
        qDebug() << "avancer";
    }
    else if (event->key() == Qt::Key_S)
        wifibot.reculer();

    else if (event->key() == Qt::Key_Q)
        wifibot.allerGauche();

    else if (event->key() == Qt::Key_D)
        wifibot.allerDroite();

    else
        wifibot.stop();

}


void MainWindow::on_boutton_avancer_released()
{
    wifibot.stop();
}


void MainWindow::on_boutton_droite_released()
{
    wifibot.stop();
}


void MainWindow::on_boutton_reculer_released()
{
    wifibot.stop();
}


void MainWindow::on_boutton_gauche_2_released()
{
    wifibot.stop();
}

void MainWindow::on_progressBar_valueChanged(int niveauBatterie){
    if(niveauBatterie < 0){
        niveauBatterie += 255;
    }
    qDebug() << "Niveau de batterie : " << niveauBatterie;
    ui->progressBar->setValue(niveauBatterie);
}

