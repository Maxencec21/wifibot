#include "MyRobot.h"

#include <QApplication>
#include<QKeyEvent>
#include "mainwindow.h"



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MyRobot wifiBot;
    MainWindow w;
    wifiBot.doConnect();
    //wifiBot.cameraStream("192.168.1.106", "8080");
    wifiBot.MyTimerSlot();
    w.show();
    //wifiBot.avancer();
    //wifiBot.disConnect();


    return a.exec();
}
