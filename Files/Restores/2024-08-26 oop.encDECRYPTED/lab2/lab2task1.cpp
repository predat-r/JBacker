#include <iostream>
#include <string>
using namespace std;
class Date
{
    int Day;
    int Month;
    int Year;

public:
    Date()
    {
        Day = 0;
        Month = 0;
        Year = 0;
    }
    void setDay(int a)
    {
        if (a < 31 && a > 0)
        {
            Day = a;
        }
        else
        {
            cout << "Error!\n";
        }
    }
    void setMonth(int a)
    {
        if (a < 13 && a > 0)
        {
            Month = a;
        }
        else
        {
            cout << "error!";
        }
    }
    void setYear(int a)
    {
        if (a >= 0)
        {
            Year = a;
        }
        else
        {
            cout << "error!";
        }
    }
    int getDay() const
    {
        return Day;
    }
    int getMonth() const
    {
        return Month;
    }
    int getYear() const
    {
        return Year;
    }
    void displayDate() const
    {

        cout << getDay() << "/" << getMonth() << "/" << getYear();
    }
};
int main()
{
    int d, m, y;
    Date dates[5];
    dates[0].setDay(25);
    dates[0].setMonth(12);
    dates[0].setYear(1876);
    dates[1].setDay(9);
    dates[1].setMonth(11);
    dates[1].setYear(1877);
    dates[2].setDay(21);
    dates[2].setMonth(4);
    dates[2].setYear(1938);
    dates[3].setDay(14);
    dates[3].setMonth(6);
    dates[3].setYear(1947);
    dates[4].setDay(11);
    dates[4].setMonth(9);
    dates[4].setYear(1948);
    dates[0].displayDate();
    cout << "\n";
    dates[1].displayDate();
    cout << "\n";
    dates[2].displayDate();
    cout << "\n";
    dates[3].displayDate();
    cout << "\n";
    dates[4].displayDate();
    cout << "\n";

    // dynamic array :
    int length;
    cout << "\nenter length of new dynamic array : ";
    cin >> length;
    Date *ptr = new Date[length];
    for (size_t i = 0; i < length; i++)
    {
        cout << "enter Day\n";
        cin >> d;
        ptr[i].setDay(d);
        cout << "enter Month\n";
        cin >> m;
        ptr[i].setMonth(m);
        cout << "enter year\n";
        cin >> y;
        ptr[i].setYear(y);
    }
    for (size_t i = 0; i < length; i++)
    {
        ptr[i].displayDate();
    }
}
