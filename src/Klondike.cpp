#include <Klondike.hpp>
#include <view/KlondikeView.hpp>

using namespace controller;
using namespace view;

Klondike::Klondike() {
	logic = new Logic();
	klondikeView = KlondikeView::instance();
}

Klondike::~Klondike() {
}

void Klondike::play() {
	GameController* gameController;
	do {
		gameController = logic->getController();
		if (gameController != NULL) {
			klondikeView->interact(gameController);
		}
	} while (gameController != nullptr);
}

auto main() -> int {
	Klondike().play();
}

