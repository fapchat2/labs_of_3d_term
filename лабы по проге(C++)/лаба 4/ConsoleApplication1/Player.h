#pragma once
#include "Pack.h"

class Player
{
public:
	Player();
	~Player();
	int getDollars();
	void setDollars(int d);
	Card* getCards();
	int getPoints();
	int getNumberOfCards();
	void addCard(Card card);

protected:
	Card* _cards;
	int _dollars;
	int _numberOfCards;
	int _numberOfPoints;

};

