#include <view/console/KlondikeViewConsole.hpp>
#include <view/KlondikeViewRegistry.hpp>
#include <fstream>

using namespace controller;
using namespace std;

namespace view {
KlondikeView* KlondikeView::klondikeView = nullptr;

KlondikeView* KlondikeView::instance() {
	if (klondikeView == nullptr) {
		string line = KlondikeView::getSingletonConfigure();
		klondikeView = KlondikeViewRegistry::instance()->lookup(line);
	}
	return klondikeView;
}

std::string KlondikeView::getSingletonConfigure() {
	ifstream ifs("view-conf.txt");
	string line;
	ifs >> line;
	ifs.close();
	return line;
}

void KlondikeView::interact(GameController* gameController) {
	assert(gameController != nullptr);
	gameController->accept(this);
}

}
