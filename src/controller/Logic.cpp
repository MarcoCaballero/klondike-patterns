#include <controller/Logic.hpp>
#include <model/Game.hpp>
#include <controller/NewCardController.hpp>
#include <controller/MoveController.hpp>

using namespace model;

namespace controller {

Logic::Logic() {
	game = new Game();
	startController = new StartController(game);
	ingameControllers["new"] = new NewCardController(game);
	ingameControllers["move"] = new MoveController(game);
//	ingameControllers['flip'] = new NewCardController(game);
}

Logic::~Logic() {

}

GameController* Logic::getController() {
	switch (game->getState()) {
	case State::INITIAL:
		return startController;
	case State::IN_GAME:
		return ingameControllers.find(game->getInGameState())->second;
	default:
		return nullptr;
	}
}

} /* namespace model */
