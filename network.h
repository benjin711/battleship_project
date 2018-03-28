#ifndef NETWORK_H
#define NETWORK_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include <QDebug>
#include <QTimer>
#include <QDataStream>
#include <utility>


class network : public QObject {
    Q_OBJECT
public:

    explicit network(QObject *parent);
    ~network();

signals:
    /**
     * @brief GameParams : Übergibt Spielkonfiguration
     * @param data : Spielfeldgröße, Anzahl Schiffe
     */
    void GameParams(std::vector<quint8> data);
    /**
     * @brief Shot : Empfängt beschossene Koordinaten
     * @param shot : Koordinaten
     */
    void Shot(std::pair<quint8,quint8> shot);
    /**
     * @brief GameState: Spielstatus
     * @param data : wer ist am Zug,etc.
     */
    void GameState(std::vector<quint8> data);
    /**
     * @brief ShotAnswer : Antwort auf Schuss
     * @param statuscode
     * @param koordinatenvector: gibt Koordinaten des versenkten Schiffes an
     */
    void ShotAnswer(quint8 statuscode,std::vector<std::pair<quint8,quint8>> koordinatenvector);

    /**
     * @brief NoAnswer : Keine Antwort vom Gegner
     */
    void NoAnswer();

    /**
     * @brief NetworkToGui: Ausgabe verschiedener Stadien.
     */
    void NetworkToGui(QString);

    /**
     * @brief GameStart: Initialisiert Spielbeginner für Logik
     */
    void GameStart(bool);


public slots:

    /**
     * @brief network::startToWaitForAnswer : Timer wird gestartet um Antwortverzögerung festzustellen
     */
    void startToWaitForAnswer();

    /**
     * @brief network::sendTimeoutToEnemy : Timeout wird gesendet
     */
    void sendTimeoutToEnemy();

    /**
     * @brief network::send : Sendefunktion für Daten an Gegner
     * @param cmd
     * @param length
     * @param data : Statuscode und Koordinanten
     */
    void send(quint8 cmd, quint8 length, std::vector<quint8> data);

    /**
     * @brief network::StartButtonPressed : Sobald der Spieler bereit ist wird eine Abfrage wer beginnt gestartet
     */
    void StartButtonPressed();

    /**
     * @brief network::connectionState : Verbindungsstatus wird überprüft
     */


    /**
     * @brief network::receiveData : Ankommende Nachrichten werden eingelesen,überprüft und je nach cmd verarbeitet
     */
    void receiveData();

    /**
     * @brief onSocketError: Socketfehler wird festgestellt
     */
    void onSocketError(QAbstractSocket::SocketError);

protected:

    QDataStream stream;
    QTcpSocket *socket;

private:

    QTimer *timer = new QTimer(this);
  ///Counter für Spielbeginn
    bool EnemyReady;
  ///Spieler bereit
    bool PlayerReady;


};

#endif // NETWORK_H

