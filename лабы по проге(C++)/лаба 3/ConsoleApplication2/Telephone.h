#pragma once
#include "ICallable.h"

using namespace std;
class Telephone: public ICallable
{

public:

    virtual void call(const std::string& recepient);



    void setModel(char* model);
    void setNumber(char* number);
    void setLastNumber(char* lastNumber);
    void setCash(double cash);
    void setCompanyManufacturer(char* companyManufacturer);
    void setWeight(char* weight);
    void setColor(char* color);
    void setPrice(char* price);

    char* getModel();
    char* getNumber();
    char* getLastNumber();
    double getCash();
    char* getCompanyManufacturer();
    char* getWeight();
    char* getColor();
    char* getPrice();
    int getCharging();



protected:
    char* Model;
    char* Number;
    char* LastNumber;
    double Cash;
    int Charging;
    char* CompanyManufacturer;
    char* Weight;
    char* Color;
    char* Price;
};

