
#ifndef MYROBOT_H
#define MYROBOT_H

#include <QObject>
#include <QTcpSocket>
#include <QAbstractSocket>
#include <QDebug>
#include <QTimer>
#include <QMutex>
#include <QWebEngineView>
#include <QUrl>
#include <QKeyEvent>


class MyRobot : public QObject {

    Q_OBJECT

public:

    explicit MyRobot(QObject *parent = 0);
    void doConnect();
    void disConnect();
    QWebEngineView* cameraStream(QString ip, QString port);
    QByteArray DataToSend;
    QByteArray DataReceived;
    QMutex Mutex;

signals:

    void updateUI(const QByteArray Data);

public slots:

    void connected();
    void disconnected();
    void readyRead();
    void MyTimerSlot();
    //void bytesWritten();

    void avancer();
    void reculer();
    void allerDroite();
    void allerGauche();
    void stop();



private:

    QTcpSocket *socket;
    QTimer *TimerEnvoi;

};
#endif // MYROBOT_H
