#ifndef VIEW_CONSOLE_MENU_COMMANDDISPATCHER_HPP_
#define VIEW_CONSOLE_MENU_COMMANDDISPATCHER_HPP_

#include <view/console/menu/Command.hpp>
#include <controller/GameControllerVisitor.hpp>
#include <map>

namespace view {

class CommandDispatcher {
public:
	static CommandDispatcher* instance();
	virtual ~CommandDispatcher();
	void dispatch(controller::StartController* startController);
	void dispatch(controller::NewCardController* newCardController);
	void dispatch(controller::MoveController* moveController);
	void dispatch(controller::FlipController* flipController);
private:
	static CommandDispatcher* dispatcher;
	CommandDispatcher();
};

} /* namespace view */

#endif /* VIEW_CONSOLE_MENU_COMMANDDISPATCHER_HPP_ */
