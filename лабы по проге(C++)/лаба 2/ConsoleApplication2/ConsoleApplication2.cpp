//Написать класс Fraction для представления обыкновенных дробей(как отношения
//    двух целых чисел x / y).Перегрузить операторы + , -, *, / для дробей.Реализовать метод
//    void reduce() для сокращения дроби, а также статические методы :
// int gcd(int n, int m)
//функция для нахождения наибольшего общего делителя чисел n и m;
// void printAsFraction(double decimal_fraction)
// void printAsFraction(char* decimal_fraction)
//перегруженные методы вывода десятичной дроби в виде обыкновенной
//(например, при значении decimal_fraction = 0.43 на экране должно
//    вывестись 43 / 100, при 0.25 – 1 / 4 и т.д.).
//    Также реализовать в виде статического члена класса счетчик всех созданных на
//    данный момент в программе экземпляров дробей.
//    Продемонстрировать работу созданного класса.Создать несколько объектов дробей.
//    Произвести операции сложения, вычитания, умножения и деления дробей.Вывести
//    на экран результаты.Показать также результаты работы статических методов класса.

#include <iostream>
#include <string>

class Fraction {
public:
    static int Instances;
    double Fract;
    int X;
    int Y;
    Fraction(int x, int y) {

        Instances++;
        X = x;
        Y = y;
        Fract = X / Y;

    } 

    void operator+(Fraction& fraction) {
        if (fraction.Y == Y) {
            X += fraction.X;
        }
        else {
            X = (X * fraction.Y) + (fraction.X * Y);
            Y *= fraction.Y;
        }
    }
    void operator -(Fraction& fraction) {
        if (fraction.Y == Y) {
            X -= fraction.X;
        }
        else {
            X = (X * fraction.Y) - fraction.X * Y;
            Y *= fraction.Y;
        }
    }
    void operator*(Fraction& fraction) {
        X *= fraction.X;
        Y *= fraction.Y;
    }
    void operator/(Fraction& fraction) {
        X *= fraction.Y;
        Y *= fraction.X;
    }


    void reduce() {
        int temp = gcd(X, Y);
        this -> X /= temp;
        this -> Y /= temp;
    }

    static int gcd(int a, int b) {
        while (a != 0 && b != 0) {
            if (a > b) a %= b;
            else b %= a;
        }
        return a + b;
    }

    static void printAsFraction(double decimal_fraction) {
        while (decimal_fraction - (int)decimal_fraction != 0) {
            decimal_fraction *= 10;
        }
        int a = 10;
        while (decimal_fraction / a > 1) {
            a *= 10;
        }
        int temp = gcd(decimal_fraction, a);
        decimal_fraction /= temp;
        a /= temp;
        std::cout << decimal_fraction << "/" << a << std::endl;
    }
    static void printAsFraction(char* decimal_fraction) {
        int cnt = 0;
        char* temp = decimal_fraction;

        while (*decimal_fraction) {
            decimal_fraction++;
            cnt++;
            if (*decimal_fraction == '.') break;
        }

        decimal_fraction++;
        char* a = new char[cnt];
        for (int i = 0; i < cnt; i++) {
            a[i] = temp[i];
        }

        std::string s = a;
        int n = stoi(s);
        std::string ss = decimal_fraction;
        int length = ss.length();
        int m = stoi(ss);
        int y = pow(10, length);
        int x = m + n * y;

        int temp1 = gcd(x, y);
        x /= temp1;
        y /= temp1;

        std::cout << x << "/" << y << std::endl;
    }
};


int Fraction::Instances = 0;

int main()
{
    std::cout << "Fraction::Instances: "  << Fraction::Instances << std::endl << std::endl;

    Fraction frac(22, 22);
    std::cout << "Fraction0 = " << frac.Fract << std::endl;
    Fraction frac1(44, 22);
    std::cout << "Fraction1 = " << frac1.Fract << std::endl;
    std::cout << "Fraction::Instances: " << Fraction::Instances << std::endl << std::endl;

    frac.reduce();
    frac1.reduce();

    std::cout << "Fraction after Fraction.reduce(): " << frac.X << "/" << frac.Y << std::endl << std::endl;


     frac + frac1;
     std::cout << "frac + frac1: " << frac.X << "/" << frac.Y << std::endl;

     frac - frac1;
     std::cout << "frac - frac1: " << frac.X << "/" << frac.Y << std::endl;

     frac / frac1;
     std::cout << "frac / frac1 :" << frac.X << "/" << frac.Y << std::endl;

     frac * frac1;
     std::cout << "frac * frac1 :" << frac.X << "/" << frac.Y << std::endl;

     std::cout << "frac.gcd(20, 40): " << frac.gcd(20, 40) << std::endl;

     std::cout << "Fraction::printAsFraction(0.5): ";
     Fraction::printAsFraction(0.5);

     std::cout << "Fraction::printAsFraction(\"0.5\"): ";
     char dec[] = "0.5";
     Fraction::printAsFraction(dec);

}

