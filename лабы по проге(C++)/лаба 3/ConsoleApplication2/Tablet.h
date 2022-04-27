 #pragma once
#include "Telephone.h"

class Tablet: public Telephone
{
public:
    Tablet();
    Tablet(char* model, char* number, char* lastNumber, char* companyManufacturer, char* weight, char* color, char* price);
    ~Tablet();
    virtual void call(const std::string& recepient);
    void serialize();
    void serialize(const string& filename);
    void deserialize();
    void deserialize(const string& filename);
    static int count;

protected:
    char* Model;
    char* Number;
    char* LastNumber;
    int Charging;
    char* CompanyManufacturer;
    char* Weight;
    char* Color;
    char* Price;
};
