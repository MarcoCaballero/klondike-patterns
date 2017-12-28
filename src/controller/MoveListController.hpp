#ifndef CONTROLLER_MOVELISTCONTROLLER_HPP_
#define CONTROLLER_MOVELISTCONTROLLER_HPP_
#include <controller/GameController.hpp>
#include <model/Coordinate.hpp>
#include <controller/Status.hpp>

namespace controller {

class MoveListController: public GameController {
public:
	MoveListController(model::Game* game);
	virtual ~MoveListController();
	void accept (GameControllerVisitor* visitor);
	void move (model::Coordinate& coordinate, int length);
	Status checkMove(model::Coordinate& coordinate);
};

} /* namespace view */

#endif /* CONTROLLER_MOVELISTCONTROLLER_HPP_ */
