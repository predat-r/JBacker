
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class airplane
{
    static int reg;
    int code;
    int totalSeats;
    int seatsBooked;
    int seatsAvailable;
    int economy;
    int business;

public:
    airplane(int x = 0, int y = 0)
    {
        reg++;
        code = reg;
        totalSeats = x;
        seatsBooked = y;
        seatsAvailable = x - y;
        business = x / 2 - ((x / 2) / 2);
        economy = totalSeats - business;
    }
    int BookSeat(int x, int y)
    {
        if (x == 1)
        {
            if (economy - y < 0)
            {
                cout << "\nNot available, kindly try later\n";
                return -1;
            };
            economy = economy - y;
        }
        if (x == 2)
        {
            if (business - y < 0)
            {
                cout << "\nNot available, kindly try later\n";
                return -1;
            };
            business = business - y;
        }
        seatsAvailable -= y;
        seatsBooked += y;
        return 1;
    }
    void cancel(int x, int y)
    {
        if (x == 1)
        {

            economy = economy + y;
        }
        if (x == 2)
        {
            business = business + y;
        }
        seatsBooked -= y;
        seatsAvailable += y;
    }
    void readfromfile(ifstream &infile)
    {
        infile >> totalSeats >> seatsBooked;
        seatsAvailable = totalSeats - seatsBooked;
        business = seatsAvailable / 2 - ((seatsAvailable / 2) / 2);
        economy = seatsAvailable - business;
    }
    void writetofile(ofstream &file)
    {
        file << totalSeats << "\t" << seatsBooked;
    }
    int getreg()
    {
        return code;
    }
    void displayAirplaneinfo()
    {
        cout << "\nThe information of aircraft is as follows :\nRegistration number : AN" << code << "\nTotal seats : " << totalSeats << "\nSeats available :" << seatsAvailable << "\nSeats available in economy class : " << economy << "\nSeats available in business class : " << business;
    }
    ~airplane()
    {
        reg--;
    }
};
int airplane::reg = 0;

class airline
{
    static int flying;
    string name;
    int Totalfleet;
    airplane *fleet;
    int departures, destinations;
    string *des;
    string *dep;
    int flag;

public:
    airline(string n = " ", int x = 0, int y = 0, int z = 0)
    {
        name = n;
        Totalfleet = x;
        departures = y;
        destinations = z;
        des = new string[z + 1];
        for (size_t i = 0; i <= z; i++)
        {
            des[i] = " ";
        }
        dep = new string[y + 1];
        for (size_t i = 0; i <= y; i++)
        {
            dep[i] = " ";
        }
        fleet = new airplane[Totalfleet];
        flag = 0;
    }

    void setDestinations()
    {

        for (size_t i = 0; i < destinations; i++)
        {

            getline(cin, des[i]);
        }
        des[destinations] = "0";
    }
    void setDepartures()
    {

        for (size_t i = 0; i < departures; i++)
        {
            getline(cin, dep[i]);
        }
        dep[departures] = "0";
    }

    string *getDepartures()
    {
        return dep;
    }
    string *getDestinations()
    {
        return des;
    }

    int getDestinationcount()
    {
        return destinations;
    }
    int getDeparturecount()
    {
        return departures;
    }
    void displayAirlineinfo() const
    {
        cout << "\nThe information of " << name << " is as follows :\n"
             << "Total fleet : " << Totalfleet << "\nList of departure cities : ";
        for (size_t i = 0; i < departures; i++)
        {
            cout << dep[i] << " |\t";
        }
        cout << "\nList of destination cities : ";
        for (size_t i = 0; i < destinations; i++)
        {
            cout << des[i] << " |\t";
        }
    }
    void setFleet(int x)
    {
        Totalfleet = x;
        delete[] fleet;
        airplane *fleet = new airplane[x];
    }
    int getFleet()
    {
        return Totalfleet;
    }
    void setName(string a)
    {
        name = a;
    }
    string getName()
    {
        return name;
    }
    void setFlag(int x)
    {
        flag = x;
    }
    int getFlag()
    {
        return flag;
    }
    void readAirlines(ifstream &file)
    {
        file >> name >> Totalfleet >> departures >> destinations;
        dep = new string[departures + 1];
        des = new string[destinations + 1];
        for (int i = 0; i < departures; ++i)
        {
            file >> dep[i];
        }

        dep[departures] = "0";

        for (int i = 0; i < destinations; ++i)
        {
            file >> des[i];
        }
        des[destinations] = "0";
    }
    void writeAirlines(ofstream &file)
    {
        file << name << Totalfleet << departures << destinations << "\n";

        for (int i = 0; i < departures; ++i)
        {
            file << dep[i];
        }
        for (int i = 0; i < destinations; ++i)
        {
            file << des[i];
        }
    }
    ~airline()
    {
        delete[] dep;
        delete[] des;
    }
};
int airline ::flying = 0;
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
