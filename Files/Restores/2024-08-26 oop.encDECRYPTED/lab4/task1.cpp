#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
const int c1 = 31;
const int c2 = 41;
class employee
{

    int ID;
    char Name[c1];
    char DeptName[c2];

public:
    employee()
    {
        ID = 0;
        for (size_t i = 0; i < c1; i++)
        {
            Name[i] = ' ';
        }
        for (size_t i = 0; i < c2; i++)
        {
            DeptName[i] = ' ';
        }
    }
    employee(int a, char *n, char *d)
    {
        ID = a;
        strcpy(Name, n);
        strcpy(DeptName, d);
    }
    void setId(int a)
    {
        ID = a;
    }
    void setName(char *a)
    {
        strcpy(Name, a);
    }
    void setDeptname(char *b)
    {
        strcpy(DeptName, b);
    }
    int getId() const
    {
        return ID;
    }
    const char *getName() const
    {
        return Name;
    }
    const char *getDeptname() const
    {
        return DeptName;
    }
    void storeinfile(ofstream &file)
    {
        file << ID << "\t" << Name << "\t" << DeptName << "\n";
    }
    void readFromfile(ifstream &file)
    {
        file >> ID >> Name >> DeptName;
    }
    void display() const
    {
        cout << "Details of the employee are :\nEmployee ID :" << getId();
        cout << "\nEmployee name :" << getName() << "\nEmployee Department :" << getDeptname() << "\n";
    }
    ~employee()
    {
    }
};
int main()
{
    int size = 0;
    cout << "\nEnter the number of employees : ";
    cin >> size;
    employee *emp = new employee[size];

    for (size_t i = 0; i < size; i++)
    {
        int n;
        string a;
        char A[31];
        char B[41];
        cout << "Enter ID : ";
        cin >> n;
        emp[i].setId(n);
        cout << "\nEnter Name :";
        cin.ignore();
        cin.getline(A, c1);
        emp[i].setName(A);
        cout << "\nEnter Department name :";
        cin.getline(B, c2);
        emp[i].setDeptname(B);
    }
    for (size_t i = 0; i < size; i++)
    {
        emp[i].display();
    }
    ofstream outfile("emps.txt");
    for (size_t i = 0; i < size; i++)
    {
        emp[i].storeinfile(outfile);
    }
    outfile.close();
    cout << "\n\nDeallocating memory \n";
    delete[] emp; // deallocatign memory after storing it in a file
    emp = nullptr;
    cout << "employees read from file : \n\n";
    int NoOfEmployees = 0;
    employee *emps = new employee[NoOfEmployees];
    ifstream infile("emps.txt");
    while (!infile.eof())
    {
        emps[NoOfEmployees].readFromfile(infile);
        NoOfEmployees++;
    }
    infile.close();
    NoOfEmployees--;

    for (size_t i = 0; i < NoOfEmployees; i++)
    {
        emps[i].display();
    }
    delete[] emps;
    emps = nullptr;
}