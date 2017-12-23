#include <controller/Logic.hpp>
#include <model/Game.hpp>

using namespace model;

namespace controller {

Logic::Logic() {
	game = new Game();
	startController = new StartController(game);
	newCardController = new NewCardController(game);
}

Logic::~Logic() {

}

GameController* Logic::getController() {
	switch (game->getState()) {
	case State::INITIAL:
		return startController;
	case State::IN_GAME:
		return newCardController;
	default:
		return nullptr;
	}
}

} /* namespace model */
