#ifndef VIEW_CONSOLE_MENU_COMMAND_HPP_
#define VIEW_CONSOLE_MENU_COMMAND_HPP_

#include <controller/GameControllerVisitor.hpp>
#include <controller/GameController.hpp>
#include <view/console/CoordinateView.hpp>
#include <view/console/MenuView.hpp>

namespace view {

class Command {
public:
	Command(std::string title, controller::GameController* gamecontroller);
	virtual ~Command();
	const std::string& getTitle() const;
	void setTitle(const std::string& title);
	void execute();
	virtual void executeChild() = 0;
private:
	std::string title;
	controller::GameController* gamecontroller;
};

} /* namespace view */

#endif /* VIEW_CONSOLE_MENU_COMMAND_HPP_ */
