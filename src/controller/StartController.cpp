#include <controller/StartController.hpp>

using namespace model;
using namespace std;

namespace controller {

StartController::StartController(model::Game* game) :
		GameController(game) {
}

StartController::~StartController() {
}

void StartController::accept(GameControllerVisitor* visitor) {
	visitor->visit(this);
}

void StartController::start(){
	this->setState(State::IN_GAME);
}

} /* namespace model */
