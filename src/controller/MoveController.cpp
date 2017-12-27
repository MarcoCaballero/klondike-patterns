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
	Card card = this->game->getBoardCellCard(origin);

	this->game->push(target, card);
	this->game->pop(origin);

	if (this->game->isDeckBoardCell(origin)) {
		this->game->flipBoardCell(origin);
		if (this->game->getBoardCellSize(origin)==1) {
			this->game->restoreDeckFromWaste();
		}
	}

	if (this->game->hasWin()) {
		game->setState(State::FINAL);
	}
}

Status MoveController::checkMove(model::Coordinate& coordinate) {
	if (!this->game->isAllowedPushOnBoardCell(coordinate))
		return Status::NOT_ALLOWED_MOVE;
	return Status::OK;
}

} /* namespace view */
