#include <iostream>
#include <string>
using namespace std;
static int sentinel = -999;
class intArray
{
    int *aptr;
    int arraySize;

public:
    intArray(int s = 0)
    {
        arraySize = s;
        aptr = new int[arraySize];
        for (size_t i = 0; i < arraySize; i++)
        {
            aptr[i] = 0;
        }
    }
    void arrayInput()
    {
        for (size_t i = 0; i < arraySize; i++)
        {
            cout << "\nEnter value at index " << i << ": ";
            cin >> aptr[i];
        }
    }
    int getValue(int index) const
    {
        return aptr[index];
    }
    void setValue(int value, int index)
    {
        aptr[index] = value;
    }
    int setSize(int s)
    {
        arraySize = s;
    }
    int getSize() const
    {
        return arraySize;
        for (size_t i = 0; i < arraySize; i++)
        {
            aptr[i] = 0;
        }
    }
    void display()
    {
        cout << "\nYour array is : ";
        int temp;
        for (size_t i = 0; i < arraySize; i++)
        {
            temp = getValue(i);
            cout << temp;
        }
    }
    int &operator[](int index)
    {
        if (index >= arraySize)
        {
            cout << "\nout of bounds\n";
            return sentinel;
        }
        else
        {
            return aptr[index];
        }
    }
    intArray &operator+=(intArray &second)
    {
        int *final = new int[this->arraySize + second.arraySize];
        for (size_t i = 0; i < this->arraySize; i++)
        {
            final[i] = this->aptr[i];
        }
        int j = 0;
        for (int i = this->arraySize; i < this->arraySize + second.arraySize; i++)
        {
            final[i] = second[j];
            j++;
        }
        delete this->aptr;
        this->arraySize = arraySize + second.arraySize;
        this->aptr = final;
        return *this;
    }
    void operator=(intArray &second)
    {
        this->arraySize = second.arraySize;
        for (size_t i = 0; i < arraySize; i++)
        {
            this->aptr[i] = second[i];
        }
    }

    ~intArray()
    {
        if (aptr != nullptr)
        {
            delete[] aptr;
        }
    }
};
int main()
{
    intArray ar1(5);
    intArray ar2(3);
    ar1.arrayInput();
    ar1.display();
    ar2.arrayInput();
    ar2.display();
    ar1 += ar2;
    ar1.display();
    ar1 = ar2;
    ar1.display();

    return 0;
}