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
	Logic* logic;
	model::Game* game;
	void buildInGameControllers();
	void buildOutStateControllers();
	void buildGame();
};

} /* namespace view */

#endif /* CONTROLLER_LOGICBUILDER_HPP_ */
