
#include <iostream>
#include <string>
using namespace std;
class Pointofsale
{
    int Totalfleet;
    int FunctionalCars;
    int Rentedout;
    int RequireMaintenance;

public:
    void setTotalfleet(int a)
    {
        Totalfleet = a;
    }
    void setFunctional(int a)
    {
        FunctionalCars = a;
    }
    void setRentedout(int a)
    {
        Rentedout = a;
    }
    void setRequiremaintenance(int a)
    {
        RequireMaintenance = a;
    }

    int getTotalfleet()
    {
        return Totalfleet;
    }
    int getFunctional()
    {
        return FunctionalCars;
    }
    int getRentedout()
    {
        return Rentedout;
    }
    int getRequiremaintenance()
    {
        return RequireMaintenance;
    }
};
class Cars
{
    string CarType;
    string CarName;
    int modelYear;
    int CostOfRent;

public:
    void setCartype(string a)
    {
        CarType = a;
    }
    void setCarname(string a)
    {
        CarName = a;
    }
    void setModelyr(int a)
    {
        modelYear = a;
    }
    void setCostofrent(int a)
    {
        CostOfRent = a;
    }
    string getCartype()
    {
        return CarType;
    }
    string getCarname()
    {
        return CarName;
    }
    int getModelyr()
    {
        return modelYear;
    }
    int getCostofrent()
    {
        return CostOfRent;
    }
};