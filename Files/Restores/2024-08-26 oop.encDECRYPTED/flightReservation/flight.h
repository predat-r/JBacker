

#include<iostream>
#include<string>
#include<fstream>
using namespace std;
class flight
{
    int ID;
    string airlineName;
    string departure;
    string destination;
    float flightDuration;
    int year, month, day;

public:
    flight(string x = " ", string y = " ", int t = 0)
    {
        departure = x;
        destination = y;
        flightDuration = t;
        year = 0;
        month = 0;
        day = 0;
    }
    void setDeparture(string x)
    {
        departure = x;
    }
    void setDestination(string x)
    {
        destination = x;
    }
    void setName(string x)
    {
        airlineName = x;
    }
    void setID(int x)
    {
        ID = x;
    }
    string getdeparture()
    {
        return departure;
    }
    string getdestination() { return destination; }
    string getName()
    {
        return airlineName;
    }
    void setFlightduration(float x)
    {
        flightDuration = x;
    }
    void setDate(int x, int y, int z)
    {
        day = x;
        month = y;
        year = z;
    }
    int getID()
    {
        return ID;
    }
    void printdate()
    {
        cout << day << "/" << month << "/" << year;
    }
    void readFromfile(ifstream &file)
    {
        file >> ID >> airlineName >> departure >> destination >> flightDuration >> day >> month >> year;
    }
    void flightInfo()
    {
        cout << "\nID of your flight : " << ID << "\nAirline : " << airlineName << "\nDeparture city : " << departure << "\nDestination city : " << destination << "\nDate of your flight : ";
        printdate();
        cout << "\nDuration of your flight : " << flightDuration << "hrs";
    }
};
