#ifndef VIEW_CONSOLE_MENU_MOVELISTCOMMAND_HPP_
#define VIEW_CONSOLE_MENU_MOVELISTCOMMAND_HPP_

#include <controller/MoveListController.hpp>
#include <view/console/menu/Command.hpp>

namespace view {

class MoveListCommand: public Command {
public:
	MoveListCommand(controller::MoveListController* moveController);
	virtual ~MoveListCommand();
	void executeChild();
private:
	controller::MoveListController* moveController;
};

} /* namespace view */

#endif /* VIEW_CONSOLE_MENU_MOVELISTCOMMAND_HPP_ */
