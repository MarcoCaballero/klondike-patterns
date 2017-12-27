#ifndef CONTROLLER_GAMECONTROLLER_HPP_
#define CONTROLLER_GAMECONTROLLER_HPP_

#include <controller/Controller.hpp>
#include <controller/GameControllerVisitor.hpp>

namespace controller {

class GameController: public Controller {
public:
	GameController(model::Game* game);
	virtual ~GameController();
	virtual void accept (GameControllerVisitor* visitor) = 0;
};

} /* namespace model */

#endif /* CONTROLLER_GAMECONTROLLER_HPP_ */
