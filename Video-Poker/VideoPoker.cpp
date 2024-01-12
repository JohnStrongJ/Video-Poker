#include <array>
#include <iostream>
#include <string>
#include <algorithm>
#include <random>
#include <chrono>

/*
 * Video Poker (WIP)
 * Currently shuffles and prints a deck of cards.
 *
 * John Strong
 */

// Represent a card as a value and a suit
enum values { ACE = 1, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING };
enum suit { HEARTS, DIAMONDS, CLUBS, SPADES };

class Card
{
private:
	int value;
	int suit;

public:
	Card(int value, int suit)
	{
		this->value = value;
		this->suit = suit;
	}

	int getValue() {
		return value;
	}

	int getSuit() {
		return suit;
	}
};

// The player's hand contains five cards, drawn from the top of the deck. (not used currently)
class Hand
{
private:
	std::string card1;
	std::string card2;
	std::string card3;
	std::string card4;
	std::string card5;

public:
	Hand() {};
};

// Not used currently.
class Player
{
	int balance;
	Hand hand;
};

// Dealer has a 52 card deck which can be shuffled.
class Dealer
{
private:
	std::array<Card, 52> deck{
		Card(ACE, HEARTS),
		Card(TWO, HEARTS),
		Card(THREE, HEARTS),
		Card(FOUR, HEARTS),
		Card(FIVE, HEARTS),
		Card(SIX, HEARTS),
		Card(SEVEN, HEARTS),
		Card(EIGHT, HEARTS),
		Card(NINE, HEARTS),
		Card(TEN, HEARTS),
		Card(JACK, HEARTS),
		Card(QUEEN, HEARTS),
		Card(KING, HEARTS),
		Card(ACE, DIAMONDS),
		Card(TWO, DIAMONDS),
		Card(THREE, DIAMONDS),
		Card(FOUR, DIAMONDS),
		Card(FIVE, DIAMONDS),
		Card(SIX, DIAMONDS),
		Card(SEVEN, DIAMONDS),
		Card(EIGHT, DIAMONDS),
		Card(NINE, DIAMONDS),
		Card(TEN, DIAMONDS),
		Card(JACK, DIAMONDS),
		Card(QUEEN, DIAMONDS),
		Card(KING, DIAMONDS),
		Card(ACE, CLUBS),
		Card(TWO, CLUBS),
		Card(THREE, CLUBS),
		Card(FOUR, CLUBS),
		Card(FIVE, CLUBS),
		Card(SIX, CLUBS),
		Card(SEVEN, CLUBS),
		Card(EIGHT, CLUBS),
		Card(NINE, CLUBS),
		Card(TEN, CLUBS),
		Card(JACK, CLUBS),
		Card(QUEEN, CLUBS),
		Card(KING, CLUBS),
		Card(ACE, SPADES),
		Card(TWO, SPADES),
		Card(THREE, SPADES),
		Card(FOUR, SPADES),
		Card(FIVE, SPADES),
		Card(SIX, SPADES),
		Card(SEVEN, SPADES),
		Card(EIGHT, SPADES),
		Card(NINE, SPADES),
		Card(TEN, SPADES),
		Card(JACK, SPADES),
		Card(QUEEN, SPADES),
		Card(KING, SPADES)
	};

public:
	Dealer() {};
	void shuffle() {
		std::random_device rd;
		std::mt19937 g(rd());
		std::shuffle(deck.begin(), deck.end(), g);
	};

	void printDeck() {
		std::cout << "Deck:" << '\n';
		for (Card card : deck)
		{
			std::cout << card.getValue() << ' ' << card.getSuit() << '\n';
		}
	}
};

int main()
{
	Dealer dealer = Dealer();
	dealer.printDeck();
	dealer.shuffle();
	dealer.printDeck();

	return 0;
}