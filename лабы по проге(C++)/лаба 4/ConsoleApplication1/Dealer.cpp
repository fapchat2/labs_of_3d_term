#include "Dealer.h"

Dealer::Dealer() :_player(*new Player)
{
	_numberOfCards = 0;
	_cards = new Card[52];
	_points = 0;
	_dollars = 0;
};

Dealer::Dealer(Player &player, Card* cards)
	:
	_player(player),
	_cards(cards)
{
	_numberOfCards = 0;
	_points = 0;
	_dollars = 0;
};

Dealer::~Dealer() 
{
	delete[] _cards;
};

void Dealer::bet() 
{
	std::cout << "How much will you bet?  " << std::endl;
	std::cin >> _dollars;

	while (_dollars < 20 || _dollars > 20000)
	{
		std::cout << "You can't bet more than 20 thousand dollars or less than 20 dollars... How much will you bet ?  " << std::endl;
		std::cin >> _dollars;
	}

	_player.setDollars(_player.getDollars() - _dollars);

}


Card* Dealer::getCards()
{
	return _cards;
}

int Dealer::getDollars()
{
	return _dollars;
}

int Dealer::getPoints() 
{
	return _points;
}

void Dealer::takeCard(Card card)
{
	_cards[_numberOfCards] = card;
	if (card.getPoints() == 11 && _points < 11)
	{
		_points += card.getPoints();
	}
	else if (card.getPoints() == 11 && _points >= 11)
	{
		++_points;
	}
	else
	{
		_points += card.getPoints();
	}
	++_numberOfCards;
	std::cout << "Dealer received a card " << card << std::endl;
}
