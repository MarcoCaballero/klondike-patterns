#include <model/utils/FrenchDeckUtils.hpp>

using namespace model;
using namespace std;

namespace utils {

FrenchDeckUtils* FrenchDeckUtils::frenchDeckUtils = NULL;
const string FrenchDeckUtils::ICON_HEARTS = "\u2665";
const string FrenchDeckUtils::ICON_SPADES = "\u2660";
const string FrenchDeckUtils::ICON_DIAMS = "\u2666";
const string FrenchDeckUtils::ICON_CLUBS = "\u2663";
const string FrenchDeckUtils::KING = "K";
const string FrenchDeckUtils::ACE = "A";
const int FrenchDeckUtils::FULL_DECK = 52;

FrenchDeckUtils::FrenchDeckUtils() {
}

FrenchDeckUtils::~FrenchDeckUtils() {
}

FrenchDeckUtils* FrenchDeckUtils::instance() {
	if (!frenchDeckUtils)
		frenchDeckUtils = new FrenchDeckUtils;
	return frenchDeckUtils;
}

string FrenchDeckUtils::getIcon(const Card& card) const {
	switch (card.getSuit()) {
	case 1:
		return ICON_CLUBS;
	case 2:
		return ICON_DIAMS;
	case 3:
		return ICON_SPADES;
	case 4:
		return ICON_HEARTS;
	default:
		return nullptr;
	}
}

string FrenchDeckUtils::getValue(const Card& card) const {
	switch (card.getValue()) {
	case 1:
		return "A";
	case 11:
		return "J";
	case 12:
		return "Q";
	case 13:
		return "K";
	default:
		return to_string(card.getValue());
	}
}

string FrenchDeckUtils::getConsoleView(const Card& card) const {
	if (card.isVisible())
		return "[" + getValue(card) + getIcon(card) + "]";
	return "|]";
}

bool FrenchDeckUtils::isKing(const model::Card& card) const {
	return getValue(card) == KING;
}

bool FrenchDeckUtils::isAce(const model::Card& card) const {
	return getValue(card) == ACE;
}

bool FrenchDeckUtils::isFullDeck(const int size) const {
	return size == FULL_DECK;
}

} /* namespace model */
