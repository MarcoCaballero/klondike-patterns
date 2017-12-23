#include <controller/StartController.hpp>
#include <iostream>

using namespace model;
using namespace std;

namespace controller {

StartController::StartController(model::Game* game) :
		GameController(game) {
}

StartController::~StartController() {
}

//void StartController::control() {
//	assert(GameController::Controller::getState() == State::INITIAL);
//	cout << this->getBoard() << endl;
//	this->setState(State::IN_GAME);
//}

void StartController::accept(GameControllerVisitor* visitor) {
	visitor->visit(this);
}

} /* namespace model */
