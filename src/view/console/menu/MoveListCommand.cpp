#include <view/console/menu/MoveListCommand.hpp>
#include <view/console/utils/IOUtils.hpp>
#include <view/console/utils/CoordinateView.hpp>

using namespace controller;
using namespace model;
using namespace std;

namespace view {

MoveListCommand::MoveListCommand(MoveListController* moveController) :
		Command("Move card: ", moveController), moveController(moveController) {

}

MoveListCommand::~MoveListCommand() {
}

void MoveListCommand::executeChild() {
	IOUtils* ioutils = IOUtils::instance();
	Coordinate coordinate =
			CoordinateView(moveController).readCoordinateLength();
	switch (moveController->checkMove(coordinate)) {
	case Status::NOT_ALLOWED_MOVE:
		ioutils->writeln("Error: not allowed move");
		break;
	case Status::KEY_ERROR:
		ioutils->writeln("Error: not allowed key is not a tableau");
		break;
	case Status::OK:
		moveController->move(coordinate, coordinate.getLength());
		break;
	default:
		ioutils->writeln("Error: undefined error");
		break;
	}
}

} /* namespace view */
