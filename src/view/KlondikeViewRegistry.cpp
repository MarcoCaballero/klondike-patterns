#include <view/KlondikeViewRegistry.hpp>

namespace view {
KlondikeViewRegistry* KlondikeViewRegistry::klondikeViewRegistry = nullptr;

KlondikeViewRegistry::KlondikeViewRegistry() {
}

KlondikeViewRegistry::~KlondikeViewRegistry() {
}

KlondikeViewRegistry* KlondikeViewRegistry::instance() {
	if (klondikeViewRegistry == nullptr) {
		klondikeViewRegistry = new KlondikeViewRegistry();
	}
	return klondikeViewRegistry;
}
void KlondikeViewRegistry::registerView(std::string name,
		KlondikeView* singleton) {
	klondikeViewMap[name] = singleton;
}
KlondikeView* KlondikeViewRegistry::lookup(std::string name) {
	return klondikeViewMap.find(name)->second;
}

} /* namespace view */
