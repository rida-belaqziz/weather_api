#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QNetworkRequest>
#include <vector>
#include <QString>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow) {
    ui->setupUi(this);

    // Initialiser le gestionnaire réseau
    networkManager = new QNetworkAccessManager(this);

    // Initialiser les villes dans le combo box
    std::vector<QString> villes = {"Paris", "Lille", "Poitiers", "New York", "Tokyo", "Berlin", "Moscou"};
    for(const auto &city : villes){ui->comboBox_ville->addItem(city);}

    // Connecter le bouton à l'action de récupération météo
    connect(ui->pushButton_valider, &QPushButton::clicked, this, &MainWindow::onFetchWeatherClicked);

    // Connecter le gestionnaire réseau pour traiter les données de l'API
    connect(networkManager, &QNetworkAccessManager::finished, this, &MainWindow::onWeatherDataReceived);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::onFetchWeatherClicked() {
    QString city = ui->comboBox_ville->currentText();  // Récupère la ville sélectionnée
    QString apiKey = "YOUR_API_KEY";             // clé API
    QString url = QString("http://api.openweathermap.org/data/2.5/weather?q=%1&appid=%2&units=metric")
                  .arg(city)
                  .arg(apiKey);

    // Envoyer la requête GET
    networkManager->get(QNetworkRequest(QUrl(url)));
}


void MainWindow::onWeatherDataReceived(QNetworkReply *reply) {
    if (reply->error() == QNetworkReply::NoError) {
        QByteArray responseData = reply->readAll();  // Lire les données JSON
        QJsonDocument jsonDoc = QJsonDocument::fromJson(responseData);
        QJsonObject jsonObj = jsonDoc.object();

        // Extraire les informations météo
        double temp = jsonObj["main"].toObject()["temp"].toDouble();
        int humidity = jsonObj["main"].toObject()["humidity"].toInt();
        double windSpeed = jsonObj["wind"].toObject()["speed"].toDouble();

        // Afficher QLCDNumber
        ui->lcdNumber_temp->display(temp);
        ui->lcdNumber_hum->display(humidity);
        ui->lcdNumber_vent->display(windSpeed);
    } else {
        // erreur si la requête a échoué
        ui->lcdNumber_temp->display(0);
        ui->lcdNumber_hum->display(0);
        ui->lcdNumber_vent->display(0);
    }
    reply->deleteLater();
}















