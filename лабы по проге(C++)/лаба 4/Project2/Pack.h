#pragma once
#include <algorithm>
#include <iostream>
#include <time.h>
#include <string>
#include "Card.h"
//#include "IFormattable.h" //паттерн GOF «Адаптер» в обоих видах (адаптер класса и адаптер объекта)

class Pack// : public IFormattable
{
public:
	Pack();
	~Pack();
	Card* getCards();
	std::string returnNumbersInString() const;


protected:
	Card* _cards;
};
//Карты: 2-10, J, Q, K, A
