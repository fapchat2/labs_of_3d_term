#include "Player.h"
Player::Player()
{
	_dollars = 20000;
	_numberOfPoints = 0;
	_numberOfCards = 0;
	_cards = new Card[52];

}

Player::~Player()
{
	delete[] _cards;
}

int Player::getDollars()
{
	return _dollars;
}

void Player::setDollars(int d)
{
	 _dollars = d;
}

Card* Player::getCards()
{
	return _cards;
}

int Player::getPoints()
{
	return _numberOfPoints;
}

void Player::addCard(Card card)
{
	_cards[_numberOfCards] = card;
	if (card.getPoints() == 11 && _numberOfPoints < 11)
	{
		_numberOfPoints += card.getPoints();
	}
	else if(card.getPoints() == 11 && _numberOfPoints >= 11)
	{
		++_numberOfPoints;
	}
	else
	{
		_numberOfPoints += card.getPoints();
	}
	++_numberOfCards;
	std::cout << "Player received a card " << card << std::endl;

};

int Player::getNumberOfCards() 
{
	return _numberOfCards;
}





//int Player::setPack(int d)
//{
//	_dollars = d;
//}