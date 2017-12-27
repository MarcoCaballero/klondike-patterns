#include <view/console/KlondikeViewConsole.hpp>

using namespace controller;
using namespace model;
using namespace std;

namespace view {

KlondikeViewConsole::KlondikeViewConsole() {
	menu = CommandDispatcher::instance();
}

KlondikeViewConsole::~KlondikeViewConsole() {
}

void KlondikeViewConsole::visit(StartController* startController) {
	menu->dispatch(startController);
}

void KlondikeViewConsole::visit(NewCardController* newCardController) {
	menu->dispatch(newCardController);
}

void KlondikeViewConsole::visit(controller::FlipController* flipController) {
	menu->dispatch(flipController);
}

void KlondikeViewConsole::visit(MoveController* moveController) {
	menu->dispatch(moveController);
}

} /* namespace view */
