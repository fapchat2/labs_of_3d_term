#define _CRT_SECURE_NO_WARNINGS
#include"MobilePhone.h"
#include <iostream>
#include <fstream>



MobilePhone::MobilePhone()
{
    Charging = 100;
    count++;

}


MobilePhone::MobilePhone(char* model, char* number, char* lastNumber, double cash, char* companyManufacturer, char* weight, char* color, char* price)
{
    Model = model;
    Number = number;
    LastNumber = lastNumber;
    Cash = cash;
    Charging = 100;
    CompanyManufacturer = companyManufacturer;
    Weight = weight;
    Color = color;
    Price = price;
    count++;
}

MobilePhone::~MobilePhone()
{
}

void MobilePhone::call(const std::string& recepient)
{
    Charging -= 3;
    Cash -= 1;
    char* numb = new char[recepient.length() + 1];
    strcpy(numb, recepient.data());
    this->setLastNumber(numb);
    delete[] numb;
    int i = 0;
    int correctness = 1;
    while (recepient[i])
    {
        if (!(recepient[i] >= '0' && recepient[i] <= '9'))
        {
            cout << "Номер некорректен!!!\n";
            correctness = 0;
            break; 
        }
        i++;
    }
    if(correctness) cout << "произведён звонок на телефон с номером: " << recepient << endl;

}


void MobilePhone::serialize()
{
    cout << "MobilePhone::serialize() (works only for MobilePhones, tablets have other variables)" << endl;

    ofstream fout;
    fout.open("output.txt", fstream::out);
    fout << Model << endl << Number << endl << LastNumber << endl << Charging << endl << CompanyManufacturer << endl << Weight << endl << Color << endl << Price;
    fout.close();


}

void MobilePhone::serialize(const string& filename)
{
    cout << "MobilePhone::serialize() (works only for MobilePhones, tablets have other variables)" << endl;

    ofstream fout;
    fout.open(filename + ".txt", fstream::out);
    fout << Model << endl << Number << endl << LastNumber << endl << Charging << endl << CompanyManufacturer << endl << Weight << endl << Color << endl << Price;
    fout.close();

}
void MobilePhone::deserialize()
{
    cout << "MobilePhone::deserialize() (works only for MobilePhones, tablets have other variables)" << endl;

    fstream fin; 
    fin.open("output.txt", fstream::in);
    std::string model;
    std::string number;
    std::string lastNumber;
    double cash;
    int charging;
    std::string companyManufacturer;
    std::string weight;
    std::string color;
    std::string price;

    fin >> model;
    fin >> number;
    fin >> lastNumber;
    fin >> cash;
    fin >> charging;
    fin >> companyManufacturer;
    fin >> weight;
    fin >> color;
    fin >> price;

    char* cstr = new char[model.length() + 1];
    strcpy(cstr, model.c_str());
    Model = cstr;

    cstr = new char[number.length() + 1];
    strcpy(cstr, number.c_str());
    Number = cstr;

    cstr = new char[lastNumber.length() + 1];
    strcpy(cstr, lastNumber.c_str());
    LastNumber = cstr;

    Charging = charging;

    Cash = cash;

    cstr = new char[model.length() + 1];
    strcpy(cstr, model.c_str());
    CompanyManufacturer = cstr;

    cstr = new char[number.length() + 1];
    strcpy(cstr, number.c_str());
    Weight = cstr;

    cstr = new char[lastNumber.length() + 1];
    strcpy(cstr, lastNumber.c_str());
    Color = cstr;

    cstr = new char[lastNumber.length() + 1];
    strcpy(cstr, lastNumber.c_str());
    Price = cstr;
}

void MobilePhone::deserialize(const string& filename)
{
    cout << "MobilePhone::deserialize() (works only for MobilePhones, tablets have other variables)" << endl;

    fstream fin;
    fin.open(filename + ".txt", fstream::in);

    std::string model;
    std::string number;
    std::string lastNumber;
    double cash;
    int charging;
    std::string companyManufacturer;
    std::string weight;
    std::string color;
    std::string price;

    fin >> model;
    fin >> number;
    fin >> lastNumber;
    fin >> cash;
    fin >> charging;
    fin >> companyManufacturer;
    fin >> weight;
    fin >> color;
    fin >> price;

    char* cstr = new char[model.length() + 1];
    strcpy(cstr, model.c_str());
    Model = cstr;

    cstr = new char[number.length() + 1];
    strcpy(cstr, number.c_str());
    Number = cstr;

    cstr = new char[lastNumber.length() + 1];
    strcpy(cstr, lastNumber.c_str());
    LastNumber = cstr;

    Charging = charging;

    Cash = cash;

    cstr = new char[model.length() + 1];
    strcpy(cstr, model.c_str());
    CompanyManufacturer = cstr;

    cstr = new char[number.length() + 1];
    strcpy(cstr, number.c_str());
    Weight = cstr;

    cstr = new char[lastNumber.length() + 1];
    strcpy(cstr, lastNumber.c_str());
    Color = cstr;

    cstr = new char[lastNumber.length() + 1];
    strcpy(cstr, lastNumber.c_str());
    Price = cstr;
}
int MobilePhone::count = 0;
