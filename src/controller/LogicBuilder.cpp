#include <controller/LogicBuilder.hpp>
#include <controller/NewCardController.hpp>
#include <controller/FlipController.hpp>
#include <controller/MoveCardController.hpp>
#include <controller/MoveListController.hpp>

using namespace model;

namespace controller {

LogicBuilder::LogicBuilder() :
		logic(new Logic()), game(new Game()) {

}

LogicBuilder::~LogicBuilder() {
}

Logic* LogicBuilder::build() {
	buildGame();
	buildOutStateControllers();
	buildInGameControllers();
	return logic;
}
void LogicBuilder::buildGame() {
	game = new Game();
	logic->setGame(game);
}

void LogicBuilder::buildInGameControllers() {
	std::map<std::string, GameController*> ingameControllers;
	ingameControllers["new"] = new NewCardController(game);
	ingameControllers["move"] = new MoveCardController(game);
	ingameControllers["movelist"] = new MoveListController(game);
	ingameControllers["flip"] = new FlipController(game);
	logic->setIngameControllers(ingameControllers);
}
void LogicBuilder::buildOutStateControllers() {
	StartController* startController = new StartController(game);
	logic->setStartController(startController);
	ExitController* exitController = new ExitController(game);
	logic->setExitController(exitController);
	WinController* winController = new WinController(game);
	logic->setWinController(winController);
}

} /* namespace view */
