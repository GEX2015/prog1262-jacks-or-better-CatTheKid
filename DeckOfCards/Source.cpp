//
//     Cat Fortman
//	   May 03 2016
//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



#include <iostream>
#include <set>
#include <vector>
#include "Card.h"
#include <string>
#include <ctime>
#include "Deck.h"
#include "Hand.h"

int main(int argc, char *argv[])
{

	srand(static_cast<unsigned int>(time(0)));
	/*Card c(Face::ACE, Suit::HEART);

	std::cout << c.toString() << std::endl;
	system("pause");

	(std::set<Card> deck;

	for (auto f : Card::faces)
	{
		for (auto s : Card::suits)
		{
			deck.insert(Card(f, s));1
		}
	}*/

	
	
		Deck deck; // creates deck of cards

		deck.shuffle();  // shuffles the deck

		Hand hand;  // instantiates a hand of cards

		hand.addCard(deck.draw());

		std::cout << hand;  // show cards

		/*if (hand.isRoyalFlush())
		{
			std::cout << "You have a ROYAL FLUSH!!!" << std::endl;
		}*/
	

		hand.clear(); // clears the hand

		system("pause");
	}

