#include <Klondike.hpp>
#include <view/KlondikeView.hpp>
#include <view/console/KlondikeViewConsole.hpp>

using namespace controller;
using namespace view;

Klondike::Klondike() {
	logic = LogicBuilder().build();
	klondikeView = KlondikeView::instance();
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

