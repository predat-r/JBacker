#include <iostream>
#include <string>
#include <fstream>
using namespace std;
int totalIDs = 0;
class Product
{
private:
    int productID;
    float price;
    string name;
    int quantity;

public:
    Product()
    {
        productID = 0;
        price = 0.0;
        name = "";
        quantity = 0;
    }
    void setProductID(int x)
    {
        productID = x;
    }
    void setPrice(float x)
    {
        price = x;
    }
    void setName(string x)
    {
        name = x;
    }
    void setQuanity(int x)
    {
        quantity = x;
    }
    int getProductID()
    {
        return productID;
    }
    string getName()
    {
        return name;
    }
    float getPrice()
    {
        return price;
    }
    int getQuantity()
    {
        return quantity;
    }
    void readFromFile(ifstream &file)
    {
        file >> productID >> name >> price >> quantity;
    }

    void writeToFile(ofstream &file)
    {
        file << productID << " " << name << " " << price << " " << quantity;
    }

    void display()
    {
        cout << "Product ID : " << getProductID() << "\nName : " << getName() << "\nPrice : " << getPrice() << "\nQuantity : " << getQuantity() << "\n\n";
    }
    ~Product() {}
};
void addProducts(Product *&productlist, int capacity);
void removeProducts(Product *productlist);
void updateQuantity(Product *productlist);
void displayProducts(Product *productlist);
void totalValue(Product *productlist);
void Refreshlist(Product *productlist, int i, int j);
int FindIDbyname(Product *productlist, string a);
int main()
{
    int choice = 0;
    int capacity = 1;
    Product *productlist = new Product[capacity];
    ifstream inFile("inventory.txt");
    if (inFile.is_open())
    {
        while (!inFile.eof())
        {
            productlist[totalIDs].readFromFile(inFile);
            totalIDs++;
        }
        inFile.close();
    }
    do
    {
        cout << "Welcome to inventory management ! What  operation would you like to perform\n1.\t\tAdd Products\n2.\t\tRemove Products\n3.\t\tUpdate Quantity\n4.\t\tDisplay products\n5.\t\tTotal Value\n6.\t\tExit Program\n\n";
        cin >> choice;
        switch (choice)
        {
        case 1:
            addProducts(productlist, capacity);
            break;
        case 2:
            removeProducts(productlist);
            break;
        case 3:
            updateQuantity(productlist);
            break;
        case 4:
            displayProducts(productlist);
            break;
        case 5:
            totalValue(productlist);
            break;

        default:
            break;
        }
    } while (choice != 6);
    if (choice == 6)
    {
        ofstream outFile("inventory.txt");
        if (outFile.is_open())
        {
            for (int i = 0; i < totalIDs; i++)
            {
                productlist[i].writeToFile(outFile);
            }
            outFile.close();
        }

        delete[] productlist; // Deallocate memory before exiting

        cout << "\nThanks for using our program";
    }
}
void addProducts(Product *&productlist, int capacity)
{
    int num;
    string d;
    int a;
    float e;

    cout << "\nHow many products do you want to add :\n";
    cin >> num;
    if (num + totalIDs > capacity)
    {
        int newCapacity = num + totalIDs;
        Product *temp = new Product[newCapacity];
        for (size_t i = 0; i < totalIDs; i++)
        {
            temp[i] = productlist[i];
        }
        delete[] productlist;
        productlist = temp;
        capacity = newCapacity;
    }

    cin.ignore();

    for (int i = 0; i < num; i++)
    {

        productlist[totalIDs].setProductID(totalIDs);

        cout << "\nEnter name of product : ";
        getline(cin, d);
        productlist[totalIDs].setName(d);

        cout << "Price of Product : ";
        cin >> e;
        cin.ignore();
        productlist[totalIDs].setPrice(e);

        cout << "Enter Quantity : ";
        cin >> a;
        cin.ignore();
        productlist[totalIDs].setQuanity(a);
        totalIDs++;
    }
    return;
}

void removeProducts(Product *productlist)
{
    int option, id;
    string namer;
    cout << "\n1\t\tSearch by id\n2\t\tSearch by name\n";
    cin >> option;
    switch (option)
    {
    case 1:
        cout << "\nEnter ID of the product you want to remove :\n";
        cin >> id;
        Refreshlist(productlist, id, id + 1);
        cout << "\n";
        return;
        break;
    case 2:
        cout << "\nEnter name of product you want to remove :\n";
        cin.ignore();
        getline(cin, namer);
        id = FindIDbyname(productlist, namer);
        Refreshlist(productlist, id, id + 1);
        cout << "\n";
        return;

    default:
        break;
    }
}
int FindIDbyname(Product *productlist, string a)
{
    for (int i = 0; i < totalIDs; i++)
    {
        if (a == productlist[i].getName())
        {
            return productlist[i].getProductID();
        }
    }
}
void Refreshlist(Product *productlist, int i, int j)
{
    for (; i < totalIDs; i++)
    {
        productlist[i] = productlist[j];
        productlist[j].setProductID(i);
        j++;
    }
    Product p1;
    productlist[j].setProductID(i);
    productlist[totalIDs] = p1;
    totalIDs--;
    return;
}
void updateQuantity(Product *productlist)
{
    int option, id, newq;
    string namer;
    cout << "\n1\t\tSearch by id\n2\t\tSearch by name\n";
    cin >> option;
    switch (option)
    {
    case 1:
        cout << "\nEnter ID of the product you want to update quantity of :\n";
        cin >> id;
        productlist[id].display();
        cout << "\nEnter New quantity : ";
        cin >> newq;
        productlist[id].setQuanity(newq);
        cout << "\ndone!";
        break;
    case 2:
        cout << "\nEnter name of product you want to update quantity of :\n";
        getline(cin, namer);
        id = FindIDbyname(productlist, namer);
        cout << "\nEnter New quantity : ";
        cin >> newq;
        productlist[id].setQuanity(newq);
        cout << "\ndone!";
        break;

    default:
        break;
    }
    cout << "\n\n";
    return;
}
void displayProducts(Product *productlist)
{
    for (int i = 0; i < totalIDs; i++)
    {
        productlist[i].display();
    }
    cout << "\n";
    return;
}
void totalValue(Product *productlist)
{
    double totalValue = 0.0;
    for (size_t i = 0; i < totalIDs; i++)
    {
        totalValue += productlist[i].getPrice();
    }
    cout << "the total value of your items is " << totalValue << "\n";
    return;
}