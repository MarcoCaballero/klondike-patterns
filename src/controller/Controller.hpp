#ifndef CONTROLLER_CONTROLLER_HPP_
#define CONTROLLER_CONTROLLER_HPP_

#include <model/Game.hpp>

namespace controller {

class Controller {
public:
	Controller(model::Game* game);
	Controller(void) = delete;

	Controller(Controller const&);
	Controller& operator=(Controller const& rhs) = delete;

	Controller(Controller && rhs) noexcept =delete;
	Controller& operator=(Controller&& rhs) noexcept =delete;

	virtual ~Controller();

	model::State getState() const;
	void setState(model::State state);
	model::Board* getBoard() const;
	void setInGameState(std::string inGameState);

protected:
	model::Game* game;
};

} /* namespace model */

#endif /* CONTROLLER_CONTROLLER_HPP_ */
