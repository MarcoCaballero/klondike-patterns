#include <controller/LogicBuilder.hpp>
#include <controller/NewCardController.hpp>
#include <controller/FlipController.hpp>
#include <controller/MoveCardController.hpp>
#include <controller/MoveListController.hpp>

using namespace model;

namespace controller {

LogicBuilder::LogicBuilder() {
	game = new Game();
	startController = new StartController(game);
	exitController = new ExitController(game);
	winController = new WinController(game);
	ingameControllers["new"] = new NewCardController(game);
	ingameControllers["move"] = new MoveCardController(game);
	ingameControllers["movelist"] = new MoveListController(game);
	ingameControllers["flip"] = new FlipController(game);

}

LogicBuilder::~LogicBuilder() {
}

Logic* LogicBuilder::build() {
	Logic* logic = new Logic();
	logic->setGame(game);
	logic->setStartController(startController);
	logic->setWinController(winController);
	logic->setExitController(exitController);
	logic->setIngameControllers(ingameControllers);
	return logic;
}

} /* namespace view */
