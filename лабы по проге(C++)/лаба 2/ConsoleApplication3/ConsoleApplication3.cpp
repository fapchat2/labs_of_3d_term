#define _CRT_SECURE_NO_WARNINGS


//Написать собственный класс, в соответствии с вариантом.Продемонстрировать в коде
//инкапсуляцию данных, применение конструкторов без параметров и с параметрами
//для инициализации данных.Класс должен содержать метод serialize() для
//сохранения данных класса в файл и метод deserialize() для чтения данных класса
//из файла по умолчанию в текущей директории, а также перегруженные методы
//serialize( string& filename) и deserialize( string&
//    filename) для работы с файлом с указанным в параметре именем

//Класс ТЕЛЕФОН.
//Данные: модель, номер телефона, последний набранный номер, остаток на счету.
//Создать два телефона в куче.Установить данные первого телефона с помощью сеттеров,
//второго – в конструкторе с параметрами.В главной функции проимитировать десять
//звонков – позвонить по нескольку раз на 3 номера, в том числе на номер другого
//телефона в программе.За каждую минуту разговора снимается 0, 5 руб.Вывести всю
//информацию о телефонах после проведенных звонков.

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Telephone {

public:

    Telephone() {
        count++;

    }


    Telephone(char* model, char* number, char* lastNumber, double cash) {
        Model = model;
        Number = number;
        LastNumber = lastNumber;
        Cash = cash;
        count++;
    }
    void serialize() {
        ofstream fout;
            fout.open("output.txt", fstream::out);
            fout << Model << endl << Number << endl << LastNumber << endl << Cash;
            fout.close();
    }

    void serialize(const string& filename) {
        ofstream fout;
        fout.open(filename + ".txt", fstream::out);
        fout << Model << endl << Number << endl << LastNumber << endl << Cash;
        fout.close();

    }
    void deserialize() {
        fstream fin; //ifstream - file input
        fin.open("output.txt", fstream::in);
        std::string model;
        std::string number;
        std::string lastNumber;
        double cash;
            fin >> model;
            fin >> number;
            fin >> lastNumber;
            fin >> cash;



        char* cstr = new char[model.length() + 1];
        strcpy(cstr, model.c_str());

        Model = cstr;

        cstr = new char[number.length() + 1];
        strcpy(cstr, number.c_str());
        Number = cstr;

        cstr = new char[lastNumber.length() + 1];
        strcpy(cstr, lastNumber.c_str());
        LastNumber = cstr;

        Cash = cash;
    }

    void deserialize(const string& filename) {
        fstream fin;
        fin.open(filename + ".txt", fstream::in);
        std::string model;
        std::string number;
        std::string lastNumber;
        double cash;

        fin >> model;
        fin >> number;
        fin >> lastNumber;
        fin >> cash;

        char* cstr = new char[model.length() + 1];
        strcpy(cstr, model.c_str());

        Model = cstr;

        cstr = new char[number.length() + 1];
        strcpy(cstr, number.c_str());
        Number = cstr;

        cstr = new char[lastNumber.length() + 1];
        strcpy(cstr, lastNumber.c_str());
        LastNumber = cstr;

        Cash = cash;

    }

    void call(char* number, double minutes) {
        Cash -= minutes * 0.5;
        LastNumber = number;
        cout << "произведён звонок на телефон с номером: " << number << ". Снято рублей: " << to_string(minutes * 0.5) << endl;
    }

    void setModel(char* model)
    {
        Model = model;
    }
    void setNumber(char* number)
    {
        Number = number;
    }
    void setLastNumber(char* lastNumber)
    {
        LastNumber = lastNumber;
    }
    void setCash(double cash)
    {
        Cash = cash;
    }


    char* getModel()
    {
        return Model;
    }
    char* getNumber()
    {
        return Number;
    }
    char* getLastNumber()
    {
        return LastNumber;
    }
    double getCash()
    {
        return Cash;
    }




protected:
    char* Model;
    char* Number;
    char* LastNumber;
    double Cash;
    static int count;

};


int Telephone::count = 0;



