#include <view/console/menu/Command.hpp>
namespace view {

Command::Command(std::string title, controller::GameController* gamecontroller) :
		title(title), gamecontroller(gamecontroller) {

}

Command::~Command() {
}

const std::string& Command::getTitle() const {
	return title;
}

void Command::setTitle(const std::string& title) {
	this->title = title;
}

void Command::execute() {
	this->executeChild();
	MenuView(gamecontroller).print();
}

} /* namespace view */
