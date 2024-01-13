#include <array>
#include <iostream>
#include <string>
#include <algorithm>
#include <random>
#include <chrono>

/*
 * Video Poker (WIP)
 * Currently shuffles and prints a deck of cards, then deals five cards from the shuffled deck to the player's hand and prints the five cards.
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
	Card()
	{
		value = -1;
		suit = -1;
	}

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

// A hand contains five cards, drawn from the top of the deck.
class Hand
{
private:
	Card card1;
	Card card2;
	Card card3;
	Card card4;
	Card card5;

public:
	Hand() {};

	Hand(Card c1, Card c2, Card c3, Card c4, Card c5)
	{
		card1 = c1;
		card2 = c2;
		card3 = c3;
		card4 = c4;
		card5 = c5;
	}

	void setHand(Card c1, Card c2, Card c3, Card c4, Card c5)
	{
		card1 = c1;
		card2 = c2;
		card3 = c3;
		card4 = c4;
		card5 = c5;
	}

	void setCard(int n, Card card)
	{
		switch (n)
		{
		case 1:
			card1 = card;
			break;
		case 2:
			card2 = card;
			break;
		case 3:
			card3 = card;
			break;
		case 4:
			card4 = card;
			break;
		case 5:
			card5 = card;
			break;
		default:
			break;
		}
	}

	std::array<Card, 5> getCards()
	{
		return { card1, card2, card3, card4, card5 };
	}
};

// Not used currently.
class Player
{
private:
	double balance;
	Hand hand;

public:
	Player(double balance)
	{
		this->balance = balance;
		hand = Hand();
	}

	void setHand(Hand h)
	{
		hand = h;
	}

	void printHand()
	{
		std::cout << '\n' << "Printing the player's Hand: " << '\n';
		std::array<Card, 5> handArray = hand.getCards();
		for (Card card : handArray)
		{
			std::cout << card.getValue() << ' ' << card.getSuit() << '\n';
		}
	}
};

// Dealer has a 52 card deck which can be shuffled.
class Dealer
{
private:
	std::array<Card, 52> deck
	{
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
	void shuffle() 
	{
		std::random_device rd;
		std::mt19937 g(rd());
		std::shuffle(deck.begin(), deck.end(), g);
	};

	void printDeck() 
	{
		std::cout << "Deck:" << '\n';
		for (Card card : deck)
		{
			std::cout << card.getValue() << ' ' << card.getSuit() << '\n';
		}
	}

	// Deal the player five cards from the top of the deck.
	Player deal(Player player)
	{
		Hand hand = Hand(deck[0], deck[1], deck[2], deck[3], deck[4]);
		player.setHand(hand);
		return player;
	}
};

int main()
{
	Dealer dealer = Dealer();
	dealer.printDeck();
	dealer.shuffle();
	dealer.printDeck();
	Player player = Player(100);

	player = dealer.deal(player);
	player.printHand();

	return 0;
}