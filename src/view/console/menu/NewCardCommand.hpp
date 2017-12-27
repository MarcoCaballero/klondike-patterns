#ifndef VIEW_CONSOLE_MENU_NEWCARDCOMMAND_HPP_
#define VIEW_CONSOLE_MENU_NEWCARDCOMMAND_HPP_

#include <view/console/menu/Command.hpp>
#include <controller/NewCardController.hpp>

namespace view {

class NewCardCommand: public Command {
public:
	NewCardCommand(controller::NewCardController* newCardController);
	virtual ~NewCardCommand();
	void executeChild();

private:
	controller::NewCardController* newCardController;
};

} /* namespace view */

#endif /* VIEW_CONSOLE_MENU_NEWCARDCOMMAND_HPP_ */
