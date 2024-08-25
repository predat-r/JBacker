#include <iostream>
#include <string>
#include <limits>
using namespace std;
class Mystring
{
    int length;
    char *data;

public:
    Mystring(int x = 0)
    {
        length = x;
        data = new char[length];
        for (size_t i = 0; i < length; i++)
        {
            data[i] = ' ';
        }
        data[length + 1] = '\0';
    }
    Mystring(const Mystring &str)
    {
        this->length = str.length;
        this->data = new char[length + 1];
        for (size_t i = 0; i < length; i++)
        {
            this->data[i] = str.data[i];
        }
        this->data[length + 1] = '\0';
    }
    void setLength(int a)
    {
        length = a;
        int res;
        for (size_t i = 0; i < length; i++)
        {
            if (data[i] == '\0')
            {
                res = i;
            }
        }
        for (size_t i = res; i < length; i++)
        {
            data[i] = ' ';
        }
    }
    int getLength()
    {
        return length;
    }

    void inputValues()
    {
        cout << "\nEnter string :\n";
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear input buffer
        cin.getline(data, length + 1);
        return;
    }

    void concatenate(const Mystring &str)
    {

        for (size_t i = 0; str.data[i] != '\0'; i++)
        {

            this->data[length - 1] = str.data[i];
            length++;
        }
        this->data[length - 1] = '\0';
    }
    Mystring substring(int start, int leng)
    {
        Mystring subStr(leng + 1);
        int index = 0;
        for (size_t i = start; i < length; i++)
        {
            subStr.data[index] = this->data[i];
            index++;
        }
        subStr.data[length - 1] = '\0';
        return subStr;
    }
    void show()
    {

        cout << "\nYour string is :\n";
        for (size_t i = 0; i < length; i++)
        {

            cout << data[i];
        }
    }
    const char getValue(int a)
    {
        return data[a];
    }
    void setValue(int a, char b)
    {
        if (a > length)
        {
            return;
        }

        data[a] = b;
    }
    void copyString(const Mystring &str)
    {
        this->length = str.length;
        for (size_t i = 0; i <= length; i++)
        {
            this->data[i] = str.data[i];
        }
    }
    void toUpper()
    {
        char *arr = new char[26]; // creating an array where ill keep ascii values of uppercase chars
        int start = 65;
        int temp;
        for (size_t i = 0; i < 26; i++)
        {
            arr[i] = start; // putting the values
            start++;
        }
        for (size_t i = 0; i < length; i++)
        {
            if (this->data[i] < 97 || this->data[i] > 122)
            {
                continue;
            }

            temp = this->data[i];
            temp = temp - 97; // so they start from index zero now 'a' will put 0 in temp
            for (size_t j = 0; j < 26; j++)
            {
                if (temp == j)
                {

                    this->data[i] = arr[j]; // putting the approproiate uppercase character in place of the lowercase one
                }
            }
        }

        delete[] arr;
    }
    void toLower()
    {
        char *arr = new char[26]; // creating an array where ill keep ascii values of lowercase chars
        int start = 97;
        int temp;
        for (size_t i = 0; i < 26; i++)
        {
            arr[i] = start; // putting the values
            start++;
        }
        for (size_t i = 0; i < length; i++)
        {
            if (this->data[i] < 65 || this->data[i] > 90)
            {
                continue;
            }

            temp = this->data[i];
            temp = temp - 65; // so they start from index zero now 'A' will put 0 in temp
            for (size_t j = 0; j < 26; j++)
            {
                if (temp == j)
                {

                    this->data[i] = arr[j]; // putting the approproiate lowercase character in place of the lowercase one
                }
            }
        }

        delete[] arr;
    }
    void toProper()
    {
        char *arr = new char[26]; // creating an array where ill keep ascii values of uppercase chars
        int start = 65;
        int temp;
        for (size_t i = 0; i < 26; i++)
        {
            arr[i] = start; // putting the values
            start++;
        }
        for (size_t i = 0; i < length - 1; i++)
        {
            if (i == 0)
            {
                temp = this->data[i];
                temp = temp - 97; // so they start from index zero now 'a' will put 0 in temp
                for (size_t j = 0; j < 26; j++)
                {
                    if (temp == j)
                    {

                        this->data[i] = arr[j]; // putting the approproiate uppercase character in place of the lowercase one
                    }
                }
            }

            if (data[i] == ' ')
            {

                temp = this->data[i + 1];
                temp = temp - 97; // so they start from index zero now 'a' will put 0 in temp
                for (size_t j = 0; j < 26; j++)
                {
                    if (temp == j)
                    {

                        this->data[i + 1] = arr[j]; // putting the approproiate uppercase character in place of the lowercase one
                    }
                }
            }
        }
        delete[] arr;
    }
    void toSentence()
    {
        char *arr = new char[26]; // creating an array where ill keep ascii values of uppercase chars
        int start = 65;
        int temp;
        for (size_t i = 0; i < 26; i++)
        {
            arr[i] = start; // putting the values
            start++;
        }
        temp = this->data[0];
        temp = temp - 97; // so they start from index zero now 'a' will put 0 in temp
        for (size_t j = 0; j < 26; j++)
        {
            if (temp == j)
            {

                this->data[0] = arr[j]; // putting the approproiate uppercase character in place of the lowercase one
            }
        }
        delete[] arr;
    }
    Mystring sentence()
    {
        Mystring sent(*this);
        sent.toSentence();
        return sent;
    }
    void toReverse()
    {
        Mystring *rev = new Mystring(this->length);
        size_t i = length - 1;

        // Find the index of the last non-space character
        for (;; i--)
        {
            if (data[i] != ' ' || i == 0)
            {
                break; // Stop if non-space character is found or reached the beginning of the string
            }
        }
        size_t j = i - 1;
        for (size_t k = 0; k <= i; k++)
        {
            rev->data[k] = this->data[j];
            j--;
        }
        for (size_t l = 0; l < i; l++)
        {
            this->data[l] = rev->data[l];
        }
        delete rev;
    }

