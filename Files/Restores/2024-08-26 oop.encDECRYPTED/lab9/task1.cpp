#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;
class Employee
{
    char name[50];
    int number;

public:
    Employee()
    {
        int b = 0;

        for (size_t i = 0; i < 50; i++)
        {
            name[i] = 0;
        }
    }
    Employee(char *a, int b = 0)
    {
        number = b;
        for (size_t i = 0; i < 50; i++)
        {
            name[i] = a[i];
            if (a[i] == '\0')
            {
                break;
            }
        }
    }
    Employee(const Employee &e)
    {
        this->number = e.number;
        for (size_t i = 0; i < 50; i++)
        {
            name[i] = e.name[i];
            if (e.name[i] == '\0')
            {
                break;
            }
        }
    }
    void setName(char *a)
    {
        for (size_t i = 0; i < 50; i++)
        {
            name[i] = a[i];
            if (a[i] == '\0')
            {
                break;
            }
        }
    }
    void setNumber(int a)
    {
        number = a;
    }
    char *getName()
    {
        return name;
    }
    int getNumber() const
    {
        return number;
    }
    void operator=(const Employee &e)
    {
        this->number = e.number;
        for (size_t i = 0; i < 50; i++)
        {
            name[i] = e.name[i];
            if (e.name[i] == '\0')
            {
                break;
            }
        }
    }
    void display() const
    {
        cout << "\nname : " << name;
        cout << "\nID  : " << number;
    }
};
class ProductionWorker : public Employee
{
    int shift;
    double payRate;

public:
    ProductionWorker()
    {
        shift = 0;
        payRate = 0;
    }
    ProductionWorker(int a, double b, char *c, int d) : Employee(c, d)
    {
        shift = a;
        payRate = b;
    }

    void setShift(int n)
    {
        shift = n;
    }
    void setPayrate(double n)
    {
        payRate = n;
    }
    int getShift() const
    {
        return shift;
    }
    double getPayrate() const
    {
        return payRate;
    }
    void display()
    {
        cout << "\n\nName : " << getName() << "\nNumber : " << getNumber() << "\nShift : " << shift << "\nPayrate : " << payRate;
    }
};
class TeamLeader : public ProductionWorker
{
    double bonus;
    int reqHours;
    int attHours;

public:
    TeamLeader()
    {
        bonus = 0;
        reqHours = 0;
        attHours = 0;
    }
    TeamLeader(double bon, int r, int att, int a, double b, char *c, int d) : ProductionWorker(a, b, c, d)
    {
        bonus = bon;
        reqHours = r;
        attHours = att;
    }
    void setBonus(int a)
    {
        bonus = a;
    }
    void setReq(int a)
    {
        reqHours = a;
    }
    void setAtt(int a)
    {
        attHours = a;
    }
    void display()
    {

        cout << "\n\nName : " << getName() << "\nNumber : " << getNumber() << "\nShift : " << getShift() << "\nPayrate : " << getPayrate() << "\nBonus : " << bonus << "\nRequired hours : " << reqHours << "\nAttended hours : " << attHours;
    }
};
int main()
{
    int num1, num2;
    char name1[50];
    char name2[50];
    cout << "\nEnter name of Employee : ";
    cin >> name1;
    cout << "\nEnter number of employee : ";
    cin >> num1;
    Employee e0(name1, num1);
    e0.display();
    cout << "\nEnter name of Employee number 2  : ";
    cin >> name2;
    cout << "\nEnter number of employee number 2 : ";
    cin >> num2;
    Employee *e1 = new Employee(name2, num2);
    e1->display();
    int num3, num4;
    double num5, num6;
    cout << "\nEnter name of Employee : ";
    cin >> name1;
    cout << "\nEnter number of employee : ";
    cin >> num1;
    cout << "\nEnter shift of worker : ";
    cin >> num3;
    cout << "\nEnter hourly pay rate : ";
    cin >> num5;
    ProductionWorker p0(num3, num5, name1, num1);
    p0.display();
    cout << "\nEnter name of Employee : ";
    cin >> name2;
    cout << "\nEnter number of employee : ";
    cin >> num2;
    cout << "\nEnter shift of worker : ";
    cin >> num4;
    cout << "\nEnter hourly pay rate : ";
    cin >> num6;
    ProductionWorker *p1 = new ProductionWorker(num4, num6, name2, num2);
    p1->display();
    delete p1;
    delete e1;
    int tls;
    cout << "\nHow many team leaders do you want to create : \n";
    cin >> tls;
    int num7, num8;
    double num9;
    TeamLeader **teamleaders = new TeamLeader *[tls];
    for (size_t i = 0; i < tls; i++)
    {
        teamleaders[i] = new TeamLeader;
    }

    for (size_t i = 0; i < tls; i++)
    {
        cout << "\nEnter name of Employee : ";
        cin >> name2;
        teamleaders[i]->setName(name2);
        cout << "\nEnter number of employee : ";
        cin >> num2;
        teamleaders[i]->setNumber(num2);
        cout << "\nEnter shift of worker : ";
        cin >> num4;
        teamleaders[i]->setShift(num4);
        cout << "\nEnter hourly pay rate : ";
        cin >> num6;
        teamleaders[i]->setPayrate(num6);
        cout << "\nEnter bonus amount : ";
        cin >> num9;
        teamleaders[i]->setBonus(num9);
        cout << "\nEnter required hours : ";
        cin >> num7;
        teamleaders[i]->setReq(num7);
        cout << "\nEnter attended hours : ";
        cin >> num8;
        teamleaders[i]->setAtt(num8);
    }
    for (size_t i = 0; i < tls; i++)
    {
        teamleaders[i]->display();
    }
    for (size_t i = 0; i < tls; i++)
    {
        delete[] teamleaders[i];
    }
    delete[] teamleaders;

    teamleaders = nullptr;
}