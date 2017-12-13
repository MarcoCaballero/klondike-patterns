#include <model/Card.hpp>
#include <model/utils/FrenchDeckUtils.hpp>

using namespace std;
using namespace utils;

namespace model {

Card::Card(int value, int suit, int color) {
	this->value = value;
	this->suit = suit;
	this->color = color;
	this->visibility = false;
}

Card::Card(const Card &card) :
		value(card.value), suit(card.suit), color(card.color), visibility(
				card.visibility) {
}

Card::~Card() {
}

int Card::getColor() const {
	return color;
}

void Card::setColor(int color) {
	this->color = color;
}

int Card::getSuit() const {
	return suit;
}

int Card::getValue() const {
	return value;
}

bool Card::isVisible() const {
	return visibility;
}

void Card::setVisibility(bool visibility) {
	this->visibility = visibility;
}

bool Card::isPreviousValue(int value) const {
	return compareValue(value) == 1;
}

bool Card::isFollowingValue(int value) const {
	return compareValue(value) == -1;
}

bool Card::isEqualSuit(int suit) const {
	return this->suit == suit;
}

bool Card::isEqualColor(int color) const {
	return this->color == color;
}

int Card::compareValue(int value) const {
	return this->value - value;
}

ostream& operator<<(ostream &strm, const Card &card) {
	return strm << FrenchDeckUtils::instance()->getConsoleView(card);
}

} /* namespace controller */
