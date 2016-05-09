#include "Deck.h"
#include "Card.h"
#include <vector>
#include <String>
#include <map>
#include <set>
#include <iostream>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <memory>

//
//     Cat Fortman
//	   May 03 2016
//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


Deck::Deck()  
{
	for (auto f: Card::faces) // creates the deck with card faces and suits
	{
		for (auto s: Card::suits)
		{
			deck.push_back(std::make_shared<Card>(Card(f, s)));
		}
	}

	_topDeck = deck.size() - 1;
}


Deck::~Deck()
{
}

void Deck::shuffle() // shuffles the deck with rand
{
	//std::random_shuffle(deck.begin(), deck.end());
	for (int i = 1; i != deck.size(); i++)
	{
		std::swap(deck[i], deck[i + (rand() % (deck.size()-i))]);
	}
		
}

bool Deck::isEmpty() // returns true for empty deck
{
	if (deck.empty())
	{
		return true;
	}
	else
	{
		return false;
	}
}

CardPtr Deck::draw()  // draws the top the card
{
	return deck.at(_topDeck--);
}

