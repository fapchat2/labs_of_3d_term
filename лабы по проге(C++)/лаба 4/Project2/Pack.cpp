#include "Pack.h"


Pack::Pack()
{

	_cards = new Card[52];
	int suit = 3; //Ascii code масти
	int j = 2;

	for (size_t i = 0; i < 52; i++)
	{
		if (j == 15) j = 2;
		Card card(j, suit);
		j++;
		_cards[i] = card;
		if ((i + 1) % 13 == 0) suit++;
	}


	srand(time(0));
	for (int i = 0; i < 52; ++i)
		std::swap(_cards[i], _cards[std::rand() % 52]);

}

Pack::~Pack()
{
	delete[] _cards;
}

std::string Pack::returnNumbersInString() const
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

Card* Pack::getCards()
{
	return _cards;
};

