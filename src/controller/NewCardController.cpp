#include <controller/NewCardController.hpp>
#include <iostream>

using namespace model;
using namespace std;

namespace controller {

NewCardController::NewCardController(model::Game* game) :
		GameController(game) {
}

NewCardController::~NewCardController() {
}

void NewCardController::accept(GameControllerVisitor* visitor) {
	visitor->visit(this);
}

} /* namespace model */
