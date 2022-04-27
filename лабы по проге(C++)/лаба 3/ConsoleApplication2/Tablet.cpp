#define _CRT_SECURE_NO_WARNINGS
#include"Tablet.h"
#include <iostream>
#include <fstream>


Tablet::Tablet()
{
    Charging = 100;
    count++;

}


Tablet::Tablet(char* model, char* number, char* lastNumber, char* companyManufacturer, char* weight, char* color, char* price)
{
    Model = model;
    Number = number;
    LastNumber = lastNumber;
    Charging = 100;
    CompanyManufacturer = companyManufacturer;
    Weight = weight;
    Color = color;
    Price = price;
    count++;
}


Tablet::~Tablet()
{
}

void Tablet::call(const std::string& recepient)
{
    Charging -= 10;
    char* numb = new char[recepient.length() + 1];
    strcpy(numb, recepient.data());
    this->setLastNumber(numb);
    delete[] numb;


    cout << "произведён звонок на телефон с номером: " << recepient << endl;
}



void Tablet::serialize()
{
    cout << "Tablet::serialize() (works only for tablets, telephones have other variables)" << endl;

    ofstream fout;
        fout.open("output.txt", fstream::out);
        fout << Model << endl << Number << endl << LastNumber << endl << Charging << endl << CompanyManufacturer << endl << Weight << endl << Color << endl << Price;
        fout.close();


}

void Tablet::serialize(const string& filename)
{
    cout << "Tablet::serialize() (works only for tablets, telephones have other variables)" << endl;

    ofstream fout;
    fout.open(filename + ".txt", fstream::out);
    fout << Model << endl << Number << endl << LastNumber << endl << Charging << endl << CompanyManufacturer << endl << Weight << endl << Color << endl << Price;
    fout.close();

}
void Tablet::deserialize()
{
    cout << "Tablet::deserialize() (works only for tablets, telephones have other variables)" << endl;

    fstream fin;
    fin.open("output.txt", fstream::in);
    std::string model;
    std::string number;
    std::string lastNumber;
    int charging;
    std::string companyManufacturer;
    std::string weight;
    std::string color;
    std::string price;

        fin >> model;
        fin >> number;
        fin >> lastNumber;
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

void Tablet::deserialize(const string& filename)
{
    cout << "Tablet::deserialize() (works only for tablets, telephones have other variables)" << endl;

    fstream fin;
    fin.open(filename + ".txt", fstream::in);
    std::string model;
    std::string number;
    std::string lastNumber;
    int charging;
    std::string companyManufacturer;
    std::string weight;
    std::string color;
    std::string price;

    fin >> model;
    fin >> number;
    fin >> lastNumber;
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
int Tablet::count = 0;
