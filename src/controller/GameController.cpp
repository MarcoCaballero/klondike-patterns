#include <controller/GameController.hpp>

using namespace model;

namespace controller  {

GameController::GameController(Game* game): game(game) {
}

GameController::~GameController() {
}

State GameController::getState() const {
	return game->getState();
}

void GameController::setState(State state) {
	game->setState(state);
}

Board* GameController::getBoard() const {
	return game->getBoard();
}

void GameController::setInGameState(std::string inGameState) {
	game->setInGameState(inGameState);
}

} /* namespace model */
