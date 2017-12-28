#ifndef VIEW_CONSOLE_MENU_MOVECARDCOMMAND_HPP_
#define VIEW_CONSOLE_MENU_MOVECARDCOMMAND_HPP_

#include <controller/MoveCardController.hpp>
#include <view/console/menu/Command.hpp>

namespace view {

class MoveCardCommand: public Command {
public:
	MoveCardCommand(controller::MoveCardController* moveController);
	virtual ~MoveCardCommand();
	void executeChild();
private:
	controller::MoveCardController* moveController;
};

} /* namespace view */

#endif /* VIEW_CONSOLE_MENU_MOVECARDCOMMAND_HPP_ */
