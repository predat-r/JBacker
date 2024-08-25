#include <iostream>
#include <string>
using namespace std;
class complex
{
    double real;
    double imaginary;

public:
    complex()
    {
        real = 0.0;
        imaginary = 0.0;
    }
    complex(double r)
    {
        real = r;
        imaginary = 0.0;
    }
    complex(double r, double i)
    {
        real = r;
        imaginary = i;
    }
    complex(const complex &c)
    {
        this->real = c.real;
        this->imaginary = c.imaginary;
    }
    double getReal() const
    {
        return real;
    }
    double getImaginary() const
    {
        return imaginary;
    }
    void setReal(double a)
    {
        real = a;
    }
    void setImaginary(double a)
    {
        imaginary = a;
    }
    complex operator+(const complex c) const
    {
        complex add;
        add.imaginary = (this->imaginary + c.imaginary);
        add.real = (this->real + c.real);
        return add;
    }
    complex operator-(const complex c) const
    {
        complex sub;
        sub.imaginary = (this->imaginary - c.imaginary);
        sub.real = (this->real - c.real);
        return sub;
    }
    complex operator*(const complex comp) const
    {
        complex mult;
        int a, b, c, d;
        a = this->real * comp.real;
        b = this->real * comp.imaginary;
        c = this->imaginary * comp.real;
        d = this->imaginary * comp.imaginary;
        int e = b + c;
        a = a - d;
        mult.real = a;
        mult.imaginary = e;
        return mult;
    }
    complex operator/(complex deno) const
    {
        complex division;
        int newDeno = (deno.real * deno.real) + (deno.imaginary * deno.imaginary);
        deno.imaginary = deno.imaginary * -1;
        complex newNue(this->operator*(deno));
        division.real = newNue.real / newDeno;
        division.imaginary = newNue.imaginary / newDeno;
        return division;
    }
    complex conjugate(complex c)
    {
        complex conj(c);
        conj.imaginary = (conj.imaginary * -1);
        return conj;
    }
    void display()
    {
        cout << "\n";
        if (imaginary > 0)
        {
            cout << real << " + " << imaginary << "i\n";
        }
        if (imaginary < 0)
        {
            cout << real << imaginary << "i\n";
        }
    }
    ~complex()

    {
    }
};
int main()
{
    double real, imaginary;
    int option = 0;
    cout << "\nWelcome to complex numbers\n";
    cout << "Enter your real number :\n ";
    cin >> real;
    cout << "Enter your imaginary number :\n ";
    cin >> imaginary;
    complex c1(real, imaginary);
    do
    {
        cout << "\nWhat would you like to perform\n1---Add a complex number to your number\n2---Subtract a complex number from your number\n3---Multiply a complex number to your number\n4---Divide your complex number by another complex number\n5---Get conjugate of your complex number\n6--- get real number\n7---get imaginary number\n8---display your complex number\n9---Set real\n10---set Imaginary\n11---exit program\n\n";
        cin >> option;

        if (option == 1)
        {
            cout << "\nEnter values for your second complex number\n";

            cout << "Enter your real number :\n ";
            cin >> real;
            cout << "Enter your imaginary number :\n ";
            cin >> imaginary;
            complex c2(real, imaginary);
            complex add(c1 + c2);
            add.display();
        }
        if (option == 2)
        {
            cout << "\nEnter values for your second complex number\n";

            cout << "Enter your real number :\n ";
            cin >> real;
            cout << "Enter your imaginary number :\n ";
            cin >> imaginary;
            complex c3(real, imaginary);
            complex sub(c1 - c3);
            sub.display();
        }
        if (option == 3)
        {
            cout << "\nEnter values for your second complex number\n";

            cout << "Enter your real number :\n ";
            cin >> real;
            cout << "Enter your imaginary number :\n ";
            cin >> imaginary;
            complex c4(real, imaginary);
            complex mult(c1 * c4);
            mult.display();
        }
        if (option == 4)
        {
            cout << "\nEnter values for your second complex number\n";

            cout << "Enter your real number :\n ";
            cin >> real;
            cout << "Enter your imaginary number :\n ";
            cin >> imaginary;
            complex c5(real, imaginary);
            complex div(c1 / c5);
            div.display();
        }
        if (option == 5)
        {
            cout << "\nThe conjugate of your complex number is :\n";
            complex conj(c1.conjugate(c1));
            conj.display();
        }
        if (option == 6)
        {
            double r;
            r = c1.getReal();
            cout << "\nYour real number is : " << r << "\n";
        }
        if (option == 7)
        {
            double i;
            i = c1.getImaginary();
            cout << "\nYour imaginary number is :" << c1.getImaginary() << "\n";
        }
        if (option == 8)
        {
            c1.display();
        }
        if (option == 9)
        {
            double a;
            cout << "\nEnter real number you would like to set : \n";
            cin >> a;
            c1.setReal(a);
            c1.display();
        }
        if (option == 10)
        {
            double b;
            cout << "\nEnter imaginary number you would like to set : \n";
            cin >> b;
            c1.setImaginary(b);
            c1.display();
        }

    } while (option != 11);

    return 0;
}