#include "MyRobot.h"

#include <QApplication>
#include <QKeyEvent>

#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
<<<<<<< Updated upstream
    MainWindow w;


    //wifibot.doConnect();
    //wifiBot.cameraStream("192.168.1.106", "8080");
    //wifibot.MyTimerSlot();
    //wifiBot.avancer();
    //wifiBot.disConnect();

    w.show();
    return a.exec();
=======

    MyRobot robot;
    robot.doConnect(); // Connecter le robot

    // Instancier la fenêtre principale de l'application (si nécessaire)
    MainWindow mainWindow;
    mainWindow.show();

    // Démarrer la boucle d'événements de l'application
    int result = a.exec();

    robot.disConnect(); // Déconnecter le robot

    return result;
>>>>>>> Stashed changes
}
