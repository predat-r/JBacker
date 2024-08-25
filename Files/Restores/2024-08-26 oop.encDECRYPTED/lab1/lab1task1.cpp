#include <iostream>
#include <string>
using namespace std;
class student
{
    int rollNumber;
    string name;
    string address;
    string phoneNumber;
    char Grade;

public:
    student()
    {
        rollNumber = 0;
        name = "";
        address = "";
        phoneNumber = 0.0;
        Grade = 'a';
    }
    void setRollnum(int a)
    {
        rollNumber = a;
    }
    void setName(string a)
    {

        name = a;
    }
    void setAddress(string a)
    {
        address = a;
    }
    void setPhonenum(string a)
    {
        phoneNumber = a;
    }
    void setGrade(char a)
    {
        Grade = a;
    }
    string getName()
    {
        return name;
    }
    string getAddress()
    {
        return address;
    }
    int getRollnum() const
    {
        return rollNumber;
    }
    string getPhone()
    {
        return phoneNumber;
    }
    char getGrade()
    {
        return Grade;
    }
    void displayStudentInfo() 
    {

        cout << "the details of the student are :\nName = " << getName() << "\nRollnumber = " << rollNumber << "\nName = " << getName() << "\nAddress = " << getAddress() << "\nGrade = " << getGrade() << "\nphone number = " << getPhone();
    }
};
int main()
{
    student std1, std2;
    double ph1 ;
    std1.setAddress("78 khurram block canal bank scheme harbanspura lahore");
    std1.setGrade('A');
    std1.setName("haris naeem");
    std1.setRollnum(024);
    std1.setPhonenum("03004043122");
    std2.setAddress("32-B dharamapura");
    std2.setGrade('B');
    std2.setName("bilal ahmar");
    std2.setRollnum(022);
    std2.setPhonenum("54");
    std1.displayStudentInfo();
    std2.displayStudentInfo();
}