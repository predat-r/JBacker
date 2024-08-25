// #include <iostream>
// #include <ctime>
// using namespace std;

// int main() {

//     time_t currentTime = time(nullptr);
//     tm* yum = localtime(&currentTime);
//     int year = (yum->tm_year) + 1900;
//     int month = (yum->tm_mon) + 1;
//     int day = (yum->tm_mday);
//     cout<<"\n"<<year<<"\n"<<month<<"\n"<<day;
     
//     return 0;

// }
#include <iostream>
#include  <json.hpp>
using namespace std; // Namespace directive

string getApiResponse(const string& url) {
    CURL *curl;
    CURLcode res;
    string response;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, [](char *ptr, size_t size, size_t nmemb, string *data) -> size_t {
            data->append(ptr, size * nmemb);
            return size * nmemb;
        });
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);
        res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);
    } else {
        cerr << "curl_easy_init() failed" << endl;
    }

    curl_global_cleanup();
    return response;
}
void parseApiResponse(const string& response) {
    Json::Value root;
    Json::Reader reader;
    bool parsingSuccessful = reader.parse(response, root);
    if (!parsingSuccessful) {
        cerr << "Failed to parse JSON" << endl;
        return;
    }

    if (root.isMember("results")) {
        Json::Value results = root["results"];
        string sunrise = results["sunrise"].asString();
        string sunset = results["sunset"].asString();
        cout << "Sunrise: " << sunrise << endl;
        cout << "Sunset: " << sunset << endl;
    } else {
        cerr << "Results not found in JSON" << endl;
    }
}
int main() {
    string url = "https://api.sunrise-sunset.org/json?lat=36.7201600&lng=-4.4203400&date=today";
    string response = getApiResponse(url);
    parseApiResponse(response);
    return 0;
}
