#include "Telephone.h"

class MobilePhone: public Telephone
{
public:
    MobilePhone();
    MobilePhone(char* model, char* number, char* lastNumber, double cash, char* companyManufacturer, char* weight, char* color, char* price);
    ~MobilePhone();
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
    double Cash;
    int Charging;
    char* CompanyManufacturer;
    char* Weight;
    char* Color;
    char* Price;

};

