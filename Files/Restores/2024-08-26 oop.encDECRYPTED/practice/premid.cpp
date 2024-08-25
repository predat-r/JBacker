#include <iostream>
#include <string>
using namespace std;
class rectangle
{
private:
    double width;
    double length;

public:
    void setLength(double);
    void setWidth(double);
    double getLength();
    void getWidth();
};
void rectangle ::setLength(double a)
{
    length = a;
}
void rectangle ::setWidth(double a)
{
    width = a;
}
double rectangle ::getLength()
{
    return length;
}
double rectangle ::getWidth()
{
    return width;
}
