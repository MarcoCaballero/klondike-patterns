#include <controller/MoveController.hpp>

using namespace std;
using namespace model;

namespace controller {

MoveController::MoveController(Game* game) :
		GameController(game) {
}

MoveController::~MoveController() {
}

void MoveController::accept(GameControllerVisitor* visitor) {
	visitor->visit(this);
}

void MoveController::move(Coordinate& coordinate) {
	string origin = coordinate.getOrigin();
	string target = coordinate.getTarget();
	Card card = this->game->getBoard()->getCard(origin);

	this->game->getBoard()->push(target, card);
	this->game->getBoard()->pop(origin);

	if (this->game->getBoard()->isDeckCell(origin)) {
		this->game->getBoard()->flip(origin);
		if (this->game->getBoard()->size(origin)==1) {
			this->game->getBoard()->restoreDeckFromWaste();
		}
	}


	if (this->game->getBoard()->isCompleteBoard()) {
		game->setState(State::FINAL);
	}
}

Status MoveController::checkMove(Coordinate& coordinate) {
	string origin = coordinate.getOrigin();
	string target = coordinate.getTarget();
	if (!this->game->getBoard()->isAllowedPush(origin, target))
		return Status::NOT_ALLOWED_MOVE;
	return Status::OK;
}

} /* namespace view */
