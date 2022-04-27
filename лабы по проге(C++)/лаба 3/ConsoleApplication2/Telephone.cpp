#define _CRT_SECURE_NO_WARNINGS
#include "Telephone.h"
#include <iostream>
#include <fstream>

using namespace std;




    void Telephone::call(const std::string& recepient)
    {
        cout << "произведён звонок на телефон с номером: " << recepient << endl;
    }

    void Telephone::setModel(char* model)
    {
        Model = model;
    }
    void Telephone::setNumber(char* number)
    {
        Number = number;
    }
    void Telephone::setLastNumber(char* lastNumber)
    {
        LastNumber = lastNumber;
    }
    void Telephone::setCash(double cash)
    {
        Cash = cash;
    }
    void Telephone::setCompanyManufacturer(char* companyManufacturer)
    {
        CompanyManufacturer = companyManufacturer;
    }
    void Telephone::setWeight(char* weight)
    {
        Weight = weight;
    }
    void Telephone::setColor(char* color)
    {
        Color = color;
    }
    void Telephone::setPrice(char* price)
    {
        Price = price;
    }



    char* Telephone::getModel()
    {
        return Model;
    }
    char* Telephone::getNumber()
    {
        return Number;
    }
    char* Telephone::getLastNumber()
    {
        return LastNumber;
    }
    double Telephone::getCash()
    {
        return Cash;
    }

    char* Telephone::getCompanyManufacturer()
    {
        return CompanyManufacturer;

    }
    char* Telephone::getWeight() 
    {
        return Weight;

    }
    char* Telephone::getColor()
    {
        return Color;

    }
    char* Telephone::getPrice()
    {
        return Price;

    }
    int Telephone::getCharging()
    {
        return Charging;
    }

