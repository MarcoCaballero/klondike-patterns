#include <view/console/utils/CoordinateChecker.hpp>

using namespace std;
using namespace model;
using namespace controller;

namespace view {

CoordinateChecker::CoordinateChecker(Board* board) : board(board) {
}

CoordinateChecker::~CoordinateChecker() {
}

bool CoordinateChecker::check(Coordinate& coordinate) {
	return (isValid(coordinate.getOrigin()) && isValid(coordinate.getTarget()));
}

bool CoordinateChecker::isValid(string key) {
	return board->existsCellKey(key);
}

} /* namespace view */
