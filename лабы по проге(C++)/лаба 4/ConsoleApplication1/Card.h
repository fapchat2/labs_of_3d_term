#pragma once
#include <iostream>
class Card
{
public:
    Card();
    Card(int number , int suit);
    ~Card();

    int getSuit();
    int getNumber();
    int getPoints();
    friend std::ostream& operator<<(std::ostream& os, const Card &card);

protected:
    int _number;
    int _suit; //масть
    int _points;
};

