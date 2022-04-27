#include "Game.h"
Game::Game()
{
	Pack pack1;
	Pack pack2;
	Pack pack3;
	Pack pack4;

	Card* cardsOfPack1 = pack1.getCards();
	Card* cardsOfPack2 = pack2.getCards();
	Card* cardsOfPack3 = pack3.getCards();
	Card* cardsOfPack4 = pack4.getCards();

	Card* _cards = new Card[208];

	int j = 0;
	for (size_t i = 0; i < 52; i++)
	{
		_cards[j] = cardsOfPack1[i];
		++j;
	}
	for (size_t i = 0; i < 52; i++)
	{
		_cards[j] = cardsOfPack2[i];
		j++;
	}
	for (size_t i = 0; i < 52; i++)
	{
		_cards[j] = cardsOfPack3[i];
		j++;
	}
	for (size_t i = 0; i < 52; i++)
	{
		_cards[j] = cardsOfPack4[i];
		j++;
	}


	srand(time(0));
	for (int i = 0; i < 208; ++i)
		std::swap(_cards[i], _cards[std::rand() % 208]);

	Player _player;
	Dealer _dealer(_player, _cards);
	int i = 0;
	_dealer.bet();
	_dealer.takeCard(_cards[i]);

	_player.addCard(_cards[++i]);

	_player.addCard(_cards[++i]);

	std::cout << "Do you want to make a surrender? (1-yes)(0-no) " << std::endl;
	int answer;
	std::cin >> answer;
	if (answer)
	{
		_player.setDollars(_player.getDollars() + _dealer.getDollars() / 2);
	} 
	else 
	{
		while (_player.getPoints() < 21 && _player.getNumberOfCards() < 5)
		{
			std::cout << "Do you want to take another card? (1-yes)(0-no) " << std::endl;
			int answer;
			std::cin >> answer;
			if (answer)
			{
				if (_player.getNumberOfCards() == 5)
				{
					std::cout << "Player has maximum cards " << std::endl;
				}
				_player.addCard(_cards[++i]);
			}
			else
			{
				break;
			}

		}



		if (_player.getCards()[0].getNumber() + _player.getCards()[1].getNumber() == 21)
		{
			std::cout << "Player has blackjack!!! " << std::endl;
			_player.setDollars(_player.getDollars() + _dealer.getDollars() + _dealer.getDollars() / 2);
		}
		else if (_player.getPoints() > 21)
		{
			try
			{
				throw _player.getPoints();
			}
			catch (int a)
			{
				std::cerr << "Player has over maximum: " << a << " points." << std::endl;
			}
		}
		else
		{
			_dealer.takeCard(_cards[++i]);
			if (_dealer.getPoints() < 17)
			{
				_dealer.takeCard(_cards[++i]);
			}



			if (_dealer.getCards()[0].getNumber() + _dealer.getCards()[1].getNumber() == 21)
			{
				std::cout << "Dealer has blackjack!!! " << std::endl;
				std::cout << "game over! " << std::endl;
			}
			else if (_dealer.getPoints() > 21)
			{
				try
				{
					throw _dealer.getPoints();
				}
				catch (int a)
				{
					std::cerr << "Dealer has over maximum: " << a << " points." << std::endl;
				}
			}
			else if (_dealer.getPoints() > _player.getPoints())
			{
				std::cout << "Dealer has more points!!! " << std::endl;
				std::cout << "game over! " << std::endl;
			}
			else if (_dealer.getPoints() < _player.getPoints())
			{
				std::cout << "Player has more points!!! " << std::endl;
				_player.setDollars(_player.getDollars() + _dealer.getDollars() * 2);

			}
			else if (_dealer.getPoints() == _player.getPoints())
			{
				std::cout << "A player has as many points as a dealer " << std::endl;
				_player.setDollars(_player.getDollars() + _dealer.getDollars());

			}
		}
	}

	

	//end:
		std::cout << "Now player has  " << _player.getDollars() << " dollars " << std::endl;
}


Game::~Game()
{
	delete[] _cards;
}

