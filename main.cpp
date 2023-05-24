#include "MyRobot.h"

#include <QApplication>
#include<QKeyEvent>
#include "mainwindow.h"



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;


    //wifibot.doConnect();
    //wifiBot.cameraStream("192.168.1.106", "8080");
    //wifibot.MyTimerSlot();
    //wifiBot.avancer();
    //wifiBot.disConnect();

    w.show();


    return a.exec();
}
