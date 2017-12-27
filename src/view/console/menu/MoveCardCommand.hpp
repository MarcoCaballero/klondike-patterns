#ifndef VIEW_CONSOLE_MENU_MOVECARDCOMMAND_HPP_
#define VIEW_CONSOLE_MENU_MOVECARDCOMMAND_HPP_

#include <view/console/menu/Command.hpp>
#include <controller/MoveController.hpp>

namespace view {

class MoveCardCommand: public Command {
public:
	MoveCardCommand(controller::MoveController* moveController);
	virtual ~MoveCardCommand();
	void executeChild();
private:
	controller::MoveController* moveController;
};

} /* namespace view */

#endif /* VIEW_CONSOLE_MENU_MOVECARDCOMMAND_HPP_ */
