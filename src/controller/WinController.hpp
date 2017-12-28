#ifndef CONTROLLER_WINCONTROLLER_HPP_
#define CONTROLLER_WINCONTROLLER_HPP_

#include <controller/GameController.hpp>

namespace controller {

class WinController: public GameController {
public:
	WinController(model::Game* game);
	virtual ~WinController();
	void accept (GameControllerVisitor* visitor);
	void control();
};

} /* namespace view */

#endif /* CONTROLLER_WINCONTROLLER_HPP_ */
