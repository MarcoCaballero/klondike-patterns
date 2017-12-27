#include <view/console/CoordinateView.hpp>
#include <view/console/utils/IOUtils.hpp>

using namespace controller;
using namespace model;
using namespace std;

namespace view {

CoordinateView::CoordinateView(GameController* gameController) :
		gameController(gameController), checker(gameController->getBoard()) {
}

CoordinateView::~CoordinateView() {
}

Coordinate CoordinateView::readCoordinate() {
	IOUtils* ioutils = IOUtils::instance();
	string origin = readOrigin();
	string target;
	do {
		target = readKey("Select target: ");
	} while (target == origin);
	ioutils->writeln("Moving from: " + origin + "to -> " + target);
	Coordinate coordinate(origin, target);
	return coordinate;
}

std::string CoordinateView::readKey(string title = "Select key: ") {
	IOUtils* ioutils = IOUtils::instance();
	string origin;
	do {
		origin = ioutils->readString(title);
		if (!checker.isValid(origin))
			ioutils->writeln("Bad key, please try other...");
	} while (!checker.isValid(origin));
	return origin;
}

std::string CoordinateView::readKeyFlipSurvey() {
	IOUtils* ioutils = IOUtils::instance();
	string origin;
	origin = readKey("Select key to flip: ");
	if (!checker.isValidToFlip(origin))
		ioutils->writeln("Bad key, please try other...");
	return origin;
}

std::string CoordinateView::readOrigin() {
	return readKey("Select Origin: ");
}

} /* namespace view */
