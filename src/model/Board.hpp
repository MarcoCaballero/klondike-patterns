#ifndef MODEL_BOARD_HPP_
#define MODEL_BOARD_HPP_
#include <map>
#include <memory>
#include <model/BoardCellVisitor.hpp>
#include <model/BoardCell.hpp>
#include <model/Tableau.hpp>

namespace model {

class Board: BoardCellVisitor {
public:
	Board();
	virtual ~Board();
	void push(std::string target, const Card& card);
	void push(std::string target, const CardList& cards);
	void pop(std::string target);
	void pop(std::string target, int length);
	void turnCard(std::string target);
	bool isEmpty(std::string target);
	const CardList getSubList(std::string target, int length);
	int getCountOfCompleteFoundations();
	bool isCompleteBoard();
	void clearAll();
	void visitPushList(Tableau& tableau, const CardList& cards);
	const CardList visitSublist(Deck& deck, int length);
	const CardList visitSublist(Tableau& tableau, int length);

private:
	std::map<std::string, std::shared_ptr<BoardCell>> cells;
	void restoreDeckFromWaste();
	bool isFoundationCell(std::string target);
	const std::string FOUNDATIONS_REG_EXP = "f";
	const std::string DECK = "deck";
	const std::string WASTE = "waste";
};

} /* namespace model */

#endif /* MODEL_BOARD_HPP_ */
