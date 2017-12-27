#include <view/console/menu/NewCardCommand.hpp>

namespace view {

NewCardCommand::NewCardCommand(controller::NewCardController* newCardController) :
		Command("New card: ", newCardController), newCardController(newCardController) {

}

NewCardCommand::~NewCardCommand() {
}


void NewCardCommand::executeChild() {
	newCardController->control();
}

} /* namespace view */
