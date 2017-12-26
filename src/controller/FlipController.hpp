#ifndef CONTROLLER_FLIPCONTROLLER_HPP_
#define CONTROLLER_FLIPCONTROLLER_HPP_

#include <controller/GameController.hpp>

namespace controller {

class FlipController: public GameController {
public:
	FlipController(model::Game* game);
	virtual ~FlipController();
	void accept(GameControllerVisitor* visitor);
	void flip(std::string origin);
};

} /* namespace view */

#endif /* CONTROLLER_FLIPCONTROLLER_HPP_ */
