#include <model/BoardBuilder.hpp>

namespace model {

BoardBuilder::BoardBuilder(CardList& cardlist) :
		board(new Board()), cardlist(cardlist) {
}

BoardBuilder::BoardBuilder(BoardBuilder const& builder) :
		board(builder.board), cardlist(builder.cardlist) {
}

Board* BoardBuilder::build() {
	buildDecks();
	buildTableaus();
	buildFoundations();
	return board;
}

void BoardBuilder::buildDecks() {
	decks[DECK] = new Deck(DECK, cardlist);
	decks[WASTE] = new Deck(WASTE);
	decks[DECK]->init();
	board->setDecks(decks);
}

void BoardBuilder::buildTableaus() {
	for (int i = 1; i <= TABLEAUS_SIZE; ++i) {
		std::string str = "t" + std::to_string(i);
		tableaus[str] = new Tableau(str);
		for (int j = 1; j <= i; j++) {
			if (j == i)
				decks[DECK]->turnCard();
			std::string str = "t" + std::to_string(i);
			tableaus[str]->push(decks[DECK]->getCard());
			decks[DECK]->pop();
		}
	}
	decks[DECK]->turnCard();
	board->setTableaus(tableaus);
}

void BoardBuilder::buildFoundations() {
	for (int i = 1; i <= FOUNDATIONS_SIZE; ++i) {
		std::string str = "f" + std::to_string(i);
		foundations[str] = new Foundation(str);
	}
	board->setFoundations(foundations);
}

} /* namespace model */
