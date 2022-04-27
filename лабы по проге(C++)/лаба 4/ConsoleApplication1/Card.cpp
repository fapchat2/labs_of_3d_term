#include "Card.h"
Card::Card() 
{
	_number = 0;
	_suit = 0;
	_points = 0;
}

Card::Card(int number, int suit)
{
	_number = number;
	_suit = suit;
	if (number % 11 == 0)
	{
		_points = 10;
	}
	else if (number % 12 == 0)
	{
		_points = 10;
	}
	else if (number % 13 == 0)
	{
		_points = 10;
	}
	else if (number % 14 == 0)
	{
		_points = 11;
	}
	else
	{
		_points = number;
	}
}

Card::~Card()
{
}

int Card::getSuit()
{
	return _suit;
}

int Card::getNumber()
{
	return _number;
}

int Card::getPoints()
{
	return _points;
}

std::ostream& operator<<(std::ostream& os, const Card& card)
{


	if(card._number % 11 == 0)
	{
		os << 'J';
		printf("%c ", card._suit);
	}
	else if (card._number % 12 == 0)
	{
		os << 'Q';
		printf("%c ", card._suit);
	}
	else if (card._number % 13 == 0)
	{
		os << 'K';
		printf("%c ", card._suit);
	}
	else if (card._number % 14 == 0)
	{
		os << 'A';
		printf("%c ", card._suit);
	}
	else
	{
		os << card._number;
		printf("%c ", card._suit);
	}
	return os;
}

