#include <view/console/KlondikeViewConsole.hpp>
#include <fstream>
#include <sstream>
#include <iostream>

using namespace controller;
using namespace std;

namespace view {
KlondikeView* KlondikeView::klondikeView = nullptr;
const map<std::string, KlondikeView*> KlondikeView::klondikeViewMap =
		KlondikeView::registerMap();

KlondikeView::KlondikeView(void) {
}

KlondikeView::~KlondikeView() {
}

KlondikeView* KlondikeView::instance() {
	if (klondikeView == nullptr) {
		string line = KlondikeView::getSingletonConfigure();
		klondikeView = klondikeViewMap.find(line)->second;
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

std::map<std::string, KlondikeView*> KlondikeView::registerMap() {
	map<std::string, KlondikeView*> m;
	m["console"] = new KlondikeViewConsole();
	return m;
}

void KlondikeView::interact(GameController* gameController) {
	assert(gameController != nullptr);
	gameController->accept(this);
}

}
