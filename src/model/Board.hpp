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
	const CardList getSubList(std::string target, int length);
	void turnCard(std::string target);
	bool isEmpty(std::string target);
	bool isCompleteBoard();
	int getCountOfCompleteFoundations();
	void clearAll();
	void restoreDeckFromWaste();
	void setCells(
			const std::map<std::string, std::shared_ptr<BoardCell> >& cells);
	const std::string& getDeck() const;
	const std::string& getWaste() const;
	const char getDecksRegExp() const;
	const char getFoundationsRegExp() const;
	const char getTableausRegExp() const;
	
	

private:
	std::map<std::string, std::shared_ptr<BoardCell>> cells;

	bool isFoundationCell(std::string key);
	bool isTableauCell(std::string key);
	bool isDeckCell(std::string key);
	bool existsCellKey(std::string key, const char regexp);

	const char FOUNDATIONS_REG_EXP = 'f';
	const char TABLEAUS_REG_EXP = 't';
	const char DECKS_REG_EXP = 'd';
	const std::string DECK = "d";
	const std::string WASTE = "w";
};

} /* namespace model */

#endif /* MODEL_BOARD_HPP_ */
