#include <iostream>
using namespace std;

template <typename T>
class Storage
{
private:
    T value;

public:
    // Constructor
    Storage(T val) : value(val) {}

    // Getter method
    T getValue() const;

    // Setter method
    void setValue(T);
};
template <typename T>
T Storage<T>::getValue() const
{
    return value;
}
template <typename T>
void Storage<T>::setValue(T val)
{
    value = val;
}

int main()
{
    // Create a Storage object for int
    Storage<int> intStorage(5);
    cout << "Integer Value: " << intStorage.getValue() << endl;

    // Create a Storage object for double
    Storage<double> doubleStorage(3.14);
    cout << "Double Value: " << doubleStorage.getValue() << endl;

    // Create a Storage object for string
    Storage<string> stringStorage("Hello, World!");
    cout << "String Value: " << stringStorage.getValue() << endl;

    return 0;
}