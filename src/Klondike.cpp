#include <Klondike.hpp>
#include <view/KlondikeView.hpp>
#include <view/console/KlondikeViewConsole.hpp>

using namespace controller;
using namespace view;

Klondike::Klondike() {
	logic = new Logic();
	klondikeView = KlondikeView::instance();
//	klondikeView = new KlondikeViewConsole();
}

Klondike::~Klondike() {
}

void Klondike::play() {
	GameController* gameController;
	do {
		gameController = logic->getController();
		if (gameController) {
			klondikeView->interact(gameController);
		}
	} while (gameController);
}
using namespace std;
auto main() -> int {
	Klondike().play();
}

