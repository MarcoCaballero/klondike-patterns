#include <iostream>
#include <memory>
#include <string>
#include <model/Board.hpp>
#include <map>
using namespace std;
using namespace model;

int main() {

//	Test CardList
	CardList cardlist;
	for (int i = 1; i <= 13; ++i) {
		for (int j = 1; j <= 4; ++j) {
			Card card = Card(i, j, j % 2);
			cardlist.pushBack(card);
		}
	}

	Board* board = new Board(cardlist);
	cout << "Klondike v.2.0 \n" << board << endl;

	board->push("t1", board->getDeckCard());
	board->showNewDeckCard();

	cout << "Klondike v.2.0 \n" << board << endl;

	board->discardDeckCard();

	cout << "Klondike v.2.0 \n" << board << endl;

//		auto list = deckp->getSubList(5);
//		decks["dd"]->popList(5);
//		decks["dd"]->turnCard();
//
//		cout << decks["dd"] << endl;


	return EXIT_SUCCESS;
}
