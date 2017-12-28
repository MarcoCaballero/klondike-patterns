#ifndef VIEW_CONSOLE_MENU_WINCOMMAND_HPP_
#define VIEW_CONSOLE_MENU_WINCOMMAND_HPP_

#include <view/console/menu/Command.hpp>
#include <controller/WinController.hpp>

namespace view {

class WinCommand: public Command {
public:
	WinCommand(controller::WinController* winController);
	virtual ~WinCommand();
	void executeChild();

private:
	controller::WinController* winController;
};

} /* namespace view */

#endif /* VIEW_CONSOLE_MENU_WINCOMMAND_HPP_ */
