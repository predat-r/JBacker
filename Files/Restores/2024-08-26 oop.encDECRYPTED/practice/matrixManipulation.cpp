#include <iostream>
#include <string>
using namespace std;
int numberValidation(int number)
{
    bool validInput = false;
    while (!validInput)
    {
        if (cin >> number)
        {
            if (number < 0)
            {
                cout << "Enter positive number: " << endl;
            }
            else
            {
                validInput = true;
            }
        }
        else
        {
            cin.clear();
            while (cin.get() != '\n')
                ;
            cout << "Invalid input. Please enter a valid number." << endl;
        }
    }
    return number;
}
class MyString
{
    int length;
    char *ptr;

public:
    MyString();
    MyString(int);
    MyString(const MyString &orig)
    {
        // copy constructor
        length = orig.length;
        ptr = new char[length + 1];
        for (int i = 0; i <= length; i++)
        {
            ptr[i] = orig.ptr[i];
        }
    }

    // setters
    void setLength(int l)
    {
        length = l;
    }
    void setData(char *c)
    {
        ptr = new char[length + 1];
        for (int i = 0; i <= length; i++)
        {
            ptr[i] = c[i];
        }
    }

    // getters
    int getLength() const
    {
        return length;
    }
    char *getData() const
    {
        return ptr;
    }
    void inputValue();
    void display();
    char getValue(int);
    void setValue(int, char);
    void concatenateString(const MyString &, int);
    void subString(int, int, int);
    void copyString(const MyString &);
    void upperCase();
    void lowerCase();
    void properCase();
    void toSentence();
    MyString sentence() const;
    void toReverse();
    MyString reverse() const;
    ~MyString();
};
MyString::MyString()
{
    length = 0;
    ptr = nullptr;
}
MyString::MyString(int l)
{
    length = l;
    ptr = new char[length + 1];
}
MyString ::~MyString()
{
    if (ptr != nullptr)
    {
        delete[] ptr;
        ptr = nullptr;
    }
}
void MyString::inputValue()
{
    int i;
    string ch;
a:
    cout << "Enter name:\n";
    cin.ignore();
    getline(cin, ch);
    if (ch.size() + 1 != length + 1)
    {
        cout << "The name entered is not of specified size\n";
        goto a;
    }
    for (i = 0; i < length; i++)
    {
        ptr[i] = ch[i];
    }
    ptr[i] = '\0';
}
void MyString::display()
{
    for (int i = 0; ptr[i] != '\0'; i++)
    {
        cout << ptr[i];
    }
}
char MyString::getValue(int index)
{
    return ptr[index];
}
void MyString::setValue(int index, char value)
{
    for (int i = 0; ptr[i] != '\0'; i++)
    {
        if (index == i)
        {
            ptr[i] = value;
        }
    }
}
void MyString::concatenateString(const MyString &other, int extra)
{
    int j, i;
    char *newptr = new char[length + extra + 1 + 1];
    for (i = 0; ptr[i] != '\0'; i++)
    {
        newptr[i] = ptr[i];
    }
    newptr[i] = ' ';
    i++;
    for (j = 0; other.ptr[j] != '\0' && i < length + extra + 1; j++, i++)
    {
        newptr[i] = other.ptr[j];
    }
    newptr[i] = '\0';
    for (i = 0; newptr[i] != '\0'; i++)
    {
        cout << newptr[i];
    }
    delete[] ptr;
    ptr = nullptr;
    cout << endl;
}

