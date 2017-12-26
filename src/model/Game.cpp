#include <model/Game.hpp>
#include <model/BoardBuilder.hpp>

namespace model {

Game::Game(): state(State::INITIAL) {
	auto& cardlist = *(generateCards());
	board = BoardBuilder(cardlist).build();
}

Game::~Game() {
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

} /* namespace model */
