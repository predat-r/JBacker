#include <iostream>
#include <string>
using namespace std;
class date
{
    int day;
    int month;
    int year;

public:
    date(int d = 0, int m = 0, int y = 0)
    {
        day = d;
        month = m;
        year = y;
    }
    int getDay()
    {
        return day;
    }
    int getMonth()
    {
        return month;
    }
    int getYear()
    {
        return year;
    }
    void printDate()
    {
        cout << "\n";
        cout << day << "/" << month << "/" << year;
    }
};
class time
{
    int hour;
    int min;
    int sec;

public:
    time(int h = 0, int m = 0, int s = 0)
    {
        hour = h;
        min = m;
        sec = s;
    }
    int getHour()
    {
        return hour;
    }
    int getMin()
    {
        return min;
    }
    int getSec()
    {
        return sec;
    }
    void printTime()
    {

        cout << hour << ":" << min << ":" << sec;
    }
};
class datetime : public date, public time
{
public:
    datetime(int d, int m, int y, int h, int min, int s) : date(d, m, y), time(h, min, s)
    {
    }
    string names[12] = {"january", " february", "march", "april", "may", "june", "july", "august", "september", "october", "november", "december"};
    void showFormatteddateTime()
    {
        string a = names[getMonth()];
        cout << "\n"
             << a << " " << getDay() << ", " << getYear() << " ";
        printTime();
    }
    void printDateTime()
    {
        printDate();
        cout << " ";
        printTime();
    }
};
int main()
{   
    datetime dt(5, 7, 2024, 2, 32, 12);
    dt.printDateTime();
    dt.showFormatteddateTime();
    return 0;
}