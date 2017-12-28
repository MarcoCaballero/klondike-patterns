#ifndef VIEW_CONSOLE_MENU_COMMANDDISPATCHER_HPP_
#define VIEW_CONSOLE_MENU_COMMANDDISPATCHER_HPP_

#include <view/console/menu/Command.hpp>
#include <controller/StartController.hpp>
#include <controller/NewCardController.hpp>
#include <controller/MoveCardController.hpp>
#include <controller/MoveListController.hpp>
#include <controller/FlipController.hpp>
#include <map>

namespace view {

class CommandDispatcher {
public:
	static CommandDispatcher* instance();
	virtual ~CommandDispatcher();
	void dispatch(controller::StartController* startController);
	void dispatch(controller::NewCardController* newCardController);
	void dispatch(controller::MoveCardController* moveController);
	void dispatch(controller::MoveListController* moveController);
	void dispatch(controller::FlipController* flipController);
	void dispatch(controller::ExitController* exitController);
	void dispatch(controller::WinController* winController);
private:
	static CommandDispatcher* dispatcher;
	CommandDispatcher();
};

} /* namespace view */

#endif /* VIEW_CONSOLE_MENU_COMMANDDISPATCHER_HPP_ */
