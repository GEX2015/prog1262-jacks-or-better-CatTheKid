//
//     Cat Fortman
//	   May 03 2016
//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "Card.h"
#include <set>
#include <map>
#include <iostream>

Card::Card(Face f, Suit s) : face(f), suit(s) //nitializes the card
{
}

Card::Card(const Card& card) // copy constructor for card
{
	face = card.face;
	suit = card.suit;
}

std::string Card::toString() const // returns string of face and suit values
{
	return Card::faceNames.at(face) + " of " + Card::suitNames.at(suit);
}
const std::set<Suit> Card::suits{ Suit::CLUB, Suit::DIAMOND, Suit::HEART, Suit::SPADE }; // all suit options

const std::set<Face> Card::faces{ // all face options
	Face::ACE, 
	Face::TWO, 
	Face::THREE, 
	Face::FOUR, 
	Face::FIVE,
	Face::SIX, 
	Face::SEVEN, 
	Face::EIGHT, 
	Face::NINE, 
	Face::TEN, 
	Face::JACK, 
	Face::QUEEN, 
	Face::KING };

const std::map<Suit, std::string> Card::suitNames{ {Suit::CLUB,"Clubs"},{Suit::DIAMOND,"Diamonds"}, {Suit::HEART,"<3"}, {Suit::SPADE,"Spades"} };
const std::map<Face, std::string> Card::faceNames // all face names
{
	{Face::ACE,"A"},
	{Face::TWO,"2"},
	{Face::THREE,"3"},
	{Face::FOUR, "4"},
	{Face::FIVE,"5"},
	{Face::SIX, "6" },
	{Face::SEVEN,"7" },
	{Face::EIGHT,"8" },
	{Face::NINE,"9" },
	{Face::TEN, "10" },
	{Face::JACK, "J" },
	{Face::QUEEN,"Q" },
	{Face::KING, "K"}};


bool Card::operator< (const Card& b) const // checks the value of cards 
{
	if (face < b.face) return true;
	else if ((face == b.face) && (suit < b.suit)) return true;
	else return false;
}

Card& Card::operator= (const Card& b) 
{
	Card temp(b); // Copy-constructor -- RAII
	temp.swap(*this); // Non-throwing swap

	return *this;
}

void Card::swap(Card& c) // swaps the face and suit of cards
{
	std::swap(this->face, c.face);
	std::swap(this->suit, c.suit);
}

std::ostream& operator<<(std::ostream& os, const Card& c) // overloads the output stream to show face and suit values
{
	os << Card::faceNames.at(c.face) + " of " + Card::suitNames.at(c.suit);
	return os;
}




