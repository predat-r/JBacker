#include <iostream>
#include <string>
#include <fstream>
using namespace std;
class student
{
public:
    string name;
    int rollNo;
    char grade;
    student()
    {

        name = "";
        rollNo = 0;
        grade = ' ';
    }
    void setname(string a)
    {
        name = a;
    }
    void setrollno(int a)
    {
        rollNo = a;
    }
    void setgrade(char a)
    {
        grade = a;
    }
    void writeTofile(ofstream &file)
    {
        file << name << "\t" << rollNo << "\t" << grade << "\n";
    }
    void readFromfile(ifstream &file)
    {
        file >> name >> rollNo >> grade;
    }
    void display()
    {
        cout << "details are :\n"
             << name << "\n"
             << rollNo << "\n"
             << grade << "\n";
    }
};
int main()
{
    student s1;
    s1.name = "haris";
    s1.rollNo = 54;
    s1.grade = 'c';
    ofstream ofile("student.txt");
    s1.writeTofile(ofile);
    ofile.close();
    ifstream infile("student.txt");
    s1.readFromfile(infile);
    s1.display();
}