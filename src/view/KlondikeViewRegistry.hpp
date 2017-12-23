#ifndef VIEW_KLONDIKEVIEWREGISTRY_HPP_
#define VIEW_KLONDIKEVIEWREGISTRY_HPP_

#include <map>
#include <view/KlondikeView.hpp>

namespace view {

class KlondikeViewRegistry {
public:
	virtual ~KlondikeViewRegistry();
	static KlondikeViewRegistry* instance();
	void registerView(std::string name, KlondikeView* singleton);
	KlondikeView* lookup(std::string name);

private:
	static KlondikeViewRegistry* klondikeViewRegistry;
	std::map<std::string, KlondikeView*> klondikeViewMap;
	KlondikeViewRegistry();
};

} /* namespace view */

#endif /* VIEW_KLONDIKEVIEWREGISTRY_HPP_ */
