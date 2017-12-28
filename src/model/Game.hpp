#ifndef MODEL_GAME_HPP_
#define MODEL_GAME_HPP_

#include <model/State.h>
#include <model/Board.hpp>
#include <model/Coordinate.hpp>

namespace model {

class Game {
public:
	Game();
	virtual ~Game();
	State getState() const;
	void setState(State state);
	void setInGameState(std::string inGameState);
	const std::string& getInGameState() const;
	Board* getBoard() const;
	void disCardDeckCard();
	bool isDeckBoardCell(std::string key);
	bool isTableauBoardCell(std::string key) const;
	bool isAllowedPushOnBoardCell(Coordinate coordinate);
	bool isAllowedPushOnBoardCell(Coordinate coordinate, int length);
	bool hasWin();
	void flipBoardCell(std::string key);
	void restoreDeckFromWaste();
	int getBoardCellSize(std::string key);
	Card& getBoardCellCard(std::string key);
	CardList& getBoardCellList(std::string key, int length);
	void push(std::string key, const Card& card);
	void push(std::string target, CardList& cards);
	void pop(std::string key);
	void pop(std::string target, int length);
	void restartGame();

private:
	State state;
	std::string inGameState;
	Board* board;
	CardList* generateCards();
	void createBoard();
};

} /* namespace model */

#endif /* MODEL_GAME_HPP_ */
