#include <controller/Logic.hpp>
#include <model/Game.hpp>
#include <controller/NewCardController.hpp>
#include <controller/FlipController.hpp>
#include <controller/MoveCardController.hpp>
#include <controller/MoveListController.hpp>
#include <iostream>

using namespace model;
using namespace std;

namespace controller {

Logic::Logic() {
}

Logic::~Logic() {

}

GameController* Logic::getController() {
	switch (game->getState()) {
	case State::INITIAL:
		return startController;
	case State::IN_GAME:
		return ingameControllers.find(game->getInGameState())->second;
	case State::WIN:
		return winController;
	case State::EXIT:
		return exitController;
	default:
		return nullptr;
	}
}

void Logic::setExitController(ExitController*& exitController) {
	this->exitController = exitController;
}

void Logic::setGame(model::Game*& game) {
	this->game = game;
}

void Logic::setIngameControllers(
		map<std::string, GameController*>& ingameControllers) {
	this->ingameControllers = ingameControllers;
}

void Logic::setStartController(StartController*& startController) {
	this->startController = startController;
}

void Logic::setWinController(WinController*& winController) {
	this->winController = winController;
}

} /* namespace model */
