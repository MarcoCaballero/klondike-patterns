#include <view/console/KlondikeViewConsole.hpp>
#include <view/console/utils/IOUtils.hpp>
#include <view/console/CoordinateView.hpp>
#include <view/console/MenuView.hpp>

using namespace controller;
using namespace std;

namespace view {

KlondikeViewConsole::KlondikeViewConsole() {
}

KlondikeViewConsole::~KlondikeViewConsole() {
}

void KlondikeViewConsole::visit(StartController* startController) {
	IOUtils::instance()->writeln("\nKlondike v.2.0 \n");
	startController->start();
	MenuView(startController).print();
}

void KlondikeViewConsole::visit(NewCardController* newCardController) {
	newCardController->control();
	MenuView(newCardController).print();
}

void KlondikeViewConsole::visit(controller::FlipController* flipController) {
	IOUtils* ioutils = IOUtils::instance();
	string key = CoordinateView(flipController).readKeyFlipSurvey();
	if (flipController->getBoard()->isFullOfInvisible(key)) {
		flipController->flip(key);
	} else {
		ioutils->writeln("Error: not allowed flip");
	}
	MenuView(flipController).print();
}

void KlondikeViewConsole::visit(MoveController* moveController) {
	IOUtils* ioutils = IOUtils::instance();
	Coordinate coordinate = CoordinateView(moveController).readCoordinate();
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
