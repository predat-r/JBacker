#include <iostream>
using namespace std;
class Student
{
    string name;
    double cgpa;
    int rollNo;
    int noOfTests;
    int *tests;
    double average;

public:
    Student(string a = "", double b = 0.0, int c = 0, int d = 0, double e = 0)
    {
        name = a;
        cgpa = b;
        rollNo = c;
        noOfTests = d;
        tests = nullptr;
        average = e;
    }
    void setName(string a)
    {
        name = a;
    }
    void setCgpa(double a)
    {
        cgpa = a;
    }
    void setRollno(int a)
    {
        rollNo = a;
    }
    void setNoOftests(int a)
    {
        noOfTests = a;
    }
    void setTests()
    {
        tests = new int[noOfTests];
    }
    void setTestmarks(int n, int i)
    {
        tests[i] = n;
    }

    double getAverage()
    {
        double total = 0;
        for (size_t i = 0; i < noOfTests; i++)
        {
            total += tests[i];
        }
        average = total / noOfTests;
        return average;
    }

    string getName() const
    {
        return name;
    }
    double getCgpa() const
    {
        return cgpa;
    }
    int getRollno() const
    {
        return rollNo;
    }
    int getNoOftests() const
    {
        return noOfTests;
    }
    void display()
    {
        cout << "the information is as follows :\nname :" << getName() << "\nCGPA :" << getCgpa() << "\nRollNo :" << getRollno() << "\nNo Of Tests :" << getNoOftests() << "\ntest marks :";

        for (int i = 0; i < noOfTests; i++)
        {
            cout << tests[i];
            cout << "\t";
        }
        cout << "\n Average test marks are :" << getAverage();
    }
};
void takeInformation(Student *Students, int numOfstudents);
void displayOneStudent(Student *Students, int numOfstudents, int StudentNo);
void displayAllStudents(Student *Students, int numOfstudents);
void findTopper(Student *students, int NoOfstudents);

int main()
{
    int option, NoOfstudents, StudentNo;
    cout << "\nEnter number of students :";
    cin >> NoOfstudents;
    Student *ptr = new Student[NoOfstudents];
    cout << "Select An Option :\n1--Input Information\n2--Display Information of particular student\n3--Display information of all students\n4--Find Topper\n";
    cin >> option;

    switch (option)
    {
    case 1:

        takeInformation(ptr, NoOfstudents);
        break;
    case 2:
        cout << "Enter Student number You want to see information of :";
        cin >> StudentNo;
        displayOneStudent(ptr, NoOfstudents, StudentNo);
        break;
    case 3:
        displayAllStudents(ptr, NoOfstudents);
        break;
    case 4:
        findTopper(ptr, NoOfstudents);
    default:
        break;
    }
}
void takeInformation(Student *Students, int numOfstudents)
{
    string naam;
    double m, n;
    int o, p;
    int marks;
    for (size_t i = 0; i < numOfstudents; i++)
    {

        cout << "\nenter name of student :";
        cin.ignore();
        getline(cin, naam);
        Students[i].setName(naam);
        cout << "\nEnter cgpa of student :";
        cin >> m;
        Students[i].setCgpa(m);
        cout << "\nEnter roll number of student :";
        cin >> o;
        Students[i].setRollno(o);
        cout << "\nenter number of tests :";
        cin >> p;
        Students[i].setNoOftests(p);
        Students[i].setTests();
        for (int z = 0; z < p; z++)
        {
            cout << "\nenter marks of test" << z << " :";
            cin >> marks;
            Students[i].setTestmarks(marks, z);
        }
    }
}
void displayOneStudent(Student *Students, int numOfstudents, int StudentNo)
{
    if (StudentNo > numOfstudents)
    {
        cout << "\nInvalid input, Student number exceeded number of students !";
        return;
    }
    else
    {
        Students[StudentNo].display();
    }
}
void displayAllStudents(Student *Students, int numOfstudents)
{

    for (size_t i = 0; i < numOfstudents; i++)
    {
        Students[i].display();
    }
}
void findTopper(Student *students, int NoOfstudents)
{
    int topper = 0;
    int j = 1;
    int av1, av2;
    for (size_t i = 0; i < NoOfstudents - 1; i++)
    {
        av1 = students[i].getAverage();
        av2 = students[j].getAverage();
        if (av2 > av1)
        {
            topper = j;
        }
        j++;
    }
    cout << "topper is " << topper;
    return;
}