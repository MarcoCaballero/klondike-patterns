#include <controller/FlipController.hpp>

namespace controller {

FlipController::FlipController(model::Game* game) :
		GameController(game) {
}

FlipController::~FlipController() {
}

void FlipController::accept(GameControllerVisitor* visitor) {
	visitor->visit(this);
}

void FlipController::flip(std::string key) {
	this->game->getBoard()->flip(key);
}

} /* namespace view */
