#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)

{
    ui->setupUi(this);
    ui->gridLayout->addWidget(wifibot.cameraStream("192.168.1.106", "8080"));
    connect(&wifibot, SIGNAL(batteryUpdate(int)), this, SLOT(on_progressBar_valueChanged(int)));
    connect(&wifibot, SIGNAL(odoDUpdate(float)), this, SLOT(on_lcdNumber_overflow(float)));
    connect(&wifibot, SIGNAL(odoGUpdate(float)), this, SLOT(on_lcdNumber_2_overflow(float)));
    connect(&wifibot, SIGNAL(IR_AVGUpdate(uchar)), this, SLOT(on_lcdNumber_3_overflow(uchar)));
    connect(&wifibot, SIGNAL(IR_AVDUpdate(uchar)), this, SLOT(on_lcdNumber_4_overflow(uchar)));
    connect(&wifibot, SIGNAL(IR_ARGUpdate(uchar)), this, SLOT(on_lcdNumber_5_overflow(uchar)));
    connect(&wifibot, SIGNAL(IR_ARDUpdate(uchar)), this, SLOT(on_lcdNumber_6_overflow(uchar)));




    //connect(&wifibot, SIGNAL(readyRead(const QByteArray)), this, SLOT(updateUi(const QByteArray)));
}



void MainWindow::updateUi(const QByteArray array)
{
    //On update l'ui en changeant la valeur de la progresse bar selon la batterie calculée
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
    //Si le bouton est relaché, le robot s'arrête
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
    //fonction pour récupérer la batterie
    if(niveauBatterie < 0){
        niveauBatterie += 255;
    }
    ui->progressBar->setValue(niveauBatterie);
}


void MainWindow::on_boutton_connection_clicked()
{
    //connexion propre au robot
    wifibot.doConnect();
    wifibot.MyTimerSlot();
}


void MainWindow::on_boutton_dconnection_clicked()
{
    //deco propre du robot
    wifibot.disConnect();
    wifibot.disconnected();
}


void MainWindow::on_lcdNumber_overflow(float odometrieD)
{
    ui->lcdNumber->display(odometrieD);
}




void MainWindow::on_lcdNumber_2_overflow(float odometrieG)
{
    ui->lcdNumber_2->display(odometrieG);
}


int MainWindow::on_speed_bar_valueChanged(int vitesse)
{
    return vitesse;
}



void MainWindow::on_lcdNumber_3_overflow(uchar IR_AVG)
{
    ui->lcdNumber->display(int(IR_AVG));
}


void MainWindow::on_lcdNumber_4_overflow(uchar IR_AVD)
{
    ui->lcdNumber->display(int(IR_AVD));

}


void MainWindow::on_lcdNumber_5_overflow(uchar IR_ARG)
{
    ui->lcdNumber->display(int(IR_ARG));
}


void MainWindow::on_lcdNumber_6_overflow(uchar IR_ARD)
{
    ui->lcdNumber->display(int(IR_ARD));
}

