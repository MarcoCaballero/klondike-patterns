#include <view/KlondikeViewRegistry.hpp>

using namespace std;

namespace view {

KlondikeViewRegistry* KlondikeViewRegistry::klondikeViewRegistry = nullptr;

KlondikeViewRegistry::KlondikeViewRegistry() {
}

KlondikeViewRegistry::~KlondikeViewRegistry() {
}

KlondikeViewRegistry* KlondikeViewRegistry::instance() {
	if (!klondikeViewRegistry) {
		klondikeViewRegistry = new KlondikeViewRegistry();
	}
	return klondikeViewRegistry;
}

KlondikeView* KlondikeViewRegistry::lookup(std::string viewName) {
	return klondikeViewMap.find(viewName)->second;
}


} /* namespace view */
