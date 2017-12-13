#include <iostream>
#include <memory>
#include <string>
#include <model/Tableau.hpp>
#include <model/Deck.hpp>
#include <model/Foundation.hpp>
using namespace std;
using namespace model;

int main() {

//	Test CardList
	CardList cl1;
	for (int i = 1; i <= 13; ++i) {
		for (int j = 1; j <= 4; ++j) {
			Card card = Card(i, j, j % 2);
			cl1.pushBack(card);
		}
	}

// 	Test Deck
	Deck deck("deck", cl1);
	Deck waste("waste");
	deck.init();
	cout << waste << endl;
	cout << deck << endl;
	auto list = deck.getSubList(5);
	deck.popList(5);
	deck.turnCard();

	cout << endl;

//	Test tableau
	Tableau tableau("t1", list);
	cout << deck << endl;
	cout << waste << endl;
	cout << tableau << endl;

	cout << endl;

//	Test foundation
	Foundation found("f1");
	Card card = tableau.getCard();
	tableau.pop();
	tableau.turnCard();
	found.push(card);
	cout << deck << endl;
	cout << waste << endl;
	cout << tableau << endl;
	cout << found << endl;

	cout << endl;

//	test Waste
	deck.discardCardTo(waste);
	cout << deck << endl;
	cout << waste << endl;
	cout << tableau << endl;
	cout << found << endl;

	return EXIT_SUCCESS;
}
