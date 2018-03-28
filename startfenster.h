/**
 * @file startfenster.h
 * @brief Header von Startfenster
 * @author V. Feierle
 * */

#ifndef STARTFENSTER_H
#define STARTFENSTER_H

#include <QDialog>
#include <QPushButton>
#include "spielfeld.h"
#include <QTextBrowser>

namespace Ui {
class Startfenster;
}

/**
 * @brief Klasse Startfenster
 */
class Startfenster : public QDialog
{
    Q_OBJECT

public:
    /**
     * @brief Startfenster: Konstruktor
     */
    explicit Startfenster(QObject *parent = 0);
    ~Startfenster();
    /**
     * @brief spielfeld: erzeugt spielfeld
     */
    Spielfeld* spielfeld;


private:
    Ui::Startfenster *ui;
    /**
     * @brief port: Eingegebener Port
     */
    qint16 port;
    /**
     * @brief host: Eingegebener Host
     */
    QString host;

signals:
    /**
     * @brief ClientMode: emittiert, wenn Client ausgewählt ist, Host und Port
     * @param host: Host Adresse
     * @param port: Port Adresse
     */
    void ClientMode(QString host , quint16 port);
    /**
     * @brief ServerMode: emittiert, wenn Server ausgewählt ist, Port
     * @param port: Port Adresse
     */
    void ServerMode(quint16 port);
    /**
     * @brief disconnectButton: emittiert Signal, wenn im Startfenster der Trennen Button geklickt wird
     */
    void disconnectButton();


public slots:
    /**
     * @brief readFromNetwork: gibt Nachrichten im Textfeld aus
     * @param message: übergebene Nachricht vom Netzwerk
     */
    void readFromNetwork(QString message);
    /**
     * @brief state: emittiert Signal ob Server oder Client ausgewählt ist
     */
    void state();

private slots:
    /**
     * @brief on_StartSpielfeld_clicked: zeigt bei Start das Spielfeld
     */
    void on_StartSpielfeld_clicked();
    /**
     * @brief disableHost: ist Server ausgewählt, kann nur ein Port eingegeben werden
     */
    void disableHost();
    /// @brief ist Client ausgewählt, kann ein Host und ein Port eingegeben werden
    /**
     * @brief enableHost: ist Client ausgewählt, kann ein Host und ein Port eingegeben werden
     */
    void enableHost();

};

#endif // STARTFENSTER_H
