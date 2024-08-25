#include <iostream>
#include <string>
using namespace std;
class square
{
    int side;
    friend class rectangle;

public:
};
class rectangle

{
    int height, width;
    friend class square;

public:
    int area(const square &sqr)
    {
        int area = sqr.side * sqr.side;
    }
};
int main()
{

    return 0;
}