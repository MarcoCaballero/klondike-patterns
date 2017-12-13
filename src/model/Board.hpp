#ifndef MODEL_BOARD_HPP_
#define MODEL_BOARD_HPP_
#include <map>
#include <memory>
#include <model/BoardCell.hpp>

namespace model {

class Board {
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
	void restoreDeckFromWaste();

private:
	std::map<std::string, std::shared_ptr<BoardCell>> cells;

	bool isFoundationCell(std::string target);
	bool isTableauCell(std::string target);
	bool isDeckCell(std::string target);
	bool existsCellKey(std::string target);

	const std::string FOUNDATIONS_REG_EXP = "f";
	const std::string TABLEAUS_REG_EXP = "t";
	const std::string DECKS_REG_EXP = "d";
	const std::string DECK = "deck";
	const std::string WASTE = "waste";
};

} /* namespace model */

#endif /* MODEL_BOARD_HPP_ */
