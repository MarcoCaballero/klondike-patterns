#include <controller/ExitController.hpp>

namespace controller {

ExitController::ExitController(model::Game* game) :
		GameController(game) {
}

ExitController::~ExitController() {
}

void ExitController::accept(GameControllerVisitor* visitor) {
	visitor->visit(this);
}

void ExitController::exitGame() {
	exit(0);
}

} /* namespace view */
