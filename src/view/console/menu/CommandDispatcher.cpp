#include <view/console/menu/CommandDispatcher.hpp>
#include <view/console/menu/MoveCardCommand.hpp>
#include <view/console/menu/NewCardCommand.hpp>
#include <view/console/menu/FlipCardCommand.hpp>
#include <view/console/menu/StartCommand.hpp>

namespace view {
CommandDispatcher* CommandDispatcher::dispatcher = nullptr;

CommandDispatcher::CommandDispatcher() {
}

CommandDispatcher::~CommandDispatcher() {
}

CommandDispatcher* CommandDispatcher::instance() {
	if (!dispatcher) {
		dispatcher = new CommandDispatcher();
	}
	return dispatcher;
}

void CommandDispatcher::dispatch(controller::MoveController* moveController) {
	MoveCardCommand(moveController).execute();
}

void CommandDispatcher::dispatch(controller::FlipController* flipController) {
	FlipCardCommand(flipController).execute();
}

void CommandDispatcher::dispatch(controller::NewCardController* newCardController) {
	NewCardCommand(newCardController).execute();
}

void CommandDispatcher::dispatch(controller::StartController* startController) {
	StartCommand(startController).execute();
}
} /* namespace view */
