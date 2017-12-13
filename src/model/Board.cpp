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

bool Board::isFoundationCell(std::string target) {
	return target.find(FOUNDATIONS_REG_EXP) != string::npos;
}

bool Board::isCompleteBoard() {
	return getCountOfCompleteFoundations() == 4;
}

void Board::clearAll() {
//	TO CLEAN;
}

void Board::restoreDeckFromWaste() {
	auto deck = dynamic_pointer_cast<Deck>(cells[DECK]);
	auto waste = dynamic_pointer_cast<Deck>(cells[WASTE]);
	deck->restoreFromWaste(*waste);
}

void Board::visitPushList(Tableau& tableau, const CardList& cards) {
	tableau.push(cards);
}

const CardList Board::visitSublist(Deck& deck, int length) {
	return deck.getSubList(length);
}

const CardList Board::visitSublist(Tableau& tableau, int length) {
	return tableau.getSubList(length);
}

} /* namespace model */
