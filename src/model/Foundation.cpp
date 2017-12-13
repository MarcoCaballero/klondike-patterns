#include <model/Foundation.hpp>
#include <model/utils/FrenchDeckUtils.hpp>

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
	if (isEmpty())
		return FrenchDeckUtils::instance()->isAce(getCard());
	return checkSuit(getCard().getSuit()) and checkValue(getCard().getValue());

}

bool Foundation::checkSuit(int suit) {
	return getCard().isEqualSuit(suit);
}

bool Foundation::checkValue(int value) {
	return getCard().isFollowingValue(value);
}

bool Foundation::isFull() {
	return FrenchDeckUtils::instance()->isKing(getCard());
}

} /* namespace model */
