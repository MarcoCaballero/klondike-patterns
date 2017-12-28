#ifndef CONTROLLER_GAMECONTROLLER_HPP_
#define CONTROLLER_GAMECONTROLLER_HPP_

#include <controller/GameControllerVisitor.hpp>
#include <model/Game.hpp>

namespace controller {

class GameController{
public:
	GameController(model::Game* game);
	virtual ~GameController();
	virtual void accept(GameControllerVisitor* visitor) = 0;
	model::State getState() const;
	void setState(model::State state);
	model::Board* getBoard() const;
	void setInGameState(std::string inGameState);

protected:
	model::Game* game;
};

} /* namespace model */

#endif /* CONTROLLER_GAMECONTROLLER_HPP_ */
