#include <iostream>
#include <string>
using namespace std;
class Account
{
    string accNumber;
    double balance;
    float interestRate;

public:
    Account()
    {
        accNumber = " ";
        balance = 0.0;
        interestRate = 2.3;
    }
    Account(string a, double b = 0.0, float c = 1.23)
    {
        accNumber = a;
        balance = b;
        interestRate = c;
    }
    void witdhraw(double a)
    {
        balance = balance - a;
    }
    void deposit(double a)
    {
        balance = balance + a;
    }
    void setAccNumber(string a)
    {
        accNumber = a;
    }
    void setBalance(double a)
    {
        balance = a;
    }
    void setInterestRate(float a)
    {
        interestRate = a;
    }
    string getAccnumber() const
    {
        return accNumber;
    }
    double getBalance() const
    {
        return balance;
    }
    float getinterestRate() const
    {
        return interestRate;
    }
    virtual double calcRate()
    {

        double a = balance * interestRate;
        return a;
    }
    virtual void display()
    {
        double a;
        float b;
        double c;
        a = getBalance();
        b = getinterestRate();
        c = calcRate();
        cout << "\n\nThe details of your account are as follows : \n";
        cout << "Account number : " << getAccnumber() << "\nBalance : " << a << "Rs" << "\nInterest Rate :" << b << "%\nThe interest Calculated on your acount : " << c;
    }
};
class SavingsAccount : public Account
{

public:
    SavingsAccount()
    {
        setInterestRate(21.1);
    }
    SavingsAccount(string a, float rate = 21.0, double b = 0.0, float c = 0.0) : Account(a, b, c)
    {
        setInterestRate(rate);
    }
    double calcRate() override
    {
        setInterestRate(21.1);
        double a = getBalance() * (getinterestRate());
        return a;
    }
    void display() override
    {
        double a;
        float b;
        double c;
        a = getBalance();
        c = calcRate();
        b = getinterestRate();

        cout << "\n\nThe details of your saving account are as follows : \n";
        cout << "Account number : " << getAccnumber() << "\nBalance : " << a << "Rs" << "\nInterest Rate :" << b << "%\nThe interest Calculated on your acount : " << c;
    }
};
class CheckingAccount : public Account
{
public:
    CheckingAccount()
    {
        setInterestRate(1.1);
    }
    CheckingAccount(string a, float rate = 11.1, double b = 0.0, float c = 0.0) : Account(a, b, c)
    {
        setInterestRate(rate);
    }
    double calcRate() override
    {
        setInterestRate(1.1);
        double a = getBalance() * (getinterestRate());
        return a;
    }
    void display() override
    {
        double a;
        float b;
        double c;
        a = getBalance();
        c = calcRate();
        b = getinterestRate();

        cout << "\n\nThe details of your checking account are as follows : \n";
        cout << "Account number : " << getAccnumber() << "\nBalance : " << a << "Rs" << "\nInterest Rate :" << b << "%\nThe interest Calculated on your acount : " << c;
    }
};

