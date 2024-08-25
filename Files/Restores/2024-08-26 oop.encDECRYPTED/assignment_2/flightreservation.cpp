#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class airplane  
{
    static int reg;
    int code;
    int totalSeats;
    int seatsBooked;w2
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
int entries;
int *e = &entries;
int airplane::reg = 0;
string *totalDestinations(airline *, int, string *);
string *shortlistDestinations(airline *, string *, int, int, string *);
string *totaldepartures(airline *airlines, int total)
{
    int totaldeps = 100;
    string *departureCities = new string[totaldeps];
    departureCities[0] = "0";
    int index = 0;
    for (size_t i = 0; i < total; i++)
    {
        string *temp = new string[100];

        temp = airlines[i].getDepartures();
        for (size_t k = 0; k < totaldeps; k++)
        {
            if (departureCities[k] == "0")
            {
                index = k;
            }
        }

        int g = 0;
        for (size_t j = index;; j++)
        {
            for (size_t m = 0; m < index; m++)
            {

                if (departureCities[m] == temp[g])
                {

                    g++;
                    m = -1;
                }
            }

            departureCities[j] = temp[g];
            if (temp[g] == "0")
            {
                break;
            }
            g++;
        }
    }
    cout << "Select a city to departure from the following : \n ";
    int choice;
    for (size_t i = 0;; i++)
    {
        if (departureCities[i] == "0")
        {
            break;
        }
        cout << "\n"
             << i << "---" << departureCities[i];
    }
    cout << "\n";
    cout << "\nEnter the respective number \n";
    cin >> choice;
    string *finalRoute = new string[2];
    finalRoute[0] = departureCities[choice];
    return shortlistDestinations(airlines, departureCities, choice, total, finalRoute);
}
string *shortlistDestinations(airline *airlines, string *departureCities, int choice, int total, string *finalRoute)
{

    airline *shortlistedLines = new airline[total];
    int index = 0;
    for (size_t i = 0; i < total; i++)
    {
        string *temp = airlines[i].getDepartures();
        for (size_t j = 0; temp[j] != "0"; j++)
        {

            if (departureCities[choice] == temp[j])
            {
                shortlistedLines[index] = airlines[i];
                index++;
            }
        }
    }

    return totalDestinations(shortlistedLines, index, finalRoute);
}
string *totalDestinations(airline *airlines, int total, string *finalRoute)
{

    cout << "\nThe destination cities are :\n";
    int choice;
    int totaldes = 50;
    string *destinationCities = new string[totaldes];
    destinationCities[0] = "0";
    int index2 = 0;
    for (size_t i = 0; i < total; i++)
    {
        string *temp = airlines[i].getDestinations();
        for (size_t k = 0; k < totaldes; k++)
        {
            if (destinationCities[k] == "0")
            {
                index2 = k;
            }
        }
        int g = 0;
        for (size_t j = index2;; j++)
        {
            destinationCities[j] = temp[g];
            if (temp[g] == "0")
            {
                break;
            }
            g++;
        }
    }

    for (size_t i = 0; destinationCities[i] != "0"; i++)
    {
        cout << "\n"
             << i << "---" << destinationCities[i];
    }
    cout << "\n\nEnter the respective number :\n";
    cout << "\n";
    cin >> choice;
    finalRoute[1] = destinationCities[choice];
    return finalRoute;
}
airline *availableLines(string *a, airline *airlines, int total)
{
    int index = 0;
    airline *temp = new airline[total];
    for (size_t i = 0; i < total; i++)
    {
        string *tempA = airlines[i].getDepartures();
        string *tempB = airlines[i].getDestinations();
        int A = airlines[i].getDeparturecount();
        int B = airlines[i].getDestinationcount();
        for (size_t j = 0; j < A; j++)
        {
            if (tempA[j] == a[0])
            {
                for (size_t k = 0; k < B; k++)
                {
                    if (tempB[k] == a[1])
                    {
                        temp[index] = airlines[i];
                        index++;
                    }
                }
            }
        }
    }
    temp[index].setFlag(-1);

    return temp;
}
int *bookFlight(airline *airlines, flight *flights, airplane *airplanes, int total, int numOfFlights, int *bookedflight)
{

    for (size_t booking = 0;; booking++)
    {
        int choice = 0;

        cout << "\nWelcome to flight reservation system\n";
        string *a = new string[100];
        a = totaldepartures(airlines, total);
        airline *available = availableLines(a, airlines, total);
        cout << "\nFollowing airlines are available for traveling from " << a[0] << " ->- " << a[1] << " : \n";

        for (size_t i = 0; int a = available[i].getFlag() != -1; i++)
        {
            string name = available[i].getName();
            cout << i + 1 << "---" << name << "\n";
        }
        cout << "\nEnter the respective number\n";
        cin >> choice;
        choice--;
        int *options = new int[10];
        int j = 0;
        for (size_t i = 0; i < numOfFlights; i++)
        {

            if ((flights[i].getdeparture() == a[0] && flights[i].getdestination() == a[1]) && flights[i].getName() == available[choice].getName())
            {

                options[j] = i;
                j++;
            }
        }
        options[j] = -1;
        int date;
        cout << "\n\nThe following dates are available : \n";
        for (size_t i = 0; options[i] != -1; i++)
        {
            cout << "\n"
                 << i << "--";
            flights[options[i]].printdate();
        }
        cin.ignore();
        cout << "\n\nEnter the corresponding number : \n";
        cin >> date;
        cout << "\n";
        int cls;
        cout << "AN" << airplanes[options[date]].getreg() << " will be the registration number of your airplane !\n";
        cout << "\nWhich seat would you like to book :\n1---Economy\n2---Business class\n\n";
        cin >> cls;
        int quantity;
        cout << "\nHow many seats would you like to book :\n";
        cin >> quantity;
        if (airplanes[options[date]].BookSeat(cls, quantity) != 1)
        {
            continue;
        }
        airplanes[options[date]].BookSeat(cls, quantity);

        cout << "\n\nThank you for booking  a flight with us, the complete details of your flight are as follows : \n\n";
        cout << "Registration number :\n"
             << "AN" << airplanes[options[date]].getreg();
        flights[options[date]].setID(airplanes[options[date]].getreg() + 100);
        int p = 1;
        bookedflight[*e] = flights[options[date]].getID();
        bookedflight[*e + p] = cls;
        p++;
        bookedflight[*e + p] = quantity;

        flights[options[date]].flightInfo();

        cout << "\n\n\nWould you like to book another flight ? :\n1---yes\n2---no\n\n";
        cin >> choice;
        if (choice == 2)
        {
            *e += 3;
            return bookedflight;
        }
        if (choice == 1)
        {

            *e += 3;
            continue;
        }
        else
        {
            cout << "\nenter valid option: \n";
            cin >> choice;
        }
    }
    for (size_t i = 0; i < 9; i++)
    {
        cout << "\t" << bookedflight[i];
    }

    return bookedflight;
}

void detailsFlight(airline *airlines, flight *flights, airplane *airplanes, int count, int numOfFlights)
{
    int id;
    cout << "\n\nEnter The registration number of your flight : \n";
    cin >> id;
    for (size_t i = 0; i < numOfFlights; i++)
    {
        if (id == flights[i].getID())
        {
            flights[i].flightInfo();
        }
    }
    cout << "\n";
}
void cancelFlight(flight *flights, airplane *airplanes, int count, int numOfFlights, int *bookedflights)
{
    int id;
    int index;
    cout << "\n\nEnter The registration number of your flight : \n";
    cin >> id;
    for (size_t i = 0; i < numOfFlights; i++)
    {
        if (flights[i].getID() == id)
        {
            index = i;
            break;
        }
    }

    for (size_t i = 0; i < entries; i += 3)
    {
        if (id == bookedflights[i])
        {
            airplanes[index].cancel(bookedflights[i + 1], bookedflights[i + 2]);
            bookedflights[i + 1] = 0;
            bookedflights[i + 2] = 0;
        }
    }
    cout << "\nYour booking has successfully been cancelled";
}
int main()
{
    int count = 0;
    int numOfFlights = 0;
    ifstream infile("airlineinfo.txt");
    infile >> count;
    airline *airlines = new airline[count];
    int i = 0;
    while (i < count)
    {
        airlines[i].readAirlines(infile);
        i++;
    }
    infile.close();
    ifstream ifile("scheduledFlights.txt");
    ifile >> numOfFlights;
    airplane *airplanes = new airplane[numOfFlights];
    for (size_t i = 0; i < numOfFlights; i++)
    {
        airplanes[i].readfromfile(ifile);
    }

    ifstream iptFile("upcomingTravels.txt");
    flight *flights = new flight[numOfFlights];
    for (size_t i = 0; i < numOfFlights; i++)
    {
        flights[i].readFromfile(iptFile);
    }

    ifstream flightsfile("bookedFlights.txt");
    flightsfile >> *e;
    int *bookedFlights = new int[*e];
    for (int i = 0; i < *e; i++)
    {

        flightsfile >> bookedFlights[i];
    }

    int choice;
    do
    {

        cout << "\n\t\tWELCOME TO FLIGHT RESERVATION SYSTEM\n\nWhat do you want to perform : \n\n1----Book a flight\n2----See details of your Flight\n3----Cancel a flight\n4----Exit program\n\n";
        cin >> choice;
        switch (choice)
        {
        case 1:
            bookedFlights = bookFlight(airlines, flights, airplanes, count, numOfFlights, bookedFlights);
            break;
        case 2:
            detailsFlight(airlines, flights, airplanes, count, numOfFlights);
            break;
        case 3:
            cancelFlight(flights, airplanes, count, numOfFlights, bookedFlights);
            break;
        default:

            break;
        }
    } while (choice != 4);
    ofstream ofile("bookedFlights.txt");
    ofile << *e;
    ofile << "\n";

    for (size_t i = 0; i < *e; i++)
    {
        ofile << bookedFlights[i] << "\t\t\t";
        if ((i + 1) % 3 == 0)
        {
            ofile << "\n";
        }
    }
    ofstream outfile("scheduledFlights.txt");
    outfile << numOfFlights;

    outfile << "\n";
    for (size_t i = 0; i < numOfFlights; i++)
    {
        airplanes[i].writetofile(outfile);
        outfile << "\n";
    }

    delete[] airlines;
    delete[] airplanes;
    delete[] flights;
    return 0;
}
