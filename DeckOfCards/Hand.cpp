//
//     Cat Fortman
//	   May 03 2016
//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "Hand.h"
#include "Deck.h"
#include "Card.h"
#include <map>
#include <algorithm>

Hand::Hand()
{
}


Hand::~Hand()
{
}


void Hand::clear() // clears all the cards in hand
{
	_hand.clear();
}

void Hand::addCard(CardPtr c) // adds a card to hand
{
	_hand.push_back(c);
}


std::ostream& operator<<(std::ostream& os, const Hand& h)  // overloads the cout operator 
{
	if (h.size() == 0)
	{
		os << "I'm sorry the hand is empty \n";
	}

	else
	{
		for (int i = 0; i < h.size(); i++)
		{
			os << *h._hand[i] << std::endl;
		}
	}
	return os;
}


bool Hand::isPair()					// returns boolean if there is a pair and number
{
	bool isPair = false;
	
	/*auto pairLambda = [](std::pair<Face, int> e) {
		(e.second == 2);
	};*/

	std::map<Face, int> h;


		for (int i = 0; i < _hand.size(); i++)
		{
			h[_hand[i]->face]++;
		}

		int pairCount = count_if(h.begin(), h.end(), [](std::pair<Face, int> e) {return (e.second == 2); });
		if (pairCount == 1)
		{
			isPair = true;
		}

		return isPair;

}

bool Hand::isTwoPair()					// returns boolean if there is a pair and number
{
	bool isTwoPair = false;

	/*auto pairLambda = [](std::pair<Face, int> e) {
	(e.second == 2);
	};*/

	std::map<Face, int> h;


	for (int i = 0; i < _hand.size(); i++)
	{
		h[_hand[i]->face]++;
	}

	int pairCount = count_if(h.begin(), h.end(), [](std::pair<Face, int> e) {return (e.second == 2); });
	if (pairCount > 1)
	{
		isTwoPair = true;
	}

	return isTwoPair;

}

bool Hand::isThreeOfAKind()					// returns boolean if there is a pair and number
{
	bool isThree = false;

	/*auto pairLambda = [](std::pair<Face, int> e) {
	(e.second == 2);
	};*/

	std::map<Face, int> h;

		for (int i = 0; i < _hand.size(); i++)
		{
			h[_hand[i]->face]++;
		}

		int threeCount = count_if(h.begin(), h.end(), [](std::pair<Face, int> e) {return (e.second == 3); });
		if (threeCount > 0)
		{
			isThree = true;
		}

		return isThree;

}

bool Hand::isFourOfAKind()					// returns boolean if there is a 4 of a kind
{
	bool isFour = false;

	/*auto pairLambda = [](std::pair<Face, int> e) {
	(e.second == 2);
	};*/

	std::map<Face, int> h;


	
		for (int i = 0; i < _hand.size(); i++)
		{
			h[_hand[i]->face]++;
		}

		int fourCount = count_if(h.begin(), h.end(), [](std::pair<Face, int> e) {return (e.second == 4); });
		if (fourCount > 0)
		{
			isFour = true;
		}

		return isFour;
}



bool Hand::isFullHouse()					// returns boolean if there is a fullhouse
{
	return(isPair() && isThreeOfAKind());	
}

bool Hand::isFlush()					// returns boolean if there is a flush
{
	bool isFlush = false;

	/*auto pairLambda = [](std::pair<Face, int> e) {
	(e.second == 2);
	};*/

	std::set<Suit> h;



	for (int i = 0; i < _hand.size(); i++)
	{
		h.insert(_hand[i]->suit);
	}


	if (h.size() == 1)
	{
		isFlush = true;
	}

	return isFlush;
}

bool Hand::isStraight()					// returns boolean if there is a flush
{
	bool isStraight = false;

	/*auto pairLambda = [](std::pair<Face, int> e) {
	(e.second == 2);
	};*/

	std::set<int> h;                           // set holds hand values
	

	for (int i = 0; i < _hand.size(); i++)     // inserts the face values as ints in the set
	{
		h.insert((int)_hand[i]->face);
	}

	auto first = h.begin();					   // starts the beginning of the set	
	auto last = h.end();					   // states the end of the set

	last--;									   // gets the last value of the set

	if (h.size() == 5)						   // if the hand size is 5
	{
		if (*first == (*last - 4))			   // if the end subtracted by the beginning equals the first card
		{
			isStraight = true;				   // set as true
		}
	}

	if (*first == 0)						   // if the first card is an ace take in account an ace as a higher value
	{
		h.insert(13);						   // insert phony ace
	}

	last++;

	if (h.size() == 6)						   // test new hand size
	{
		*first++;
		if (*first == (*last - 4))
		{
			isStraight = true;
		}
	}

	return isStraight;
}

bool Hand::isStraightFlush()
{
	return(isStraight() && isFlush());
}

bool Hand::isRoyalFlush()
{
	bool isRF = false;

	std::set<int> h;

	if (isStraightFlush())
	{
		for (int i = 0; i < _hand.size(); i++)     // inserts the face values as ints in the set
		{
			h.insert((int)_hand[i]->face);
		}
	}

	auto start = h.begin();

	if (*start == 0)
	{
		h.insert(13);
	}

	auto last = h.end();
	last--;

	if (*last == 13)
	{
		last--;
		if (*last == 12)
		{
			isRF = true;
		}
	}

 	return isRF;
}











