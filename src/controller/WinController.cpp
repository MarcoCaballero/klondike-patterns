#include <controller/WinController.hpp>

using namespace model;
using namespace std;

namespace controller {

WinController::WinController(model::Game* game) :
		GameController(game) {
}


WinController::~WinController(){
}

void WinController::accept(GameControllerVisitor* visitor) {
	visitor->visit(this);
}

void WinController::control() {
	this->game->restartGame();
	this->setState(State::INITIAL);
}

} /* namespace view */
