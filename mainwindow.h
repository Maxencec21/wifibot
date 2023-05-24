#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "MyRobot.h"

#include <QMainWindow>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_Bouton_avancer_clicked();

    void on_Bouton_reculer_clicked();

private:
    Ui::MainWindow *ui;
    MyRobot wifibot;
};
#endif // MAINWINDOW_H