class customer
{
    string ID;
    Account **list;
    int numOfAccounts;

public:
    customer()
    {
        numOfAccounts = 0;
        ID = " ";
        list = new Account *[numOfAccounts];
    }
    customer(string e, int a = 0)
    {
        numOfAccounts = a;
        ID = e;
    }
    void createAccount()
    {
        int choice;
        cout << "\nwhat type of account do u want to create :\n1---Normal account\n2---Savings Account\n3---Checking Account\n";
        cin >> choice;
        if (choice == 1)
        {
            list[numOfAccounts] = new Account(ID);
        }
        else if (choice == 2)
        {
            list[numOfAccounts] = new SavingsAccount(ID);
        }
        else if (choice == 3)
        {
            list[numOfAccounts] = new CheckingAccount(ID);
        }
        numOfAccounts++;
        cout << "\nAccount created successfully !!";
    }
    void deposit()
    {
        int choice;
        cout << "\nwhat type of account do u want to deposit in :\n1---Normal account\n2---Savings Account\n3---Checking Account\n";
        cin >> choice;
        double money;
        bool a = false;
        if (choice == 1)
        {
            for (size_t i = 0; i < numOfAccounts; i++)
            {
                if ((list[i]->getinterestRate()) < 10.0)
                {
                    a = true;
                    cout << "\nHow much money do u want to deposit : \n";
                    cin >> money;
                    list[i]->deposit(money);
                }
            }
            if (a == true)
            {
                cout << "\nDone";
            }
            else
            {
                cout << " \nYou dont have this type of account  ";
            }
        }
        else if (choice == 2)
        {
            for (size_t i = 0; i < numOfAccounts; i++)
            {
                if ((list[i]->getinterestRate()) > 20.0)
                {
                    a = true;
                    cout << "\nHow much money do u want to deposit : \n";
                    cin >> money;
                    list[i]->deposit(money);
                }
            }
            if (a == true)
            {
                cout << "\nDone";
            }
            else
            {
                cout << " \nYou dont have this type of account  ";
            }
        }
        else if (choice == 3)
        {
            for (size_t i = 0; i < numOfAccounts; i++)
            {
                if (((list[i]->getinterestRate()) > 10.0) && ((list[i]->getinterestRate()) < 20.0))
                {
                    a = true;
                    cout << "\nHow much money do u want to deposit : \n";
                    cin >> money;
                    list[i]->deposit(money);
                }
            }
            if (a == true)
            {
                cout << "\nDone";
            }
            else
            {
                cout << " \nYou dont have this type of account  ";
            }
        }
    }
    void withdraw()
    {
        int choice;
        cout << "\nwhat type of account do u want to deposit in :\n1---Normal account\n2---Savings Account\n3---Checking Account\n";
        cin >> choice;
        double money;
        bool a = false;
        if (choice == 1)
        {
            for (size_t i = 0; i < numOfAccounts; i++)
            {
                if ((list[i]->getinterestRate()) < 10.0)
                {
                    a = true;
                    cout << "\nHow much money do u want to withdraw : \n";
                    cin >> money;
                    list[i]->deposit(money);
                }
            }
            if (a == true)
            {
                cout << "\nDone";
            }
            else
            {
                cout << " \nYou dont have this type of account  ";
            }
        }
        else if (choice == 2)
        {
            for (size_t i = 0; i < numOfAccounts; i++)
            {
                if ((list[i]->getinterestRate()) > 20.0)
                {
                    a = true;
                    cout << "\nHow much money do u want to withdraw : \n";
                    cin >> money;
                    list[i]->deposit(money);
                }
            }
            if (a == true)
            {
                cout << "\nDone";
            }
            else
            {
                cout << " \nYou dont have this type of account  ";
            }
        }
        else if (choice == 3)
        {
            for (size_t i = 0; i < numOfAccounts; i++)
            {
                if (((list[i]->getinterestRate()) < 20.0) && ((list[i]->getinterestRate()) < 20.0))
                {
                    a = true;
                    cout << "\nHow much money do u want to withdraw : \n";
                    cin >> money;
                    list[i]->deposit(money);
                }
            }
            if (a == true)
            {
                cout << "\nDone";
            }
            else
            {
                cout << " \nYou dont have this type of account  ";
            }
        }
    }
    void displayInfo()
    {
        cout << "\nThe ID of customer is : " << ID;

        if (numOfAccounts < 1)
        {
            cout << "\nUser has no accounts to his name ";
            return;
        }

        cout << "\nUser has " << numOfAccounts << " accounts to his name \n\n";
    }
    void displayAccounts()
    {

        if (numOfAccounts < 1)
        {
            cout << "\nUser has no accounts to his name ";
            return;
        }
        cout << "\nUser has " << numOfAccounts << " accounts to his name ";
        cout << "The details of the accounts are : ";
        for (int i = 0; i < numOfAccounts; i++)
        {
            list[i]->display();
        }
    }
    ~customer()
    {
        if (list != nullptr)
        {
            for (size_t i = 0; i < numOfAccounts; i++)
            {  
                delete[] list[i];
            }
        }
        delete[] list;
    }
};

int main()
{
    customer c2("B24");
    c2.createAccount();
    c2.deposit();
    c2.displayInfo();
    c2.displayAccounts();

    return 0;
}