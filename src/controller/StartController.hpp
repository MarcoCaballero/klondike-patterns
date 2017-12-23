#ifndef CONTROLLER_STARTCONTROLLER_HPP_
#define CONTROLLER_STARTCONTROLLER_HPP_

#include <controller/GameController.hpp>

namespace controller {

class StartController: public GameController {
public:
	StartController(model::Game* game);
	virtual ~StartController();
	void accept (GameControllerVisitor* visitor);

};

} /* namespace model */

#endif /* CONTROLLER_STARTCONTROLLER_HPP_ */