void MyString::subString(int start, int end, int length)
{
    int j = 0;
    char *newptr = new char[length - (end - start) + 1];
    for (int i = start; i <= end; i++)
    {
        newptr[j] = ptr[i];
        j++;
    }
    newptr[j] = '\0';
    for (int i = 0; newptr[i] != '\0'; i++)
    {
        cout << newptr[i];
    }

    delete[] ptr;
    ptr = nullptr;
}
void MyString ::copyString(const MyString &other)
{
    length = other.length;
    ptr = new char[length + 1];
    for (int i = 0; i <= length; i++)
    {
        ptr[i] = other.ptr[i];
    }
}
void MyString::upperCase()
{
    for (int i = 0; ptr[i] != '\0'; i++)
    {
        if (ptr[i] >= 97 && ptr[i] <= 122)
        {
            ptr[i] = ptr[i] - 32;
        }
    }
}
void MyString::lowerCase()
{
    for (int i = 0; ptr[i] != '\0'; i++)
    {
        if (ptr[i] >= 65 && ptr[i] <= 90)
        {
            ptr[i] = ptr[i] + 32;
        }
    }
}
void MyString::properCase()
{
    if (ptr[0] != ' ')
    {
        if (ptr[0] >= 97 && ptr[0] <= 122)
        {
            ptr[0] = ptr[0] - 32;
        }
    }
    else if (ptr[0] == ' ')
    {
        if (ptr[0 + 1] >= 97 && ptr[0 + 1] <= 122)
        {
            ptr[0 + 1] = ptr[0 + 1] - 32;
        }
    }

    for (int i = 0; ptr[i] != '\0'; i++)
    {
        if (ptr[i] == ' ')
        {
            if (ptr[i + 1] >= 97 && ptr[i + 1] <= 122)
            {
                ptr[i + 1] = ptr[i + 1] - 32;
            }
        }
    }
}
void MyString::toSentence()
{
    if (ptr[0] != ' ')
    {
        if (ptr[0] >= 97 && ptr[0] <= 122)
        {
            ptr[0] = ptr[0] - 32;
        }
    }
    for (int i = 0; ptr[i] != '\0'; i++)
    {
        if (ptr[i] == ' ' && ptr[i + 1] != ' ')
        {
            ptr[i + 1] = ptr[i + 1] - 32;
            break;
        }
    }
}
MyString MyString::sentence() const
{
    MyString temp(length);
    for (int i = 0; ptr[i] != '\0'; i++)
    {
        temp.ptr[i] = ptr[i];
    }
    if (temp.ptr[0] != ' ')
    {
        if (temp.ptr[0] >= 97 && temp.ptr[0] <= 122)
        {
            temp.ptr[0] = temp.ptr[0] - 32;
        }
    }
    for (int i = 0; temp.ptr[i] != '\0'; i++)
    {
        if (temp.ptr[i] == ' ' && temp.ptr[i + 1] != ' ')
        {
            temp.ptr[i + 1] = temp.ptr[i + 1] - 32;
            break;
        }
    }
    temp.ptr[length] = '\0';
    return temp;
}
void MyString::toReverse()
{
    int i, j;
    for (i = 0, j = length - 1; i < j; i++, j--)
    {
        char temp = ptr[i];
        ptr[i] = ptr[j];
        ptr[j] = temp;
    }
}
MyString MyString::reverse() const
{
    MyString temp(length);
    for (int i = 0; i <= length; i++)
    {
        temp.ptr[i] = ptr[i];
    }
    int i, j;
    for (i = 0, j = length - 1; i < j; i++, j--)
    {
        char hold = temp.ptr[i];
        temp.ptr[i] = temp.ptr[j];
        temp.ptr[j] = hold;
    }
    temp.ptr[length] = '\0';
    return temp;
}
int main()
{
    int length, choice, index, length2, start, end;
    char value;

    cout << "Enter the length of string\n";
    length = numberValidation(length);
    MyString s1(length);
    s1.inputValue();
    s1.display();
    do
    {
        cout << endl;
        cout << "-------------------\n";
        cout << "What operation do you want to perform\n";
        cout << "1-Get Character\n"
             << "2-Set Character\n"
             << "3-Cancatenate String\n"
             << "4-Extract Substring\n"
             << "5-Copy String\n"
             << "6-UpperCase String\n"
             << "7-LowerCase String\n"
             << "8-ProperCase String\n"
             << "9-SentenceCase String\n"
             << "10-Reverse String\n";
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            cout << "Enter the index at which you want to get character\n(Index starting from zero)\n";
            index = numberValidation(index);
            value = s1.getValue(index);
            cout << value;
            break;
        }
        case 2:
        {
            cout << "Enter the index at which you want to get character\n(Index starting from zero)\n";
            index = numberValidation(index);
            cout << "Enter the character you want to set\n";
            cin >> value;
            s1.setValue(index, value);
            s1.display();
            break;
        }
        case 3:
        {
            cout << "Enter the length of string you want to add\n";
            length2 = numberValidation(length2);
            MyString s2(length2);
            s2.inputValue();
            s1.concatenateString(s2, length2);
            break;
        }
        case 4:
        {
            cout << "Enter the starting index of substring\n(Index starting from zero)";
            start = numberValidation(start);
            cout << "Enter the ending index of substring\n";
            end = numberValidation(end);
            s1.subString(start, end, length);
            break;
        }
        case 5:
        {
            MyString s3;
            s3.copyString(s1);
            cout << "String copied to other object\n ";
            s3.display();
            break;
        }
        case 6:
        {
            s1.upperCase();
            s1.display();
            break;
        }
        case 7:
        {
            s1.lowerCase();
            s1.display();
            break;
        }
        case 8:
        {
            s1.properCase();
            s1.display();
            break;
        }

        case 9:
        {
            cout << "Sentence case is: " << endl;
            cout << "1. without modifying" << endl
                 << "2. modifying string" << endl
                 << "-----------------" << endl;
            int n;
            cin >> n;
            if (n == 1)
            {
                MyString sentenced(s1.sentence());
                sentenced.display();
            }
            else if (n == 2)
            {
                s1.toSentence();
                s1.display();
            }
            else
            {
                cout << "Error\n";
            }
            break;
        }
        case 10:
        {
            cout << "1. without modifying" << endl
                 << "2. modifying string" << endl
                 << "-----------------" << endl;
            int op;
            cin >> op;
            if (op == 1)
            {
                MyString reversed(s1.reverse());
                reversed.display();
            }
            else if (op == 2)
            {
                s1.toReverse();
                s1.display();
            }
            else
            {
                cout << "Error\n";
            }
            break;
        }
        case 11:
        {
            cout << "Exiting..." << endl;
            return 0;
        }
        default:
        {
            cout << "ERROR: Invalid option" << endl;
            break;
        }
        }
    } while (1);
    return 0;
}