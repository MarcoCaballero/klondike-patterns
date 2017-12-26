#include <view/console/utils/MenuView.hpp>
#include <view/console/utils/IOUtils.hpp>

namespace view {

MenuView::MenuView(controller::GameController* gameController) :
		gameController(gameController) {
}

MenuView::~MenuView() {
	// TODO Auto-generated destructor stub
}

void MenuView::print() {
	IOUtils* io = IOUtils::instance();
	io->writeln("Menu Select Option :: \n NewCard: 1 \n MoveCard: 2 \n FlipCard: 3");
	int option;
	do {
		option = io->readInt("Print your option number :");
		io->writeln("selected: " + option);
		switch (option) {
		case 1:
			gameController->setInGameState("new");
			break;
		case 2:
			gameController->setInGameState("move");
			break;
		case 3:
			gameController->setInGameState("flip");
			break;
		default:
			io->writeln("Please option from 1 to 3");
			break;
		}
	} while (!isAvailableOption(option));
}

bool MenuView::isAvailableOption(int number) {
	return (number >= 0 && number <= 3);
}

} /* namespace view */
