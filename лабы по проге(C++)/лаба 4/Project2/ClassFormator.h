#pragma once
#include "Pack.h"
#include "IFormattable.h"//������� ������
class ClassFormator : public IFormattable, public Pack
{
public:
	ClassFormator();
	//ClassFormator(Pack& pack);
	~ClassFormator();
	//void prettyPrint(const IFormattable& object);
	 std::string format() const override;
private:
	//Pack & _pack;
};

