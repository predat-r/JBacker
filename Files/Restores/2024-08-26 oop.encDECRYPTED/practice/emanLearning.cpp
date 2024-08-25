#include <iostream>
using namespace std;

int divide(int numerator, int denominator) {
    if (denominator == 0) {
        throw "Division by zero error!";
    }
    return numerator / denominator;
}

int main() {
    int numerator, denominator, result;

    cout << "Enter numerator: ";
    cin >> numerator;
    cout << "Enter denominator: ";
    cin >> denominator;

    try {
        result = divide(numerator, denominator);
        cout << "Result: " << result << endl;
    } catch (const char* exc) {
        cout << exc << endl;
    }

    return 0;
}
