#include <view/console/utils/CoordinateChecker.hpp>

using namespace std;
using namespace model;

namespace view {

CoordinateChecker::CoordinateChecker(Board* board) :
		board(board) {
}

CoordinateChecker::~CoordinateChecker() {
}

bool CoordinateChecker::check(Coordinate& coordinate) {
	return (isValid(coordinate.getOrigin()) && isValid(coordinate.getTarget()));
}

bool CoordinateChecker::isValid(string key) {
	return board->existsCellKey(key);
}

bool CoordinateChecker::isValidToFlip(string key) {
	return isTableau(key) ? board->isFullOfInvisible(key) : false;
}

bool CoordinateChecker::isTableau(string key){
	return board->isTableauCell(key);
}


bool CoordinateChecker::isValidLength(string key, int length) {
	return (length > 2 && board->size(key) >= length);
}

} /* namespace view */
