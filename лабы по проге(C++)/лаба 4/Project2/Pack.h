#pragma once
#include <algorithm>
#include <iostream>
#include <time.h>
#include <string>
#include "Card.h"
//#include "IFormattable.h" //������� GOF �������� � ����� ����� (������� ������ � ������� �������)

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
//�����: 2-10, J, Q, K, A
