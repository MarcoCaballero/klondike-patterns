#include <ctime>
#include <cstdlib>
#include <algorithm>
#include <model/Deck.hpp>
#include <model/utils/FrenchDeckUtils.hpp>

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

void Deck::push(const Card& card) {
	cards.pushBack(card);
}

bool Deck::isAllowedPush(const Card& card) {
	return true;
}

bool Deck::isFull() {
	return FrenchDeckUtils::instance()->isFullDeck(size());
}

bool Deck::isFullOfInvisible() {
	return cards.isFullOfInvisible();
}

void Deck::init() {
	shuffle();
	cards.getCard().setVisibility(true);
}

void Deck::shuffle() {
	srand(time(0));
	random_shuffle(cards.getCards().begin(), cards.getCards().end());
}

void Deck::restoreFromWaste(Deck& waste) {
	assert(!waste.isEmpty());
	while (!waste.isEmpty()) {
		push(waste.getCard());
		waste.pop();
	}
}

void Deck::discardCardTo(Deck& waste) {
	assert(!isEmpty());
	waste.push(getCard());
	pop();
	turnCard();
}

CardList* Deck::getSubList(int length) {
	assert(size() >= length);
	return cards.getSubList(length);
}

} /* namespace model */
