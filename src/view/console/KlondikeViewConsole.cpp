#include <view/console/KlondikeViewConsole.hpp>
#include <view/KlondikeViewRegistry.hpp>

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

void KlondikeViewConsole::visit(MoveCardController* moveController) {
	menu->dispatch(moveController);
}

void KlondikeViewConsole::visit(controller::MoveListController* moveListController) {
	menu->dispatch(moveListController);
}

void KlondikeViewConsole::visit(controller::ExitController* exitController) {
	menu->dispatch(exitController);
}

void KlondikeViewConsole::visit(controller::WinController* winController) {
	menu->dispatch(winController);
}

} /* namespace view */
