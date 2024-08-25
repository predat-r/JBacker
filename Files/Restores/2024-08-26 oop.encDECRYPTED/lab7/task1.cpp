#include <iostream>
#include <string>
#include <cstdlib>
#include <time.h>

using namespace std;

class objectTracker
{
private:
    static int counter;

public:
    objectTracker()
    {
        counter++;
    }

    ~objectTracker()
    {
        counter--;
    }
    static int getcount()
    {
        return counter;
    }
};
int objectTracker ::counter = 0;

main()
{
    srand(time(NULL));
    int size = rand() % 20 + 1;
    objectTracker **arr = new objectTracker *[size];
    for (size_t i = 0; i < size; i++)
    {

        arr[i] = new objectTracker;
    }
    int temp = arr[0]->getcount();
    cout << "\nThe number of objects at this time is :\n"
         << temp;
    int deSize = rand() % size + 1;
    for (size_t i = 0; i < deSize; i++)
    {
        delete arr[i];
    }
    temp = arr[0]->getcount();
    cout << "\nThe number of objects at this time is :\n"
         << temp;

    return 0;
}