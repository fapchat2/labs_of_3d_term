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
#pragma once

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "MobilePhone.h";
#include "Tablet.h";



int main()
{


setlocale(LC_ALL, "rus");

char model[] = "Xi322";
char Number[] = "+38077";
char LastNumber[] = "";
double Cash = 300;
char CompanyManufacturer[] = "Apple";
char Weight[] = "0.4kg";
char Color[] = "white";
char Price[] = "2000$";

char model1[] = "Xirrr";
char Number1[] = "+38555555";
char LastNumber1[] = "";
double Cash1 = 322;
char CompanyManufacturer1[] = "Xiaomy";
char Weight1[] = "1kg";
char Color1[] = "black";
char Price1[] = "200$";

MobilePhone telephone;

 

telephone.setModel(model);
telephone.setNumber(Number);
telephone.setLastNumber(LastNumber);
telephone.setCash(Cash);
telephone.setCompanyManufacturer(CompanyManufacturer);
telephone.setWeight(Weight);
telephone.setColor(Color);
telephone.setPrice(Price);

MobilePhone* telephone1 = new MobilePhone(model1, Number1, LastNumber1, Cash1, CompanyManufacturer1, Weight1, Color1, Price1);


Tablet tablet;

tablet.setModel(model);
tablet.setNumber(Number);
tablet.setLastNumber(LastNumber);
tablet.setCompanyManufacturer(CompanyManufacturer);
tablet.setWeight(Weight);
tablet.setColor(Color);
tablet.setPrice(Price);

Tablet* tablet1 = new Tablet(model1, Number1, LastNumber1, CompanyManufacturer1, Weight1, Color1, Price1);

//пример полиморфизма 

Telephone &tel = telephone;
tel.call("aaaaaa");

Telephone& tabl = tablet;
tabl.call("aaaaaa");



cout << "демонстрация работы RTTI(определение типов во время выполнения программы)" << endl;
cout << "telephone - " << typeid(telephone).name() << endl;
cout << "telephone1 - " << typeid(telephone1).name() << endl;
cout << "tablet - " << typeid(tablet).name() << endl;
cout << "tablet1 - " << typeid(tablet1).name() << endl;
cout << Tablet::count;

}

