#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;
class employee
{
protected:
    string name;
    string ssn;
    double net_pay;

public:
    employee()
    {
        name = " ";
        ssn = " ";
        net_pay = 0.0;
    }
    employee(string the_name, string the_ssn, double netpay)
    {
        name = the_name;
        ssn = the_ssn;
        net_pay = netpay;
    }
    string get_name() const
    {
        return name;
    }
    string get_ssn() const
    {
        return ssn;
    }
    void set_name(string new_name)
    {
        name = new_name;
    }
    void set_ssn(string new_ssn)
    {
        ssn = new_ssn;
    }
    void set_netpay(double new_netpay)
    {
        net_pay = new_netpay;
    }
    void print_check() const
    {
        cout << "\n"
             << "Name : " << name << "\nSSN : " << ssn << "\nPay : $" << net_pay;
    }
};
class salariedEmployee : public employee
{
protected:
    double salary;

public:
    salariedEmployee()
    {
        salary = 0.0;
    }
    salariedEmployee(double the_weekly_salary, string the_name, string the_ssn, double netpay) : employee(the_name, the_ssn, netpay)
    {
        salary = the_weekly_salary;
    }
    double get_salary() const
    {
        return salary;
    }
    void set_salary(double the_new_salary)
    {
        salary = the_new_salary;
    }
    void print_check() const
    {

        cout << "\n"
             << "Name : " << get_name() << "\nSSN : " << get_ssn() << "\nNet pay : $" << net_pay << "\nWeekly Salary : $" << salary;
    }
};
class administrator : protected salariedEmployee
{
    string title;
    string area;
    string supervisor;

public:
    administrator()
    {   
    }
    administrator(string t, string a, string s, double the_weekly_salary, string the_name, string the_ssn, double netpay) : salariedEmployee(the_weekly_salary, the_name, the_ssn, netpay)
    {
        title = t;
        area = a;
        supervisor = s;
    }
    void set_supervisor(string s)
    {
        supervisor = s;
    }
    void set_data()
    {
        double e, b, c;
        string n, s, t, a, sv;
        cout << "\nEnter name of employee : ";
        getline(cin, n);
        set_name(n);
        cout << "\nEnter SSN of employee : ";
        getline(cin, s);
        set_ssn(s);
        cout << "\nEnter net pay of employee : ";
        cin >> e;
        set_netpay(e);
        cout << "\nEnter weekly salary of employee :";
        cin >> b;
        set_salary(b);
        cin.ignore();
        cout << "\nEnter title of employee :";
        getline(cin, t);
        title = t;
        cout << "\nEnter area of responsibility of employee :";
        getline(cin, a);
        area = a;
        cout << "\nEnter name of supervisor of employee :";
        getline(cin, s);
        supervisor = s;
    }
    void print()
    {
        cout << "\nThe details of the employee are  : \nName : " << get_name() << "\nTitle : " << title << "\nArea of responsibility : " << area << "\nSupervisor : " << supervisor << "\nNet pay : $" << net_pay << "\nWeekly salary : $" << salary << "\nAnnual salary : $" << (52 * salary);
    }
    void print_check()
    {
        cout << "\n--------------------------------- check printed --------------------------------------------------------------------\nName : " << get_name() << "\nPay : $" << net_pay << "\nWeekly salary : $" << salary << "\nTOTAL ANNUAL SALARY : $" << (salary * 52) << "\n--------------------------------- check printed --------------------------------------------------------------------";
    }
};
int main()
{
    double netPay, salary;
    string name, ssn, title, area, supervisor;
    cout << "\nEnter name of employee : ";
    getline(cin, name);
    cout << "\nEnter SSN of employee : ";
    getline(cin, ssn);
    cout << "\nEnter netpay of employee : ";
    cin >> netPay;
    employee e1(name, ssn, netPay);
    e1.print_check();
    cin.ignore();
    cout << "\n\nEnter details of salaried employee : ";
    cout << "\nEnter name of employee : ";
    getline(cin, name);
    cout << "\nEnter SSN of employee : ";
    getline(cin, ssn);
    cout << "\nEnter netpay of employee : ";
    cin >> netPay;
    cout << "\nEnter salary of employee : ";
    cin >> salary;
    salariedEmployee s1(salary, name, ssn, netPay);
    s1.print_check();
    cin.ignore();
    cout<<"\n\nEnter details of Employee as an administrator :  ";
    administrator a1;
    a1.set_data();
    a1.print();
    a1.print_check();
    return 0;
}