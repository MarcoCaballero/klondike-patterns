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

void NewCardController::control() {
	this->game->disCardDeckCard();
	if (this->game->getBoardCellSize("dd") == 1) {
		this->game->restoreDeckFromWaste();
	}
}

} /* namespace model */
