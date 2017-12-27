#ifndef CONTROLLER_COORDINATECHECKER_HPP_
#define CONTROLLER_COORDINATECHECKER_HPP_

#include <model/Coordinate.hpp>
#include <model/Board.hpp>

namespace view {

class CoordinateChecker {
public:
	CoordinateChecker(model::Board*);
	virtual ~CoordinateChecker();
	bool check(model::Coordinate& coordinate);
	void setCoordinate(const model::Coordinate& coordinate);
	bool isValid(std::string key);
	bool isValidToFlip(std::string key);
private:
	model::Board* board;
};

} /* namespace view */

#endif /* CONTROLLER_COORDINATECHECKER_HPP_ */
