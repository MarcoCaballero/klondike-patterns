#ifndef VIEW_CONSOLE_MENU_EXITCOMMAND_HPP_
#define VIEW_CONSOLE_MENU_EXITCOMMAND_HPP_

#include <view/console/menu/Command.hpp>
#include <controller/ExitController.hpp>

namespace view {

class ExitCommand: public Command {
public:
	ExitCommand(controller::ExitController* exitController);
	virtual ~ExitCommand();
	void executeChild();
private:
	controller::ExitController* exitController;
};

} /* namespace view */

#endif /* VIEW_CONSOLE_MENU_EXITCOMMAND_HPP_ */
