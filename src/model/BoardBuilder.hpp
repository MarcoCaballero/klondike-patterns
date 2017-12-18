#ifndef MODEL_BOARDBUILDER_HPP_
#define MODEL_BOARDBUILDER_HPP_

#include <memory>
#include <model/Board.hpp>
#include <model/CardList.hpp>

namespace model {

class BoardBuilder {
public:
	BoardBuilder();
	virtual ~BoardBuilder();
	Board* getBoard();
	void buildCells();
	void buildDecks(const CardList& cards);
	void buildTableaus();
	void buildFoundations();

private:
	std::unique_ptr<Board> board;
};

} /* namespace model */

#endif /* MODEL_BOARDBUILDER_HPP_ */
