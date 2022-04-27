#include "Formator.h"

Formator::Formator()
{
	Pack _pack;
}

Formator::Formator(Pack pack)
{

	_pack = pack;
}

Formator::~Formator()
{
}

std::string Formator::format()
{
	std::string NumbersInString = "";
	_cards = _pack.getCards();
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

std::string Formator::format() const
{
	return _pack.returnNumbersInString();
}

//void Formator::prettyPrint(const IFormattable& object)
//{
//	std::cout << object.format();
//}