#ifndef CONTROLLER_MOVECARDCONTROLLER_HPP_
#define CONTROLLER_MOVECARDCONTROLLER_HPP_

#include <controller/GameController.hpp>
#include <model/Coordinate.hpp>
#include <controller/Status.hpp>

namespace controller {

class MoveCardController: public GameController {
public:
	MoveCardController(model::Game* game);
	virtual ~MoveCardController();
	void accept (GameControllerVisitor* visitor);
	void move (model::Coordinate& coordinate);
	Status checkMove(model::Coordinate& coordinate);
private:
	void checkDeck(std::string origin);
	void checkWin();
};

} /* namespace view */

#endif /* CONTROLLER_MOVECARDCONTROLLER_HPP_ */
