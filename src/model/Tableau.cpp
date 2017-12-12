#include <model/Tableau.hpp>
#include <utils/FrenchDeckUtils.hpp>

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
	this->cards.pushFront(card);
}

bool Tableau::isAllowedPush(const Card& card) {
	return true;
}

bool Tableau::isFull() {
	return FrenchDeckUtils::instance()->isAce(this->getCard());
}

const CardList Tableau::getSubList(int length) {
	return this->cards.getSubList(length);
}

bool Tableau::isFullOfInvisible() {
	return this->cards.isFullOfInvisible();
}

} /* namespace model */
