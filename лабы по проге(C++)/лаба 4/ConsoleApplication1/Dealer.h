#pragma once
#include "Player.h"

class Dealer
{
public:
	Dealer();
	Dealer(Player& player, Card* cards);
	~Dealer();
	void bet();
	void takeCard(Card card);
	int getDollars();
	Card* getCards();
	int getPoints();


protected:
	Card* _cards;
	Player & _player;
	int _dollars;
	int _numberOfCards;
	int _points;
};

