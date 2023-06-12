#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)

{
    ui->setupUi(this);
    ui->gridLayout->addWidget(wifibot.cameraStream("192.168.1.106", "8080"));
    wifibot.doConnect();
    wifibot.MyTimerSlot();

    connect(&wifibot, SIGNAL(readyRead(const QByteArray)), this, SLOT(updateUi(const QByteArray)));
}


void MainWindow::updateUi(const QByteArray array)
{
    ui->progressBar->setValue(array[2]);
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_boutton_avancer_clicked()
{
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



void MainWindow::on_progressBar_valueChanged(int value)
{
    int batlvl = int(wifibot.Batterie());
    ui->progressBar->setValue(batlvl);
}

void MyRobot::keyPressed(QKeyEvent *event)
{
    // Récupérez la touche enfoncée
    int key = event->key();

    // Vérifiez quelle touche a été enfoncée et envoyez la commande correspondante
    switch (key) {
    case Qt::Key_Up:
        // Commande pour avancer
        avancer();
        qDebug() << "avancer";
        break;
    case Qt::Key_Down:
        // Commande pour reculer
        reculer();
        break;
    case Qt::Key_Left:
        // Commande pour tourner à gauche
        allerDroite();
        break;
    case Qt::Key_Right:
        // Commande pour tourner à droite
        allerGauche();
        break;
        // Ajoutez d'autres cases pour gérer d'autres touches du clavier selon vos besoins
    }
}

