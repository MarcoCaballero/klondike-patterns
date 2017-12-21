#ifndef MODEL_BOARD_HPP_
#define MODEL_BOARD_HPP_
#include <map>
#include <model/Deck.hpp>
#include <model/Foundation.hpp>
#include <model/Tableau.hpp>

namespace model {

class Board {
public:
	Board(void);
	Board(const Board& board);
	virtual ~Board();
	void push(std::string target, const Card& card);
	void push(std::string target, CardList& cards);

	void discardDeckCard();
	void showNewDeckCard();
	void showCard(std::string target);

	Card& getDeckCard();
	Card& getCard(std::string target);
	CardList& getCardSubList(std::string target, int length);

	void pop(std::string target);
	void pop(std::string target, int length);

	bool isAllowedPush(std::string origin, std::string target);

	void restoreDeckFromWaste();


	const std::string& getDeckName() const;
	const std::string& getWasteName() const;
	const char getDecksRegExp() const;
	const char getFoundationsRegExp() const;
	const char getTableausRegExp() const;
	void setDecks(const std::map<std::string, Deck*>& decks);
	void setFoundations(const std::map<std::string, Foundation*>& foundations);
	void setTableaus(const std::map<std::string, Tableau*>& tableaus);
	friend std::ostream& operator<<(std::ostream &ostrm, const Board* board);

private:
	std::map<std::string, Deck*> decks;
	std::map<std::string, Foundation*> foundations;
	std::map<std::string, Tableau*> tableaus;


	bool isFoundationCell(std::string key) const;
	bool isTableauCell(std::string key) const;
	bool isDeckCell(std::string key) const;
	bool existsCellKey(std::string key, const char regexp) const;
	bool existsCellKey(std::string key) const;

	const char FOUNDATIONS_REG_EXP = 'f';
	const char TABLEAUS_REG_EXP = 't';
	const char DECKS_REG_EXP = 'd';
	const std::string DECK = "dd";
	const std::string WASTE = "dw";
	const int FOUNDATIONS_SIZE = 4;
	const int TABLEAUS_SIZE = 7;
};

} /* namespace model */

#endif /* MODEL_BOARD_HPP_ */
