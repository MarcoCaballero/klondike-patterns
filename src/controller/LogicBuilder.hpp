#ifndef CONTROLLER_LOGICBUILDER_HPP_
#define CONTROLLER_LOGICBUILDER_HPP_

#include <controller/Logic.hpp>

namespace controller {

class LogicBuilder {
public:
	LogicBuilder();
	virtual ~LogicBuilder();
	Logic* build();
private:
	model::Game* game;
	StartController* startController;
	ExitController* exitController;
	WinController* winController;
	std::map<std::string, GameController*> ingameControllers;
};

} /* namespace view */

#endif /* CONTROLLER_LOGICBUILDER_HPP_ */
