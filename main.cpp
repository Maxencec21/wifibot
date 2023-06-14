#include "MyRobot.h"

#include <QApplication>
#include <QKeyEvent>

#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w; // Création d'une mainwindow


    w.show(); // affichage de la mainwindow créée
    return a.exec();
}
