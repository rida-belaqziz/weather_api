#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QNetworkAccessManager>
#include <QNetworkReply>

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    //void updateWeatherIcon(const QString);

private slots:
    void onFetchWeatherClicked();                  // Slot pour gérer le clic du bouton
    void onWeatherDataReceived(QNetworkReply *);   // Slot pour traiter les données reçues
    //void updateWeatherIcon(const QString);

private:
    Ui::MainWindow *ui;
    QNetworkAccessManager *networkManager;         // Gestionnaire réseau
};

#endif // MAINWINDOW_H



