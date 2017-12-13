#include <model/Board.hpp>
#include <model/Tableau.hpp>
#include <model/Deck.hpp>

using namespace std;

namespace model {

Board::Board() {
}

Board::~Board() {
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
	deck->restoreFromWaste(make_shared<Deck>(cells[WASTE]));
}

void Board::clearAll() {
	for (auto& cell: cells) {
		cell.second->clearAll();
	}
}

bool Board::isFoundationCell(std::string target) {
	return existsCellKey(FOUNDATIONS_REG_EXP);
}

bool Board::isTableauCell(std::string target) {
	return existsCellKey(TABLEAUS_REG_EXP);
}

bool Board::isDeckCell(std::string target) {
	return existsCellKey(DECKS_REG_EXP);
}

bool Board::existsCellKey(std::string target) {
	return target != string::npos;
}

} /* namespace model */
