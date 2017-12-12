#include <utils/FrenchDeckUtils.hpp>
#include <model/Foundation.hpp>

using namespace std;
using namespace utils;

namespace model {

Foundation::Foundation(string name) :
		BoardCell(name) {
}

Foundation::Foundation(string name, const CardList& cards) :
		BoardCell(name, cards) {
}

Foundation::Foundation(Foundation& Foundation) :
		BoardCell(Foundation) {
}

Foundation::~Foundation() {
}

void Foundation::push(const Card& card) {
	this->cards.pushFront(card);
}

bool Foundation::isAllowedPush(const Card& card) {
	return true;
}

bool Foundation::isFull() {
	return FrenchDeckUtils::instance()->isKing(this->getCard());
}

} /* namespace model */
