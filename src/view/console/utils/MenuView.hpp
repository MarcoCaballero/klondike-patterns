#ifndef VIEW_CONSOLE_UTILS_MENUVIEW_HPP_
#define VIEW_CONSOLE_UTILS_MENUVIEW_HPP_

#include <controller/GameController.hpp>

namespace view {

class MenuView {
public:
	MenuView(controller::GameController*);
	virtual ~MenuView();
	void print();
private:
	controller::GameController* gameController;
	bool isAvailableOption(int number);
};

} /* namespace view */

#endif /* VIEW_CONSOLE_UTILS_MENUVIEW_HPP_ */
