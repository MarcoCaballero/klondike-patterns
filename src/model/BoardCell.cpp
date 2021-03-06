#include <model/BoardCell.hpp>

using namespace std;

namespace model {

BoardCell::BoardCell(std::string name) :
		name(name) {
}

BoardCell::BoardCell(std::string name, const CardList& cards) :
		name(name), cards(cards) {
}
BoardCell::BoardCell(BoardCell& BoardCell) :
		name(BoardCell.name), cards(BoardCell.cards) {
}

BoardCell::~BoardCell() {
}

Card& BoardCell::getCard()  {
	return cards.getCard();
}

std::vector<Card>& BoardCell::getCards()  {
	return cards.getCards();
}

void BoardCell::turnCard() {
	this->getCard().setVisibility(true);
}

void BoardCell::pushList(CardList& cards) {
	this->cards.pushFront(cards);
}

void BoardCell::pop() {
	cards.pop();
}

void BoardCell::popList(int length) {
	cards.popList(length);
}

bool BoardCell::isEmpty() {
	return cards.isEmpty();
}

int BoardCell::size() {
	return cards.size();
}

void BoardCell::clearAll() {
	while (!isEmpty()) {
		cards.pop();
	}
}

const std::string& BoardCell::getName() const {
	return name;
}

ostream& operator<<(ostream &strm, const BoardCell &boardCell) {
	return strm << "(" << boardCell.name << ")" << " -> " << boardCell.cards
			<< endl;
}

ostream& operator<<(ostream &strm, const BoardCell* boardCell) {
	return strm << "(" << boardCell->name << ")" << " -> " << boardCell->cards
			<< endl;
}

} /* namespace model */
