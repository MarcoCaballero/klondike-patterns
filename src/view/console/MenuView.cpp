#include <view/console/MenuView.hpp>
#include <view/console/BoardView.hpp>
#include <view/console/utils/IOUtils.hpp>
#include <iostream>

using namespace controller;
using namespace model;

namespace view {

MenuView::MenuView(controller::GameController* gameController) :
		gameController(gameController) {
}

MenuView::~MenuView() {
}

void MenuView::print() {
	BoardView(gameController).print();
	IOUtils* io = IOUtils::instance();
	io->writeln("Menu Select Option :: \n New card: 1 \n Flip card: 2 \n Move card: 3 \n Move card list: 4 \n Finish game: 0 \n");
	int option;
	do {
		option = io->readInt("Please select an option: ");
		switch (option) {
		case 1:
			gameController->setInGameState("new");
			break;
		case 2:
			gameController->setInGameState("flip");
			break;
		case 3:
			gameController->setInGameState("move");
			break;
		case 4:
			gameController->setInGameState("movelist");
			break;
		case 0:
			gameController->setState(State::EXIT);
			break;
		default:
			io->writeln("Error bad key expected (1,2,3,4 or 0), Selected: " + option);
			break;
		}
	} while (!isAvailableOption(option));
}

bool MenuView::isAvailableOption(int number) {
	return (number >= 0 && number <= 4);
}

} /* namespace view */
