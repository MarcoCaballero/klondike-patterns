#ifndef CONTROLLER_LOGIC_HPP_
#define CONTROLLER_LOGIC_HPP_

#include <map>
#include <model/Game.hpp>
#include <controller/StartController.hpp>

namespace controller {

class Logic {
public:
	Logic();
	virtual ~Logic();
	GameController* getController();
private:
	model::Game* game;
	StartController* startController;
	std::map<std::string, GameController*> ingameControllers;

};

} /* namespace model */

#endif /* CONTROLLER_LOGIC_HPP_ */
