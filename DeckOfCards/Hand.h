//
//     Cat Fortman
//	   May 03 2016
//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once
#include "Card.h"
#include "Deck.h"
#include <vector>
#include <memory>
#include <iostream>

using CardPtr = std::shared_ptr<Card>;

class Hand
{
public:
	Hand(); // no arg hand constructor
	~Hand();

	void clear(); // clears the hand of cards

	void addCard(CardPtr c); // adds a card to the hand

	int size() const { return _hand.size(); } // returns the size of the hand of cards

	friend std::ostream& operator<<(std::ostream& os, const Hand& h); // overloads the cout operator for hand
	
	bool isPair(); // returns true for a pair of cards
	bool isTwoPair(); // returns true if there is a two pair
	bool isThreeOfAKind(); // returns true for a three of a kind
	bool isFourOfAKind(); // returns true for four of a kind
	bool isFullHouse(); // returns true if you have a full house
	bool isFlush(); // returns true for a flush
	bool isStraight(); // returns true if it is a straight
	bool isStraightFlush(); // checks for a straight flush
	bool isRoyalFlush(); // returns true if it is a royal flush

private:
	std::vector<CardPtr> _hand; // holds the cards in a hand vector
	
};
std::ostream& operator<<(std::ostream& os, const Hand& h);
