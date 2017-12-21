#include <iostream>
#include <memory>
#include <string>
#include <model/BoardBuilder.hpp>
#include <map>
using namespace std;
using namespace model;

auto main() -> int {

//	Test CardList
	CardList cardlist;
	for (int i = 1; i <= 13; ++i) {
		for (int j = 1; j <= 4; ++j) {
			Card card = Card(i, j, j % 2);
			cardlist.pushBack(card);
		}
	}

//	Board* board = new Board(cardlist);
	Board* board = BoardBuilder(cardlist).build();

	cout << "\nKlondike v.2.0 \n" << board << endl;

	cout << "permiso: " << std::boolalpha << board->isAllowedPush("dd", "t1");

	board->push("t1", board->getDeckCard());
	board->showNewDeckCard();

	cout << "\nKlondike v.2.0 \n" << board << endl;

	board->discardDeckCard();

	cout << "\nKlondike v.2.0 \n" << board << endl;

//		auto list = deckp->getSubList(5);
//		decks["dd"]->popList(5);
//		decks["dd"]->turnCard();
//
//		cout << decks["dd"] << endl;


	return EXIT_SUCCESS;
}
