#include <model/Board.hpp>

using namespace std;

namespace model {

Board::Board(void) {}

Board::~Board() {
	cout << "deleting..." << endl;
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
	if (isFoundationCell(target))
		foundations[target]->push(card);
	tableaus[target]->push(card);
}

void Board::push(std::string target, CardList& cards) {
	assert(isFoundationCell(target) or isTableauCell(target));
	if (isFoundationCell(target))
		foundations[target]->pushList(cards);
	tableaus[target]->pushList(cards);
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
	if (isFoundationCell(target))
		foundations[target]->turnCard();
	tableaus[target]->turnCard();
}

void Board::discardDeckCard() {
	decks[DECK]->discardCardTo(*decks[WASTE]);
}

CardList& Board::getCardSubList(std::string target, int length) {
	assert(isTableauCell(target));
	return *(tableaus[target]->getSubList(length));
}

void Board::pop(std::string target) {
	if (isFoundationCell(target))
		foundations[target]->pop();
	if (isTableauCell(target))
		tableaus[target]->pop();
	decks[target]->pop();
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
	return key.find(key) != string::npos;
}

void Board::setDecks(const std::map<std::string, Deck*>& decks) {
	this->decks = decks;
}

void Board::setFoundations(const std::map<std::string, Foundation*>& foundations) {
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

ostream& operator<<(ostream &ostrm, const Board* board) {
	ostrm << "Decks:" << endl;
	for (auto &v : board->decks) {
		ostrm << v.second << endl;
	}
	ostrm << "Foundations:" << endl;
	for (auto &v : board->foundations) {
		ostrm << v.second << endl;
	}
	ostrm << "Tableaus:" << endl;
	for (auto &v : board->tableaus) {
		ostrm << v.second << endl;
	}
	return ostrm;
}

} /* namespace model */
