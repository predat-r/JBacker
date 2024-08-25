#ifndef SimpleWeather_h
#define SimpleWeather_h

#include <string> // Include standard C++ headers
#include <curl/curl.h> // Include cURL for making HTTP requests

using namespace std; // Add using namespace std;

// Define a struct to hold weather data
struct WeatherData {
    string weather;
    string description;
    string icon;
    int id;
    float current_Temp;
    float min_temp;
    float max_temp;
    float humidity;
    float rain;
};

class OpenWeather {
public:
    OpenWeather(string Key, string City);
    OpenWeather(string Key, float lat, float longi);
    OpenWeather(string Key, string City, bool forecast);
    void updateStatus(WeatherData *w);
    string getResponse();
private:
    string _Response;
    string _url;
    bool _forecast;
};

class Darksky {
public:
    Darksky(string Key, float lat, float longi);
    Darksky(string Key, float lat, float longi, unsigned long timestamp);
    void updateStatus(WeatherData *w);
    void updateURL(string Key, float lat, float longi, unsigned long timestamp);
    void updateURL(string Key, float lat, float longi);
    string getResponse();
private:
    string _Response;
    string _url;
};

#endif
