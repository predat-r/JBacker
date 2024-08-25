#include <iostream>
#include <string>
using namespace std;
class rectangle
{
    int length;
    int width;

public:
    rectangle(int a = 0, int b = 0)
    {
        length = a;
        width = b;
    }
    rectangle operator+(rectangle &r2)
    {
        rectangle temp;
        temp.length = length + r2.length;
        temp.width = width + r2.width;
        return temp;
    }
    void display()
    {
        cout << "\n"
             << "the measurements of your rectangle are : " << length << " " << width;
    }
};
int main()
{
    rectangle r1(2, 3);
    rectangle r2(3, 2);
    r1.display();
    r2.display();
    r1 = r1 + r2;
    cout << "\nAddition is done \n";
    r1.display();
    return 0;
}