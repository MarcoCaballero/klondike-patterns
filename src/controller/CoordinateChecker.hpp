#ifndef CONTROLLER_COORDINATECHECKER_HPP_
#define CONTROLLER_COORDINATECHECKER_HPP_

#include <controller/Coordinate.hpp>
#include <model/Board.hpp>

namespace controller {

class CoordinateChecker {
public:
	CoordinateChecker(model::Board*);
	virtual ~CoordinateChecker();
	bool check(Coordinate& coordinate);
	void setCoordinate(const Coordinate& coordinate);
	bool isValid(std::string key);
private:
	model::Board* board;
};

} /* namespace view */

#endif /* CONTROLLER_COORDINATECHECKER_HPP_ */
