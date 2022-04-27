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

Card* Pack::getCards() 
{
	return _cards;
};

