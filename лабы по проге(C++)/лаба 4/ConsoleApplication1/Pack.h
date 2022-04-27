#pragma once
#include <algorithm>
#include <iostream>
#include <time.h>
#include "Card.h"
class Pack
{
public:
	Pack();
	~Pack();
	Card* getCards();

protected:
	Card* _cards;

};
//Карты: 2-10, J, Q, K, A
