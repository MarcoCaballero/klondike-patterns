#include <view/console/KlondikeViewConsole.hpp>
#include <view/KlondikeViewRegistry.hpp>

using namespace controller;
using namespace std;

namespace view {

KlondikeViewConsole::KlondikeViewConsole() {
	KlondikeViewRegistry::instance()->registerView("console", this);
}

KlondikeViewConsole::~KlondikeViewConsole() {
}

void KlondikeViewConsole::visit(StartController* startController) {
	cout << "\nKlondike v.2.0 \n" << endl;
	cout << startController->getBoard() << endl;
	startController->setState(model::State::IN_GAME);
	cout << "Menu Select Option :: " << endl;
}

void KlondikeViewConsole::visit(NewCardController* newCardController) {
	 newCardController->getBoard()->showNewDeckCard();
	cout << newCardController->getBoard() << endl;
	cout << "Menu Select Option :: " << endl;
}

} /* namespace view */
