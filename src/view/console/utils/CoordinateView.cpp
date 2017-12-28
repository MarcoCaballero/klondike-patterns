#include <view/console/utils/CoordinateView.hpp>
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
		if(target==origin)
			ioutils->writeln("Please origin and target could not be the same key");
	} while (target == origin);
	Coordinate coordinate(origin, target);
	return coordinate;
}

Coordinate CoordinateView::readCoordinateLength() {
	IOUtils* ioutils = IOUtils::instance();
	string origin;
	string target;
	do {
		origin = readTableauKey("Select origin: ");
		target = readTableauKey("Select target: ");
	} while (target == origin);
	int length = ioutils->readInt("Select the length to move: ");

	Coordinate coordinate(origin, target);
	coordinate.setLength(length);
	return coordinate;
}

std::string CoordinateView::readOrigin() {
	return readKey("Select Origin: ");
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

std::string CoordinateView::readTableauKey(std::string title) {
	IOUtils* ioutils = IOUtils::instance();
	string origin;
	do {
		origin = ioutils->readString(title);
		if (!checker.isTableau(origin) or !checker.isValid(origin))
			ioutils->writeln("Bad key, please try other...");
	} while (!checker.isTableau(origin) or !checker.isValid(origin));
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

} /* namespace view */
