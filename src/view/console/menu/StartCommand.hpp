#ifndef VIEW_CONSOLE_MENU_STARTCOMMAND_HPP_
#define VIEW_CONSOLE_MENU_STARTCOMMAND_HPP_

#include <view/console/menu/Command.hpp>
#include <controller/StartController.hpp>

namespace view {

class StartCommand: public Command {
public:
	StartCommand(controller::StartController* startController);
	virtual ~StartCommand();
	void executeChild();
private:
	controller::StartController* startController;
};

} /* namespace view */

#endif /* VIEW_CONSOLE_MENU_STARTCOMMAND_HPP_ */
