#include <view/console/CoordinateView.hpp>
#include <view/console/utils/IOUtils.hpp>

using namespace controller;
using namespace std;

namespace view {

CoordinateView::CoordinateView() {
}

CoordinateView::~CoordinateView() {
}

Coordinate CoordinateView::readCoordinate(GameController* gameController) {
	IOUtils* ioutils = IOUtils::instance();
	CoordinateChecker checker(gameController->getBoard());

	string origin;
	do {
		origin = ioutils->readString("Select Origin: ");
		if (!checker.isValid(origin))
			ioutils->writeln("Bad origin key, please try again...");
	} while (!checker.isValid(origin));

	string target;
	do {
		target = ioutils->readString("Select Target: ");
		if (!checker.isValid(target) || target == origin)
			ioutils->writeln("Bad target key, please try again...");
	} while (!checker.isValid(target) || target == origin);

	ioutils->writeln("Moving from: " + origin + "to -> " + target);

	Coordinate coordinate(origin, target);
	return coordinate;
}

} /* namespace view */
