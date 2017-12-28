#include <controller/MoveListController.hpp>

using namespace std;
using namespace model;

namespace controller {

MoveListController::MoveListController(Game* game) :
		GameController(game) {

}

MoveListController::~MoveListController() {
}

void MoveListController::accept(GameControllerVisitor* visitor) {
	visitor->visit(this);
}

void MoveListController::move(model::Coordinate& coordinate, int length) {
	string origin = coordinate.getOrigin();
	string target = coordinate.getTarget();
	CardList cards = this->game->getBoardCellList(target, length);
	this->game->push(target, cards);
	this->game->pop(origin, length);
}

Status MoveListController::checkMove(model::Coordinate& coordinate) {
	if (!this->game->isTableauBoardCell(coordinate.getOrigin())
			or !this->game->isTableauBoardCell(coordinate.getTarget()))
		return Status::KEY_ERROR;
	if (!this->game->isAllowedPushOnBoardCell(coordinate, coordinate.getLength()))
		return Status::NOT_ALLOWED_MOVE;
	return Status::OK;
}

} /* namespace view */
