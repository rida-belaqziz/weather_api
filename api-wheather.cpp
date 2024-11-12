#include <iostream>
#include <string>
#include <curl/curl.h> //qui permet d’effectuer des requêtes HTTP (comme GET ou POST).
#include <json/json.h> //parser les réponses en JSON.


using namespace std;
// Fonction pour écrire les données de la requête
// WriteCallback est une fonction de callback utilisée pour stocker les données de la réponse HTTP de curl dans une chaîne de caractères. Elle est appelée chaque fois que des données sont reçues.
size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp) {
    ((string*)userp)->append((char*)contents, size * nmemb); // Convertit userp en std::string et ajoute les données reçues (contents) à cette chaîne.
    return size * nmemb;
}

int main() {
    string api_key = "API_KEY";
    // city
    string city;
    cout<<"Entrer le nom de la ville:  ";
    cin>>city;
    // url          
    string url = "http://api.openweathermap.org/data/2.5/weather?q=" + city + "&appid=" + api_key + "&units=metric";
    // curl
    CURL* curl; 
    CURLcode res;
    string readBuffer;

    curl = curl_easy_init(); // initialise la session curl
    if (curl) {
        //Configurer curl avec curl_easy_setopt
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str()); //définit l’URL à laquelle curl va envoyer la requête
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
        res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);

        if (res == CURLE_OK) {
            // Parser la réponse JSON
            Json::CharReaderBuilder readerBuilder;
            Json::Value jsonData;
            string errs;
            istringstream s(readBuffer);

            if (parseFromStream(readerBuilder, s, &jsonData, &errs)) {
                cout<<""<<endl;
                cout<<":::: Meteo ::::"<<endl;
                cout << "Ville: " << jsonData["name"].asString() << endl;
                cout << "Température: " << jsonData["main"]["temp"].asFloat() << "°C" << endl;
                cout << "Description: " << jsonData["weather"][0]["description"].asString() << endl;
                cout << "Humidité: " << jsonData["main"]["humidity"].asFloat() <<" %"<< endl;
                cout << "Vent: " << jsonData["wind"]["speed"].asFloat() <<"km/h"<<endl; 
                cout << "Pression atmosphérique: " << jsonData["main"]["pressure"].asFloat() <<" hectopascals"<<endl; 
                cout<<""<<endl;
            } else {
                cout << "Erreur : " << errs << endl;
            }
        } else {
            cerr << "Erreur : " << curl_easy_strerror(res) << endl;
        }
    }

    return 0;
}