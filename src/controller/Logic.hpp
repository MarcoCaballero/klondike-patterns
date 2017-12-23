#ifndef CONTROLLER_LOGIC_HPP_
#define CONTROLLER_LOGIC_HPP_

#include <model/Game.hpp>
#include <controller/StartController.hpp>
#include <controller/NewCardController.hpp>

namespace controller {

class Logic {
public:
	Logic();
	virtual ~Logic();
	GameController* getController();

private:
	model::Game* game;
	StartController* startController;
	NewCardController* newCardController;

};

} /* namespace model */

#endif /* CONTROLLER_LOGIC_HPP_ */
