#ifndef CONTROLLER_NEWCARDCONTROLLER_HPP_
#define CONTROLLER_NEWCARDCONTROLLER_HPP_

#include <controller/GameController.hpp>

namespace controller {

class NewCardController: public GameController {
public:
	NewCardController(model::Game* game);
	virtual ~NewCardController();
	void accept (GameControllerVisitor* visitor);
	void control();
};

} /* namespace model */

#endif /* CONTROLLER_NEWCARDCONTROLLER_HPP_ */