int main()
{

    setlocale(LC_ALL, "rus");
    char numb0[] = "322322322";
    char numb1[] = "3223222888";

    char model[] = "Xiaomy-322";
    char Number[] = "+38077";
    char LastNumber[] = "+3846546077";
    double Cash = 300;

    char model1[] = "Xiaomy-rrr";
    char Number1[] = "+38555555";
    char LastNumber1[] = "+3846555555";
    double Cash1 = 322;

    Telephone* telephone = new Telephone();

    Telephone* telephone1 = new Telephone(model1, Number1, LastNumber1, Cash1);

    telephone->setModel(model);
    telephone->setNumber(Number);
    telephone->setLastNumber(LastNumber);
    telephone->setCash(Cash);

    printf("telephone->getModel %s\n", telephone->getModel());
    printf("telephone->getNumber %s\n", telephone->getNumber());
    printf("telephone->getLastNumber %s\n", telephone->getLastNumber());
    printf("telephone->getCash %f\n\n\n", telephone->getCash());


    telephone->call(telephone1->getNumber(), 2);
    telephone->call(telephone1->getNumber(), 3);
    telephone->call(telephone1->getNumber(), 2);
    telephone->call(telephone1->getNumber(), 1);
    telephone->call(telephone1->getNumber(), 2);
    telephone->call(numb0, 6);
    telephone->call(numb0, 5);
    telephone->call(numb0, 8);
    telephone->call(numb1, 2);
    telephone->call(numb1, 9);
    printf("\n\n\n");


    printf("telephone->getModel %s\n", telephone->getModel());
    printf("telephone->getNumber %s\n", telephone->getNumber());
    printf("telephone->getLastNumber %s\n", telephone->getLastNumber());
    printf("telephone->getCash %f\n\n\n", telephone->getCash());






    printf("telephone1->getModel %s\n", telephone1->getModel());
    printf("telephone1->getNumber %s\n", telephone1->getNumber());
    printf("telephone1->getLastNumber %s\n", telephone1->getLastNumber());
    printf("telephone1->getCash %f\n\n\n", telephone1->getCash());


    telephone1->call(telephone->getNumber(), 2);
    telephone1->call(telephone->getNumber(), 3);
    telephone1->call(telephone->getNumber(), 2);
    telephone1->call(telephone->getNumber(), 1);
    telephone1->call(telephone->getNumber(), 2);
    telephone1->call(numb0, 6);
    telephone1->call(numb0, 5);
    telephone1->call(numb0, 8);
    telephone1->call(numb1, 2);
    telephone1->call(numb1, 9);

    printf("\n\n\n");

    //printf("%s\n", telephone1->Model); //будет ошибка из-за инкапсуляции с пом. модификатора доступа protected
    printf("telephone1->getModel %s\n", telephone1->getModel());
    printf("telephone1->getNumber %s\n", telephone1->getNumber());
    printf("telephone1->getLastNumber %s\n", telephone1->getLastNumber());
    printf("telephone1->getCash %f\n\n\n", telephone1->getCash());

    printf("telephone1->serialize \n");
    printf("telephone->deserialize \n");

    telephone1->serialize();
    telephone->deserialize();

    printf("telephone->getModel %s\n", telephone->getModel());
    printf("telephone->getNumber %s\n", telephone->getNumber());
    printf("telephone->getLastNumber %s\n", telephone->getLastNumber());
    printf("telephone->getCash %f\n\n\n", telephone->getCash());


    char model2[] = "Apple";
    char Number2[] = "+666";
    char LastNumber2[] = "+388888999";
    double Cash2 = 5000;


    telephone->setModel(model2);
    telephone->setNumber(Number2);
    telephone->setLastNumber(LastNumber2);
    telephone->setCash(Cash2);


    telephone->serialize("telephone");
    telephone1->deserialize("telephone");

    printf("telephone1->getModel %s\n", telephone1->getModel());
    printf("telephone1->getNumber %s\n", telephone1->getNumber());
    printf("telephone1->getLastNumber %s\n", telephone1->getLastNumber());
    printf("telephone1->getCash %f\n\n\n", telephone1->getCash());

    delete telephone;
    delete telephone1;



}