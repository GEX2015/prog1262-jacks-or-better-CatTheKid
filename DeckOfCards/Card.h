//
//     Cat Fortman
//	   May 03 2016
//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once
#include <map>
#include <set>
#include <iostream>
#include <string>

enum class Suit { CLUB, DIAMOND, HEART, SPADE };
enum class Face { ACE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING };

struct Card 
{
	Card(Face f, Suit s); // constructs a card
	Card(const Card& card); // copy constructs a card

	Suit suit;
	Face face;

	std::string toString() const; // makes an output for cards

	static const std::set<Suit> suits;
	static const std::set<Face> faces;

	static const std::map<Suit, std::string> suitNames;
	static const std::map<Face, std::string> faceNames;

	bool operator< (const Card& b) const;
	Card& operator= (const Card& b);

	void swap(Card& c); // swaps cards

	friend std::ostream& operator<<(std::ostream& os, const Card& c); // overloads the output operator for card
};

std::ostream& operator<<(std::ostream& os, const Card& c);