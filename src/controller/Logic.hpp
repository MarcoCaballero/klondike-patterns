#ifndef CONTROLLER_LOGIC_HPP_
#define CONTROLLER_LOGIC_HPP_

#include <map>
#include <model/Game.hpp>
#include <controller/StartController.hpp>
#include <controller/WinController.hpp>
#include <controller/ExitController.hpp>

namespace controller {

class Logic {
public:
	Logic();
	virtual ~Logic();
	GameController* getController();
	void setExitController(ExitController*& exitController);
	void setGame(model::Game*& game);
	void setIngameControllers(std::map<std::string, GameController*>& ingameControllers);
	void setStartController(StartController*& startController);
	void setWinController(WinController*& winController);

private:
	model::Game* game;
	StartController* startController;
	ExitController* exitController;
	WinController* winController;
	std::map<std::string, GameController*> ingameControllers;

};

} /* namespace model */

#endif /* CONTROLLER_LOGIC_HPP_ */
