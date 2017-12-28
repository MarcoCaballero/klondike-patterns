#include <view/console/KlondikeViewConsole.hpp>
#include <view/KlondikeViewRegistry.hpp>
#include <fstream>
#include <sstream>
#include <iostream>

using namespace controller;
using namespace std;

namespace view {
KlondikeView* KlondikeView::klondikeView = nullptr;

KlondikeView::KlondikeView(void) {
}

KlondikeView::~KlondikeView() {
}

KlondikeView* KlondikeView::instance() {
	if (klondikeView == nullptr) {
		string line = KlondikeView::getSingletonConfigure();
		klondikeView = KlondikeViewRegistry::instance()->lookup(line);
	}
	return klondikeView;
}

std::string KlondikeView::getSingletonConfigure() {
	ifstream ifs("src/view/conf.txt");
	string line;
	getline(ifs, line);
	ifs.close();
	return line;
}


void KlondikeView::interact(GameController* gameController) {
	assert(gameController != nullptr);
	gameController->accept(this);
}

}
