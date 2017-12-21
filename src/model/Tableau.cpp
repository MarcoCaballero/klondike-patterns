#include <model/Tableau.hpp>
#include <model/utils/FrenchDeckUtils.hpp>

using namespace std;
using namespace utils;

namespace model {

Tableau::Tableau(string name) :
		BoardCell(name) {
}

Tableau::Tableau(string name, const CardList& cards) :
		BoardCell(name, cards) {
}

Tableau::Tableau(Tableau& tableau) :
		BoardCell(tableau) {
}

Tableau::~Tableau() {
}

void Tableau::push(const Card& card) {
	cards.pushFront(card);
}

bool Tableau::isAllowedPush(const Card& card) {
	if (isEmpty())
		return FrenchDeckUtils::instance()->isKing(card);
	return checkColor(card.getColor()) and checkValue(card.getValue());
}

bool Tableau::checkColor(int color) {
	return !getCard().isEqualColor(color);
}

bool Tableau::checkValue(int value) {
	return getCard().isPreviousValue(value);
}

bool Tableau::isFull() {
	return FrenchDeckUtils::instance()->isAce(getCard());
}

CardList* Tableau::getSubList(int length) {
	return cards.getSubList(length);
}

bool Tableau::isFullOfInvisible() {
	return cards.isFullOfInvisible();
}

} /* namespace model */
