#ifndef VIEW_CONSOLE_MENU_FLIPCARDCOMMAND_HPP_
#define VIEW_CONSOLE_MENU_FLIPCARDCOMMAND_HPP_

#include <view/console/menu/Command.hpp>
#include <controller/FlipController.hpp>

namespace view {

class FlipCardCommand: public Command {
public:
	FlipCardCommand(controller::FlipController* flipController);
	virtual ~FlipCardCommand();
	void executeChild();
private:
	controller::FlipController* flipController;
};

} /* namespace view */

#endif /* VIEW_CONSOLE_MENU_FLIPCARDCOMMAND_HPP_ */
