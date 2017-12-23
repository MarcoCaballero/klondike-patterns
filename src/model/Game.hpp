#ifndef MODEL_GAME_HPP_
#define MODEL_GAME_HPP_

#include <model/State.h>
#include <model/Board.hpp>

namespace model {

class Game {
public:
	Game();
	virtual ~Game();
	State getState() const;
	void setState(State state);
	Board* getBoard() const;

private:
	State state;
	Board* board;
	CardList* generateCards();
};

} /* namespace model */

#endif /* MODEL_GAME_HPP_ */
