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
	Board& board = *(this->game->getBoard());
	string origin = coordinate.getOrigin();
	string target = coordinate.getTarget();
	auto& card = board.getCard(origin);
	board.push(target, card);
	board.pop(origin);
	if (board.isCompleteBoard()) {
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
