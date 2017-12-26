#ifndef CONTROLLER_MOVECONTROLLER_HPP_
#define CONTROLLER_MOVECONTROLLER_HPP_

#include <controller/GameController.hpp>
#include <controller/Coordinate.hpp>
#include <controller/CoordinateChecker.hpp>
#include <controller/Status.hpp>

namespace controller {

class MoveController: public GameController {
public:
	MoveController(model::Game* game);
	virtual ~MoveController();
	void accept (GameControllerVisitor* visitor);
	void move (Coordinate& coordinate);
	Status checkMove(Coordinate& coordinate);
};

} /* namespace view */

#endif /* CONTROLLER_MOVECONTROLLER_HPP_ */