    Mystring Reverse()
    {
        Mystring reverse(*this);
        reverse.toReverse();
        return reverse;
    }
    ~Mystring()
    {
        if (data != nullptr)
        {

            delete[] data;
        }
    }
};
int pause();
int main()
{
    int length = 0;
    cout << "Enter the length of your string :\n";
    cin >> length;
    Mystring str(length);
    int option = -1;
    cout << "\n";

    do
    {

        cout << "\n\nChose an operation you would like to perform :\n1---Input string\n2---Display string\n3---Set char at an index\n4---Get char at an index\n5---concatenate two strings\n6---create a substring\n7---Copy another string to this string\n8---Convert to uppercase\n9---Convert to lower case\n10---Convert to proper case\n11---Create a reversed version of this string\n12---Reverse this string\n13---Create a sentence case version of this string\n14---Convert this string to sentence case\n15---Exit program\n\n";
        cin >> option;
        if (option == 1)
        {
            str.inputValues();
        }
        if (option == 2)
        {

            str.show();
        }
        if (option == 3)
        {
            int index = 0;
            char c;
            cout << "Enter the index at which you want to enter char : ";
            cin >> index;
            if (index > length)
            {
                cout << "\nExceeds string length";
                cout << "\nEnter a valid index";
                cin >> index;
            }
            cout << "Enter the char you want to enter at this index :\n";
            cin >> c;
            str.setValue(index, c);
            cout << "\nYour new string is :\n";
            str.show();
        }
        if (option == 4)
        {
            int index = 0;
            char c;
            cout << "Enter the index at which you want to get char from : ";
            cin >> index;
            c = str.getValue(index);
            cout << "\nThe char is :\t" << c;
        }
        if (option == 5)
        {
            int length3;
            cout << "\nEnter length of the string you want to concatenate to your strong :\n";
            cin >> length3;
            Mystring str2(length3);
            str2.inputValues();
            str.concatenate(str2);
            cout << "\nYour new string is :\n";
            str.show();
        }
        if (option == 6)
        {
            int index = 0;
            int L = 0;

            cout << "\nCreate a substtring from your string : ";
            cout << "\nEnter starting index :\n ";
            cin >> index;
            cout << "Enter length of your substring :\n ";
            cin >> L;
            Mystring Substring(str.substring(index, L));
            Substring.show();
        }
        if (option == 7)
        {
            int length2;
            cout << "\nEnter length of the string you want to copy to your strong :\n";
            cin >> length2;
            Mystring str2(length2);
            str2.inputValues();
            str.copyString(str2);
            cout << "\nYour new string is :\n";
            str.show();
        }
        if (option == 8)
        {
            cout << "\nYour string after being converted to uppercase is :\n";
            str.toUpper();
            str.show();
        }
        if (option == 9)
        {
            cout << "\nYour string after being converted to lowercase is :\n";
            str.toLower();
            str.show();
        }
        if (option == 10)
        {
            cout << "\nYour string after being converted to porpercase is :\n";
            str.toProper();
            str.show();
        }
        if (option == 11)
        {
            cout << "\nYour string after being reversed is :\n";
            str.toReverse();
            str.show();
        }
        if (option == 12)
        {
            cout << "\n Reversed copy of your string is :\n";
            Mystring rev(str.Reverse());
            rev.show();
        }
        if (option == 13)
        {
            cout << "\nYour string after being converted to sentencecase is :\n";
            str.toSentence();
            str.show();
        }
        if (option == 14)
        {
            cout << "\nSentence case copy of your string is :\n";
            Mystring sent(str.sentence());
            sent.show();
        }

    } while (option != 15);
    return 0;
}