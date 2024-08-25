#include <iostream>
#include <string>
using namespace std;
class IntArray
{
    int size;
    int *arr;

public:
    IntArray()
    {
        size = 0;
        arr = nullptr;
    }
    IntArray(int x = 0)
    {

        size = x;
        arr = new int[size];
        for (size_t i = 0; i < size; i++)
        {
            arr[i] = 0;
        }
    }
    IntArray(const IntArray &array)
    {
        this->size = array.size;
        this->arr = new int[size];
        for (size_t i = 0; i < size; i++)
        {
            this->arr[i] = array.arr[i];
        }
    }
    void setSize(int x)
    {
        size = x;
        arr = new int[size];
        for (size_t i = 0; i < size; i++)
        {
            arr[i] = 0;
        }
    }
    int getSize() const
    {
        return size;
    }
    void setValue(int index, int value)
    {

        arr[index] = value;
    }
    int getValue(int index) const
    {
        return arr[index];
    }

    IntArray addArrays(const IntArray array2) const
    {

        IntArray sum(*this);
        for (size_t i = 0; i < size; i++)
        {
            sum.arr[i] += array2.arr[i];
        }
        return sum;
    }
    IntArray subArrays(const IntArray array2) const
    {

        IntArray sub(*this);
        for (size_t i = 0; i < size; i++)
        {
            sub.arr[i] -= array2.arr[i];
        }
        return sub;
    }
    IntArray mulArray(const IntArray array2) const
    {

        IntArray mul(*this);
        for (size_t i = 0; i < size; i++)
        {
            mul.arr[i] *= array2.arr[i];
        }
        return mul;
    }
    bool palindrome() const
    {
        IntArray rev(*this);
        int j = rev.size - 1;
        for (int i = 0; i < size; i++)
        {
            if (this->arr[i] != rev.arr[j])
            {
                return false;
            }
            j--;
        }
        return true;
    }
    IntArray reverse() const
    {
        IntArray rev(this->size);
        int j = size - 1;
        for (size_t i = 0; i < size; i++)
        {
            rev.arr[i] = this->arr[j];
            j--;
        }
        return rev;
    }
    IntArray cyclicRotate(int n) const
    {
        if (n > size)
        {
            n = n - size;
        }

        IntArray rot(this->size);
        int j = size - n;
        for (size_t i = 0; i < n; i++)
        {
            rot.arr[i] = this->arr[j];
            j++;
        }
        j = 0;
        for (size_t i = n; i < size; i++)
        {
            rot.arr[i] = this->arr[j];
            j++;
        }

        return rot;
    }
    void display() const
    {
        cout << "\nYour Array is :\n";

        for (size_t i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
    }

    ~IntArray()
    {
        delete[] arr;
        arr = nullptr;
    }
};
void arrayInput(IntArray &array, int size);
int main()
{

    int size = 0;
    cout << "Welcome\n";
    cout << "Enter Size of Array :\n";
    cin >> size;
    IntArray array1(size);

    int option = 0;
    do
    {

        cout << "\n1--Enter values in array\n2--display array\n3--get size of array\n4--Add an array to your array\n5--Subtract an array from your array\n6--Multiply an array to your array\n7--Check if your array is a palindrome\n8--Reverse your array\n9--Rotate your array\n10--Exit program\n\n";
        cin >> option;
        if (option < 1 || option > 10)
        {
            cout << "\nEnter a correct value\n";
            cin >> option;
        }

        if (option == 1)
        {
            arrayInput(array1, size);
        }
        if (option == 2)
        {
            array1.display();
        }
        if (option == 3)
        {
            int x = array1.getSize();
            cout << "\nThe size of your array is :\n";
            cout << x;
        }
        if (option == 4)
        {
            int size2 = 0;
            cout << "Enter size of second array (Must be same as size of original array)\n";
            cin >> size2;
            if (size2 != size)
            {
                cout << "\nNot possible, size of both arrays must be same\n";
            }
            else
            {

                IntArray array2(size2);
                arrayInput(array2, size2);
                IntArray sum(array1.addArrays(array2));
                cout << "The sum of your arrays is :\n";
                sum.display();
            }
        }
        if (option == 5)
        {
            int size2 = 0;
            cout << "Enter size of second array (Must be same as size of original array)\n";
            cin >> size2;
            if (size2 != size)
            {
                cout << "\nNot possible, size of both arrays must be same\n";
            }
            else
            {

                IntArray array2(size2);
                arrayInput(array2, size2);
                IntArray sub(array1.subArrays(array2));
                cout << "The subtraction of your arrays is :\n";
                sub.display();
            }
        }
        if (option == 6)
        {
            int size2 = 0;
            cout << "\nEnter size of second array (Must be same as size of original array)\n";
            cin >> size2;
            if (size2 != size)
            {
                cout << "\nNot possible, size of both arrays must be same\n";
            }
            else
            {

                IntArray array2(size2);
                arrayInput(array2, size2);
                IntArray mul(array1.mulArray(array2));
                cout << "The product of your arrays is :\n";
                mul.display();
            }
        }
        if (option == 7)
        {
            if (array1.palindrome() == false)
            {
                cout << "\nYour array is not a palindrome\n";
            }
            else if (array1.palindrome() == true)
            {
                cout << "\nYour array is a palindrome\n";
            }
        }
        if (option == 8)
        {
            IntArray rev(array1.reverse());
            cout << "\nThe reverse of your array is : ";
            rev.display();
        }
        if (option == 9)
        {
            int rotate = 0;
            cout << "\nEnter the value of rotation :\n ";
            cin >> rotate;
            IntArray rot(array1.cyclicRotate(rotate));
            cout << "\nThe rotated array is :\n";
            rot.display();
        }

    } while (option != 10);
}
void arrayInput(IntArray &array, int size)
{

    int x = 0;
    for (size_t i = 0; i < size; i++)
    {

        cout << "\nEnter value at index " << i << "\n";
        cin >> x;
        array.setValue(i, x);
    }
}