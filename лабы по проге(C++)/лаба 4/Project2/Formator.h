#pragma once
#include "Pack.h"
#include "IFormattable.h"//������� �������
class Formator : public IFormattable
{
public:
	Formator();
	Formator(Pack _pack);
	~Formator();
	//void prettyPrint(const IFormattable& object);
	std::string format();
	std::string format() const override;
private:
	Pack _pack;
	Card* _cards;
};

