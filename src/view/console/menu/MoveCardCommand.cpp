#include <view/console/menu/MoveCardCommand.hpp>
#include <view/console/utils/IOUtils.hpp>
#include <view/console/CoordinateView.hpp>

using namespace controller;
using namespace model;
using namespace std;

namespace view {

MoveCardCommand::MoveCardCommand(MoveCardController* moveController) :
		Command("Move card: ", moveController), moveController(moveController) {
}

MoveCardCommand::~MoveCardCommand() {
}

void MoveCardCommand::executeChild() {
	IOUtils* ioutils = IOUtils::instance();
	Coordinate coordinate = CoordinateView(moveController).readCoordinate();
	switch (moveController->checkMove(coordinate)) {
	case Status::NOT_ALLOWED_MOVE:
		ioutils->writeln("Error: not allowed move");
		break;
	case Status::OK:
		moveController->move(coordinate);
		break;
	default:
		ioutils->writeln("Error: undefined error");
	}
}

} /* namespace view */
