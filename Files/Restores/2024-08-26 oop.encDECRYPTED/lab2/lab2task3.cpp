#include <iostream>
#include <string>
using namespace std;

class Car {
    int yearModel;
    string make;
    int speed;

public:
    Car(int a, string b) {
        yearModel = a;
        make = b;
        speed = 0;
    }

    void accelerate() {
        speed += 5;
        displaySpeed(); // Display speed after acceleration
    }

    void brake() {
        speed -= 5;
        displaySpeed(); // Display speed after braking
    }

    void displaySpeed() const {
        cout << "\nThe new speed of your car is: " << speed;
    }

    void displayCarinfo() const {
        cout << "\nThe details of your car are as follows:\nYear Model: " << yearModel << "\nMake: " << make << "\nSpeed: " << speed;
    }
};

int main() {
    int constructA;
    string constructMake;

    cout << "Enter make for constructor: ";
    getline(cin, constructMake);
    cout << "Enter model year for constructor: ";
    cin >> constructA;
    cin.ignore(); // Ignore the newline character left in the buffer

    Car c1(constructA, constructMake);
    c1.accelerate();

    Car* ptr = new Car(54, "pakistan");
    ptr->accelerate();
    ptr->accelerate();
    ptr->accelerate();
    ptr->accelerate();
    ptr->accelerate();
    ptr->brake();
    ptr->brake();
    ptr->brake();
    ptr->brake();
    ptr->brake();

    // Delete the dynamically allocated object
    delete ptr;

    return 0;
}
