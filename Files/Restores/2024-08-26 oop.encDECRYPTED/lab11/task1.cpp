#include <iostream>
#include <string>
using namespace std;
class ship
{
    string name;
    string year;

public:
    ship()
    {
        name = " ";
        year = " ";
    }
    ship(string a, string b)
    {
        name = a;
        year = b;
    }
    void setName(string a)
    {
        name = a;
    }
    void setYear(string b)
    {
        year = b;
    }
    string getYear() const
    {
        return year;
    }
    string getName() const
    {
        return name;
    }
    virtual void print()
    {
        cout << "\nThe information of your ship is : \n";
        cout << "Name : " << getName() << "\nYear : " << getYear();
    }
};
class CruiseShip : public ship
{
    int Pcount;

public:
    CruiseShip()
    {
        Pcount = 0;
    }
    CruiseShip(int a, string b, string c) : ship(b, c)
    {
        Pcount = a;
    }
    void setPcount(int a)
    {
        Pcount = a;
    }
    int getPcount() const
    {
        return Pcount;
    }
    void print() override
    {
        cout << "\nThe information of cruise ship is as follows :\n"
             << "Name : " << getName() << "\nYear :" << getYear() << "\nMax Passenger count : " << getPcount();
    }
};
class CargoShip : public ship
{
    int capacity;

public:
    CargoShip()
    {
        capacity = 0;
    }
    CargoShip(int a, string b, string c) : ship(b, c)
    {
        capacity = a;
    }
    void setCapacity(int a)
    {
        capacity = a;
    }
    int getCapacity() const
    {
        return capacity;
    }
    void print() override
    {
        cout << "\nThe information of Cargo ship is as follows :\n"
             << "Name : " << getName() << "\nYear :" << getYear() << "\nMax capacity in tons: " << getCapacity();
    }
};
class BattleShip : public ship
{
    int missiles;

public:
    BattleShip()
    {
        missiles = 0;
    }
    BattleShip(int a, string b, string c) : ship(b, c)
    {
        missiles = a;
    }
    void setMissiles(int a)
    {
        missiles = a;
    }
    int getMissiles() const
    {
        return missiles;
    }
    void print() override
    {
        cout << "\nThe information of Battle ship is as follows :\n"
             << "Name : " << getName() << "\n missiles : " << getMissiles();
    }
};
int main()
{

    int count;
    int num;
    cout << "\nHow many ships do u want to create :  ";
    cin >> count;
    ship **si = new ship *[count];
    for (int i = 0; i < count; i++)
    {
        cout << "\nWhich type of ship do u want to create on this index :\n1---Cruise ship\n2---Cargo ship\n3---Battle ship";
        cout << "\nEnter Respective number : ";
        cin >> num;
        if (num == 1)
        {
            si[i] = new CruiseShip(190, "Titanic", "1990");
        }
        else if (num == 2)
        {
            si[i] = new CargoShip(3000, "PAKCargo", "1990");
        }
        else if (num == 3)
        {
            si[i] = new BattleShip(70, "US SSR", "1990");
        }
    }
    for (size_t i = 0; i < count; i++)
    {
        si[i]->print();
    }
    for (size_t i = 0; i < count; i++)
    {
        delete si[i];
    }
    delete[] si;
    
    
}