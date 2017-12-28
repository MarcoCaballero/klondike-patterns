#include <controller/MoveCardController.hpp>

using namespace std;
using namespace model;

namespace controller {

MoveCardController::MoveCardController(Game* game) :
		GameController(game) {
}

MoveCardController::~MoveCardController() {
}

void MoveCardController::accept(GameControllerVisitor* visitor) {
	visitor->visit(this);
}

void MoveCardController::move(Coordinate& coordinate) {
	string origin = coordinate.getOrigin();
	string target = coordinate.getTarget();
	Card card = this->game->getBoardCellCard(origin);

	this->game->push(target, card);
	this->game->pop(origin);

	checkDeck(origin);
	checkWin();
}

Status MoveCardController::checkMove(model::Coordinate& coordinate) {
	if (!this->game->isAllowedPushOnBoardCell(coordinate))
		return Status::NOT_ALLOWED_MOVE;
	return Status::OK;
}

void MoveCardController::checkDeck(string origin) {
	if (this->game->isDeckBoardCell(origin)) {
		this->game->flipBoardCell(origin);
		if (this->game->getBoardCellSize(origin) == 1) {
			this->game->restoreDeckFromWaste();
		}
	}
}

void MoveCardController::checkWin() {
	if (this->game->hasWin()) {
		game->setState(State::WIN);
	}
}

} /* namespace view */
