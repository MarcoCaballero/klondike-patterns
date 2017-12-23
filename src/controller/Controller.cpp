#include <controller/Controller.hpp>

using namespace model;

namespace controller {

Controller::Controller(Game* game) :
		game(game) {
}

Controller::~Controller() {
}

State Controller::getState() const {
	return game->getState();
}

void Controller::setState(State state) {
	game->setState(state);
}

Board* Controller::getBoard() const{
	return game->getBoard();
}

}
/* namespace model */
