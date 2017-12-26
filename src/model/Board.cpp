#include <model/Board.hpp>

using namespace std;

namespace model {

Board::Board(void) {
}

Board::~Board() {
	for (auto elem : decks) {
		delete elem.second;
	}
	for (auto elem : foundations) {
		delete elem.second;
	}
	for (auto elem : tableaus) {
		delete elem.second;
	}
}

bool Board::isAllowedPush(std::string origin, std::string target) {
	assert(
			(isFoundationCell(target) or isTableauCell(target))
					and (existsCellKey(origin) and !isFoundationCell(origin)));

	Card card = getCard(origin);
	if (isFoundationCell(target))
		return foundations[target]->isAllowedPush(card);
	return tableaus[target]->isAllowedPush(card);
}

void Board::push(std::string target, const Card& card) {
	assert(isFoundationCell(target) or isTableauCell(target));
	if (isFoundationCell(target)) {
		foundations[target]->push(card);
	} else {
		tableaus[target]->push(card);
	}
}

void Board::push(std::string target, CardList& cards) {
	assert(isFoundationCell(target) or isTableauCell(target));
	if (isFoundationCell(target)) {
		foundations[target]->pushList(cards);
	} else {
		tableaus[target]->pushList(cards);
	}
}

Card& Board::getCard(std::string target) {
	assert(existsCellKey(target));
	if (isFoundationCell(target))
		return foundations[target]->getCard();
	if (isTableauCell(target))
		return tableaus[target]->getCard();
	return decks[target]->getCard();

}

Card& Board::getDeckCard() {
	return decks[DECK]->getCard();
}

void Board::showNewDeckCard() {
	decks[DECK]->pop();
	decks[DECK]->turnCard();
}
void Board::showCard(std::string target) {
	assert(isFoundationCell(target) or isTableauCell(target));
	if (isFoundationCell(target)) {
		foundations[target]->turnCard();
	} else {
		tableaus[target]->turnCard();
	}
}

void Board::discardDeckCard() {
	decks[DECK]->discardCardTo(*decks[WASTE]);
}

CardList& Board::getCardSubList(std::string target, int length) {
	assert(isTableauCell(target));
	return *(tableaus[target]->getSubList(length));
}

void Board::pop(std::string target) {
	if (isFoundationCell(target)) {
		foundations[target]->pop();
	} else if (isTableauCell(target)) {
		tableaus[target]->pop();
	} else {
		decks[target]->pop();
	}
}

void Board::pop(std::string target, int length) {
	if (isFoundationCell(target))
		foundations[target]->popList(length);
	if (isTableauCell(target))
		tableaus[target]->popList(length);
}

void Board::restoreDeckFromWaste() {
	decks[DECK]->restoreFromWaste(*decks[WASTE]);
}

bool Board::isFoundationCell(std::string key) const {
	return existsCellKey(key, FOUNDATIONS_REG_EXP);
}

bool Board::isTableauCell(std::string key) const {
	return existsCellKey(key, TABLEAUS_REG_EXP);
}

bool Board::isDeckCell(std::string key) const {
	return existsCellKey(key, DECKS_REG_EXP);
}

bool Board::existsCellKey(std::string key, const char regexp) const {
	return (existsCellKey(key) and (key.at(0) == regexp));
}

bool Board::existsCellKey(std::string key) const {
	bool status = false;
	for (auto& v : foundations) {
		if (v.first == key)
			status = true;
	}
	for (auto& v : tableaus) {
		if (v.first == key)
			status = true;
	}
	for (auto& v : decks) {
		if (v.first == key)
			status = true;
	}
	return status;
}

void Board::setDecks(const std::map<std::string, Deck*>& decks) {
	this->decks = decks;
}

void Board::setFoundations(
		const std::map<std::string, Foundation*>& foundations) {
	this->foundations = foundations;
}

void Board::setTableaus(const std::map<std::string, Tableau*>& tableaus) {
	this->tableaus = tableaus;
}

const std::string& Board::getDeckName() const {
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

const std::string& Board::getWasteName() const {
	return WASTE;
}

bool Board::isCompleteBoard() {
	bool status = true;
	for (auto& v : foundations) {
		if (!v.second->isFull())
			status = false;
	}
	return status;
}

bool Board::isEmpty(std::string key) {
	assert(existsCellKey(key));
	if (isFoundationCell(key))
		return foundations[key]->isEmpty();
	if (isTableauCell(key))
		return tableaus[key]->isEmpty();
	return decks[key]->isEmpty();
}

int Board::size(std::string key) {
	assert(existsCellKey(key));
	if (isFoundationCell(key))
		return foundations[key]->size();
	if (isTableauCell(key))
		return tableaus[key]->size();
	return decks[key]->size();
}

void Board::flip(std::string key) {
	assert(existsCellKey(key));
	if (isFoundationCell(key)) {
		foundations[key]->turnCard();
	} else if (isTableauCell(key)) {
		tableaus[key]->turnCard();
	} else {
		decks[key]->turnCard();
	}
}

ostream& operator<<(ostream &ostrm, const Board* board) {
	ostrm << "Decks:" << endl;
	for (auto &v : board->decks) {
		ostrm << v.second;
	}
	ostrm << endl;
	ostrm << "Foundations:" << endl;
	for (auto &v : board->foundations) {
		ostrm << v.second;
	}
	ostrm << endl;
	ostrm << "Tableaus:" << endl;
	for (auto &v : board->tableaus) {
		ostrm << v.second;
	}
	return ostrm;
}

} /* namespace model */
