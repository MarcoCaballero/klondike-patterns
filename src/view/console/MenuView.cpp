#include <view/console/MenuView.hpp>
#include <view/console/BoardView.hpp>
#include <view/console/utils/IOUtils.hpp>
#include <iostream>

namespace view {

MenuView::MenuView(controller::GameController* gameController) :
		gameController(gameController) {
}

MenuView::~MenuView() {
	// TODO Auto-generated destructor stub
}

void MenuView::print() {
	BoardView(gameController).print();
	IOUtils* io = IOUtils::instance();
	io->writeln("Menu Select Option :: \n NewCard: 1 \n MoveCard: 2 \n FlipCard: 3 \n");
	int option;
	do {
		option = io->readInt("Please select an option between 1 and 3: ");
		switch (option) {
		case 1:
			io->writeln("Selected: new:");
			gameController->setInGameState("new");
			break;
		case 2:
			io->writeln("Selected: move:");
			gameController->setInGameState("move");
			break;
		case 3:
			io->writeln("Selected: flip:");
			gameController->setInGameState("flip");
			break;
		default:
			io->writeln("Error bad key expected (1,2,3), Selected: " + option );
			break;
		}
	} while (!isAvailableOption(option));
}

bool MenuView::isAvailableOption(int number) {
	return (number >= 1 && number <= 3);
}

} /* namespace view */
