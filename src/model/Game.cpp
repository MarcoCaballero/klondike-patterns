#include <model/Game.hpp>
#include <model/BoardBuilder.hpp>

namespace model {

Game::Game():state(State::INITIAL) {
	createBoard();
}

Game::~Game() {
}

void Game::createBoard() {
	auto& cardlist = *(generateCards());
	board = BoardBuilder(cardlist).build();
}

State Game::getState() const {
	return state;
}

void Game::setState(State state) {
	this->state = state;
}

Board* Game::getBoard() const {
	return board;
}

CardList* Game::generateCards() {
	CardList* cardlist = new CardList();
	for (int i = 1; i <= 13; ++i) {
		for (int j = 1; j <= 4; ++j) {
			Card card = Card(i, j, j % 2);
			cardlist->pushBack(card);
		}
	}
	return cardlist;
}

void Game::setInGameState(std::string inGameState) {
	this->inGameState = inGameState;
}

const std::string& Game::getInGameState() const {
	return inGameState;
}

void Game::disCardDeckCard() {
	board->discardDeckCard();
}

void Game::restoreDeckFromWaste() {
	board->restoreDeckFromWaste();
}

int Game::getBoardCellSize(std::string key) {
	return board->size(key);
}

bool Game::isDeckBoardCell(std::string key) {
	return board->isDeckCell(key);
}

bool Game::isAllowedPushOnBoardCell(Coordinate coordinate) {
	std::string origin = coordinate.getOrigin();
	std::string target = coordinate.getTarget();
	return board->isAllowedPush(origin, target);
}

bool Game::isAllowedPushOnBoardCell(Coordinate coordinate, int length) {
	std::string origin = coordinate.getOrigin();
	std::string target = coordinate.getTarget();
	return board->isAllowedPush(origin, target, length);
}

bool Game::isTableauBoardCell(std::string key) const {
	return board->isTableauCell(key);
}

bool Game::hasWin() {
	return board->isCompleteBoard();
}

void Game::flipBoardCell(std::string key) {
	board->flip(key);
}

Card& Game::getBoardCellCard(std::string key) {
	return board->getCard(key);
}

CardList& Game::getBoardCellList(std::string key, int length) {
	return board->getCardSubList(key, length);
}

void Game::push(std::string key, const Card& card) {
	board->push(key, card);
}

void Game::push(std::string target, CardList& cards) {
	board->push(target, cards);
}

void Game::pop(std::string key) {
	board->pop(key);
}

void Game::pop(std::string target, int length) {
	board->pop(target, length);
}

void Game::restartGame() {
	board->restoreBoard();
	createBoard();
}
} /* namespace model */
