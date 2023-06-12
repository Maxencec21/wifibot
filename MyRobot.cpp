#include "myrobot.h"

MyRobot::MyRobot(QObject *parent) : QObject(parent) {
    DataToSend.resize(9);
    DataToSend[0] = 0xFF;
    DataToSend[1] = 0x07;
    DataToSend[2] = 0x00;//120 sur la gauche
    DataToSend[3] = 0x00;
    DataToSend[4] = 0x00;//120 sur la droite
    DataToSend[5] = 0x00;
    DataToSend[6] = 0;
    DataToSend[7] = 0x0;
    DataToSend[8] = 0x0;
    DataReceived.resize(21);
    TimerEnvoi = new QTimer();
    // setup signal and slot
    connect(TimerEnvoi, SIGNAL(timeout()), this, SLOT(MyTimerSlot())); //Send data to wifibot timer
}


void MyRobot::doConnect() {
    socket = new QTcpSocket(this); // socket creation
    connect(socket, SIGNAL(connected()),this, SLOT(connected()));
    connect(socket, SIGNAL(disconnected()),this, SLOT(disconnected()));

    connect(socket, SIGNAL(bytesWritten(qint64)),this, SLOT(bytesWritten(qint64)));
    connect(socket, SIGNAL(readyRead()),this, SLOT(readyRead()));
    qDebug() << "connecting..."; // this is not blocking call
    //socket->connectToHost("LOCALHOST", 15020);
    socket->connectToHost("192.168.1.106", 15020); // connection to wifibot
    // we need to wait...
    if(!socket->waitForConnected(5000)) {
        qDebug() << "Error: " << socket->errorString();
        return;
    }
    TimerEnvoi->start(75);

}

void MyRobot::disConnect() {
    TimerEnvoi->stop();
    socket->close();
}

void MyRobot::connected() {
    qDebug() << "connected..."; // Hey server, tell me about you.
}

void MyRobot::disconnected() {
    qDebug() << "disconnected...";
}


void MyRobot::readyRead() {
    qDebug() << "reading..."; // read the data from the socket
    DataReceived = socket->readAll();
    emit updateUI(DataReceived);
    qDebug() << DataReceived[0] << DataReceived[1] << DataReceived[2];
    int niveauBatterie = static_cast<int>(DataReceived[2]);

    float odometrieD = ((((long)DataReceived[16] << 24))+(((long)DataReceived[15] << 16))+(((long)DataReceived[14] << 8))+((long)DataReceived[13]));

    float odometrieG = ((((long)DataReceived[8] << 24))+(((long)DataReceived[7] << 16))+(((long)DataReceived[6] << 8))+((long)DataReceived[5]));

    emit batteryUpdate(niveauBatterie);
    emit odoDUpdate(odometrieD);
    emit odoGUpdate(odometrieG);

}

void MyRobot::MyTimerSlot() {
    qDebug() << "Timer...";
    while(Mutex.tryLock());
    socket->write(DataToSend);
    Mutex.unlock();
}

short MyRobot::Crc16(QByteArray Adresse_tab , unsigned char Taille_max)
{
    unsigned int Crc = 0xFFFF;
    unsigned int Polynome = 0xA001;
    unsigned int CptOctet = 0;
    unsigned int CptBit = 0;
    unsigned int Parity= 0;
    Crc = 0xFFFF;
    Polynome = 0xA001;
    for ( CptOctet= 1 ; CptOctet < Taille_max ; CptOctet++)
    {
        Crc ^= (unsigned char)(Adresse_tab[CptOctet]);
        for ( CptBit = 0; CptBit <= 7 ; CptBit++)
        {
            Parity= Crc;
            Crc >>= 1;
            if (Parity%2 == true)
            {
                Crc ^= Polynome;
            }
        }
    }

    return(Crc);
}

void MyRobot::crctosend()
{
    // Calculer le CRC à partir des données actuelles dans DataToSend
    short crc = Crc16(DataToSend,7);

    // Ajouter le CRC aux octets 7 et 8 de DataToSend
    DataToSend[7] = crc;           // Octet 7
    DataToSend[8] = crc >> 8;    // Octet 8
    DataReceived.resize(21);

}


//Focntion faisant avancer le robot
void MyRobot::avancer(){
    DataToSend[2] = 100;
    DataToSend[3] = 0;
    DataToSend[4] = 100;
    DataToSend[5] = 0;
    DataToSend[6] = 80;
    crctosend();
}

//Focntion faisant reculer le robot
void MyRobot::reculer(){
    DataToSend[2] = 100;
    DataToSend[3] = 0;
    DataToSend[4] = 100;
    DataToSend[5] = 0;
    DataToSend[6] = 0;
    crctosend();

}

//Focntion faisant aller le robot à droite
void MyRobot::allerDroite(){
    DataToSend[2] = 150;
    DataToSend[3] = 0;
    DataToSend[4] = 150;
    DataToSend[5] = 0;
    DataToSend[6] = 64;
    crctosend();
}

//Focntion faisant aller le robot à gauche
void MyRobot::allerGauche(){
    DataToSend[2] = 150;
    DataToSend[3] = 0;
    DataToSend[4] = 150;
    DataToSend[5] = 0;
    DataToSend[6] = 16;
    crctosend();
}

//Focntion faisant s'arrêter le robot
void MyRobot::stop(){
    DataToSend[2] = 0x00;
    DataToSend[3] = 0x00;
    DataToSend[4] = 0x00;
    DataToSend[5] = 0x00;
    DataToSend[6] = 80;
    crctosend();
}
float MyRobot::Batterie(){
    unsigned char data = (DataReceived[2] >> 2);
    float batterie = float(data);
    return batterie;
}
QWebEngineView* MyRobot::cameraStream(QString ip, QString port){

    QUrl url = QUrl("http://" + ip + ":" + port + "/?action=stream");
    qDebug() << url;
    QWebEngineView *view = new QWebEngineView();
    view->load(url);
    return view;
}

void MyRobot::bytesWritten(qint64 bytes){
    qDebug() << bytes << "bytes written";
}


