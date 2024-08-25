#include <iostream>
#include <string>
using namespace std;
class bankDetails
{
    double accountNumber;
    string Name;
    double balance;

public:
    void setBalance(double a)
    {
        balance = a;
    }
    void setName(string a)
    {

        Name = a;
    }
    void setAccnumber(double a)
    {
        accountNumber = a;
    }
    double getAccnumber()
    {
        return accountNumber;
    }
    double getBalance()
    {
        return balance;
    }
    string getName()
    {
        return Name;
    }

    void displayAccountInfo()
    {
        cout <<"the details of your account are as under:\n\nAccount number : " << getAccnumber() <<"\nAccount holder's name :" << getName() <<"\nBalance in account : "<< getBalance()<<"$";
    }
    void withdraw(int a)
    {
        if (balance - a >= 0)
        {
            balance = balance - a;
            cout <<"\nBalance withdrawn successfully \nYour new balance is :" << getBalance();
        }
        else
        {
            cout <<"\nWitdraw attempt failed\nnot enough balance !";
        }
    }
    void deposit(int a)
    {
        balance = balance + a;
        cout <<"\nDeposit successful\nYour new balance is :" << getBalance();
    }
};
int main()
{
    bankDetails acc1, acc2;
    acc1.setAccnumber(125369);
    acc1.setBalance(1001);
    acc1.setName("haris naeem");
    acc1.displayAccountInfo();
    cout << "\n\n";
    acc1.withdraw(500);
    cout << "\n\n";

    acc1.deposit(300);
    cout << "\n\n";

    acc1.withdraw(2000);
    cout << "\n\n";
    acc1.displayAccountInfo();
}