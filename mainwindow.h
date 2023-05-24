#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "MyRobot.h"
#include <QQmlContext>
#include <QLabel>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QPixmap>
#include <QMainWindow>
#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <QOpenGLShaderProgram>
#include <QOpenGLTexture>
#include <QTimer>
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

    MyRobot wifibot;
private slots:

    void on_Bouton_avancer_clicked();

    void on_Bouton_reculer_clicked();

private:
    Ui::MainWindow *ui;
    MyRobot wifiBot;
};
#endif // MAINWINDOW_H
