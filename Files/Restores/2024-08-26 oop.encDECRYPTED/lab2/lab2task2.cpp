#include <iostream>
#include <string>
using namespace std;
class Circle
{
    double radius;
    double pi = 3.14159;

public:
    Circle()
    {
        radius = 0.0;
    }
    Circle(double a)
    {
        radius = a;
    }
    void setRadius(double a)
    {
        radius = a;
    }
    double getRadius()const
    {
        return radius;
    }
    double getArea()const
    {

        return (pi * radius * radius);
    }
    double getDiameter()
    {   double diameter = (radius * 2);
        return diameter;
    }
    double getCircumference()const
    {
        return (2 * pi * radius);
    }
    void displayProperties()const
    {
        cout << "Area  : " << getArea() << "\nDiameter  : " << getDiameter() << "\nCircumference  : " << getCircumference();
    }
};
int main()
{
    Circle c1;
    int radius1,radius2;
    cout << "enter Radius :";
    cin >> radius1;
    c1.setRadius(radius1);
    c1.displayProperties();
    cout<<"\nenter radius for creating object:\n";
    cin>>radius2;
    Circle c2(radius2);
    c2.displayProperties();
}