#ifndef MODEL_BOARDCELL_HPP_
#define MODEL_BOARDCELL_HPP_
#include <model/CardList.hpp>
#include <string>

namespace model {

class BoardCell {
public:
	virtual ~BoardCell();
	Card& getCard();
	std::vector<Card>& getCards();
	void pop();
	void popList(int length);
	bool isEmpty();
	int size();
	void turnCard();
	virtual void push(const Card& card) = 0;
	virtual bool isAllowedPush(const Card& card) = 0;
	virtual bool isFull() = 0;
	friend std::ostream& operator<<(std::ostream &strm, const BoardCell &boardCell);

protected:
	BoardCell(std::string name);
	BoardCell(std::string name, const CardList& cardlist);
	BoardCell(BoardCell& boardCell);
	std::string name;
	CardList cards;
};

} /* namespace model */

#endif /* MODEL_BOARDCELL_HPP_ */
