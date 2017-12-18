#include <model/Board.hpp>
#include <model/Tableau.hpp>
#include <model/Deck.hpp>

using namespace std;

namespace model {

Board::Board() {
}

Board::~Board() {
}

void Board::setCells(
		const std::map<std::string, std::shared_ptr<BoardCell> >& cells) {
	this->cells = cells;
}

void Board::push(std::string target, const Card& card) {
	cells[target]->push(card);
}

void Board::push(std::string target, const CardList& cards) {
	auto tableau = dynamic_pointer_cast<Tableau>(cells[target]);
	tableau->push(cards);
}

void Board::pop(std::string target) {
	cells[target]->pop();
}

void Board::pop(std::string target, int length) {
	cells[target]->popList(length);
}

void Board::turnCard(std::string target) {
	cells[target]->turnCard();
}

bool Board::isEmpty(std::string target) {
	return cells[target]->isEmpty();
}

const CardList Board::getSubList(std::string target, int length) {
	auto tableau = dynamic_pointer_cast<Tableau>(cells[target]);
	return tableau->getSubList(length);
}

int Board::getCountOfCompleteFoundations() {
	int sum = 0;
	for (auto& found : cells) {
		if (isFoundationCell(found.first) and found.second->isFull())
			sum++;
	}
	return sum;
}

bool Board::isCompleteBoard() {
	return getCountOfCompleteFoundations() == 4;
}

void Board::restoreDeckFromWaste() {
	auto deck = dynamic_pointer_cast<Deck>(cells[DECK]);
	deck->restoreFromWaste(deck);
}

void Board::clearAll() {
	for (auto& cell : cells) {
		cell.second->clearAll();
	}
}

bool Board::isFoundationCell(std::string key) {
	return existsCellKey(key, FOUNDATIONS_REG_EXP);
}

bool Board::isTableauCell(std::string key) {
	return existsCellKey(key, TABLEAUS_REG_EXP);
}

bool Board::isDeckCell(std::string key) {
	return existsCellKey(key, DECKS_REG_EXP);
}

bool Board::existsCellKey(std::string key, const char regexp) {
	return key.find(regexp) != string::npos;
}

const std::string& Board::getDeck() const {
	return DECK;
}

const char Board::getDecksRegExp() const {
	return DECKS_REG_EXP;
}

const char Board::getFoundationsRegExp() const {
	return FOUNDATIONS_REG_EXP;
}

const char Board::getTableausRegExp() const {
	return TABLEAUS_REG_EXP;
}

const std::string& Board::getWaste() const {
	return WASTE;
}

} /* namespace model */
