#ifndef VIEW_KLONDIKEVIEWREGISTRY_HPP_
#define VIEW_KLONDIKEVIEWREGISTRY_HPP_

#include <view/console/KlondikeViewConsole.hpp>
#include <map>

namespace view {

class KlondikeViewRegistry {
public:
	static KlondikeViewRegistry* instance();
	KlondikeView* lookup(std::string viewName);
	virtual ~KlondikeViewRegistry();

private:
	static KlondikeViewRegistry* klondikeViewRegistry;
	KlondikeViewRegistry();
	std::map<std::string, KlondikeView*> klondikeViewMap = {
			{"console",new KlondikeViewConsole()}
	};
};

} /* namespace view */

#endif /* VIEW_KLONDIKEVIEWREGISTRY_HPP_ */
