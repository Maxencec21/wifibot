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
#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <QOpenGLShaderProgram>
#include <QOpenGLTexture>
#include <QTimer>

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


public slots:
    void updateUi(const QByteArray);

private slots:

    void on_boutton_avancer_clicked();

    void on_boutton_droite_clicked();

    void on_boutton_reculer_clicked();

    void on_boutton_gauche_2_clicked();

    void keyPressed(QKeyEvent *event);



    void on_progressBar_valueChanged(int value);

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
