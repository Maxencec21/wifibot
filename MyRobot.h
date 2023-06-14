
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
    void batteryUpdate(int batteryLevel);
    void odoDUpdate(float odometrieD);
    void odoGUpdate(float odometrieG);
    void IR_AVGUpdate(unsigned char IR_AVG);
    void IR_AVDUpdate(unsigned char IR_AVD);
    void IR_ARGUpdate(unsigned char IR_ARG);
    void IR_ARDUpdate(unsigned char IR_ARD);


public slots:

    void connected();
    void disconnected();
    void readyRead();
    void MyTimerSlot();
    short Crc16(QByteArray Adresse_tab , unsigned char Taille_max);
    void crctosend();

    void avancer();
    void reculer();
    void allerDroite();
    void allerGauche();
    void stop();

    float Batterie();
    void bytesWritten(qint64 bytes);


private:

    QTcpSocket *socket;
    QTimer *TimerEnvoi;

};
#endif // MYROBOT_H
