#pragma once
#include "Card.h"
//
//     Cat Fortman
//	   May 03 2016
//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <vector>
#include <memory>


using CardPtr = std::shared_ptr<Card>;

class Deck 
{
public:
	Deck();
	~Deck();

	void shuffle(); // function to shuffle deck
	
	bool isEmpty(); // checks if deck is empty

	CardPtr draw(); // draws a card


private:
	std::vector<CardPtr> deck; // creates vector of card pointers for deck
	int _topDeck; // top card of deck
	//std::vector<Card> deck;
};

