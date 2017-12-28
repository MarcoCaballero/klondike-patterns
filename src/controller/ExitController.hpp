#ifndef CONTROLLER_EXITCONTROLLER_HPP_
#define CONTROLLER_EXITCONTROLLER_HPP_

#include <controller/GameController.hpp>

namespace controller {

class ExitController: public GameController {
public:
	ExitController(model::Game* game);
	virtual ~ExitController();
	void accept (GameControllerVisitor* visitor);
	void exitGame();
};

} /* namespace view */

#endif /* CONTROLLER_EXITCONTROLLER_HPP_ */
