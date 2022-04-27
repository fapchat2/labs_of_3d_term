#include "ClassFormator.h"

ClassFormator::ClassFormator() //:_pack(*new Pack)
{

}

//ClassFormator::ClassFormator(Pack& pack) : _pack(pack)
//{
//}

ClassFormator::~ClassFormator()
{

}

std::string ClassFormator:: format() const
{
	std::string NumbersInString = "";
	int j;
	for (int i = 0; i < 51; i++)
	{

		for (j = i + 1; j < 52; j++)
		{
			if (_cards[i].getNumber() < _cards[j].getNumber())
			{
				int temp = _cards[i].getNumber();
				_cards[i].setNumber(_cards[j].getNumber());
				_cards[j].setNumber(temp);
			}
		}

	}


	for (int i = 0; i < 52; ++i)
		NumbersInString.append(std::to_string(_cards[i].getNumber()).append(" "));


	return NumbersInString;
}



//void Formator::prettyPrint(const IFormattable& object)
//{
//	std::cout << object.format();
//}