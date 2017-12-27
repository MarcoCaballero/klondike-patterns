#ifndef MODEL_BOARDBUILDER_HPP_
#define MODEL_BOARDBUILDER_HPP_
#include <model/Board.hpp>

namespace model {

class BoardBuilder {
public:
	BoardBuilder(CardList& cardlist);
	BoardBuilder(void) = delete;
	BoardBuilder(BoardBuilder const& builder);
	BoardBuilder& operator=(BoardBuilder const& rhs) = delete;
	BoardBuilder(BoardBuilder && rhs) noexcept =delete;
	BoardBuilder& operator=(BoardBuilder&& rhs) noexcept =delete;
	virtual ~BoardBuilder(void) = default;
	Board* build();

private:
	Board* board;
	std::map<std::string, Deck*> decks;
	std::map<std::string, Foundation*> foundations;
	std::map<std::string, Tableau*> tableaus;
	CardList cardlist;
	void buildDecks();
	void buildTableaus();
	void buildFoundations();
	const std::string DECK = "dd";
	const std::string WASTE = "dw";
	const int FOUNDATIONS_SIZE = 4;
	const int TABLEAUS_SIZE = 7;
};

} /* namespace model */

#endif /* MODEL_BOARDBUILDER_HPP_ */
