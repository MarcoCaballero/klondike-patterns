#include <view/console/KlondikeViewConsole.hpp>
#include <view/console/BoardView.hpp>
#include <view/console/utils/IOUtils.hpp>
#include <view/console/utils/MenuView.hpp>

using namespace controller;
using namespace view;
using namespace std;

namespace view {

KlondikeViewConsole::KlondikeViewConsole() {
}

KlondikeViewConsole::~KlondikeViewConsole() {
}

void KlondikeViewConsole::visit(StartController* startController) {
	cout << "\nKlondike v.2.0 \n" << endl;
	BoardView(startController).print();
	startController->setState(model::State::IN_GAME);
	MenuView(startController).print();
}

void KlondikeViewConsole::visit(NewCardController* newCardController) {
	newCardController->getBoard()->showNewDeckCard();
	BoardView(newCardController).print();
	MenuView(newCardController).print();
}

void KlondikeViewConsole::visit(MoveController* moveController) {
	IOUtils* ioutils = IOUtils::instance();
	CoordinateChecker checker(moveController->getBoard());
	string origin;
	string target;
	do {
		origin = ioutils->readString("Select Origin");
	} while (checker.isValid(origin));
	do {
		target = ioutils->readString("Select Target");
	} while (checker.isValid(target));

	Coordinate coordinate(origin, target);

	switch (moveController->checkMove(coordinate)) {
	case Status::NOT_ALLOWED_MOVE:
		ioutils->writeln("Error: not allowed move");
		break;
	default:
		moveController->move(coordinate);
		break;
	}
	MenuView(moveController).print();
}

} /* namespace view */
