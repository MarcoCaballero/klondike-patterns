#include <ctime>
#include <cstdlib>
#include <algorithm>
#include <model/Deck.hpp>
#include <utils/FrenchDeckUtils.hpp>

using namespace std;
using namespace utils;

namespace model {

Deck::Deck(std::string name) :
		BoardCell(name) {
}

Deck::Deck(std::string name, CardList& cards) :
		BoardCell(name, cards) {
}

Deck::Deck(Deck& deck) :
		BoardCell(deck) {
}

Deck::~Deck() {
}

bool Deck::isFull() {
	return FrenchDeckUtils::instance()->isFullDeck(this->size());
}

bool Deck::isFullOfInvisible() {
	return this->cards.isFullOfInvisible();
}

void Deck::init() {
	shuffle();
	this->cards.getCard().setVisibility(true);
}

void Deck::shuffle() {
	srand(time(0));
	random_shuffle(this->cards.getCards().begin(),
			this->cards.getCards().end());
}

void Deck::restoreFromWaste(Deck& waste) {
	assert(isEmpty());
	assert(!waste.isEmpty());
	while (!waste.isEmpty()) {
		push(waste.getCard());
		waste.pop();
	}
}

void Deck::discardCard(Deck& waste) {
	assert(!isEmpty());
	waste.push(getCard());
	this->pop();
	this->turnCard();
}

const CardList Deck::getSubList(int length) {
	assert(size() >= length);
	return this->cards.getSubList(length);
}

void Deck::push(const Card& card) {
	this->cards.pushBack(card);
}

bool Deck::isAllowedPush(const Card& card) {
	return true;
}

} /* namespace model */
