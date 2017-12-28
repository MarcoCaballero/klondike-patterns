#include <view/console/menu/CommandDispatcher.hpp>
#include <view/console/menu/MoveCardCommand.hpp>
#include <view/console/menu/MoveListCommand.hpp>
#include <view/console/menu/NewCardCommand.hpp>
#include <view/console/menu/FlipCardCommand.hpp>
#include <view/console/menu/StartCommand.hpp>
#include <view/console/menu/ExitCommand.hpp>
#include <view/console/menu/WinCommand.hpp>

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

void CommandDispatcher::dispatch(
		controller::MoveCardController* moveController) {
	MoveCardCommand(moveController).execute();
}

void CommandDispatcher::dispatch(
		controller::MoveListController* moveController) {
	MoveListCommand(moveController).execute();
}

void CommandDispatcher::dispatch(controller::FlipController* flipController) {
	FlipCardCommand(flipController).execute();
}

void CommandDispatcher::dispatch(
		controller::NewCardController* newCardController) {
	NewCardCommand(newCardController).execute();
}

void CommandDispatcher::dispatch(controller::StartController* startController) {
	StartCommand(startController).execute();
}

void CommandDispatcher::dispatch(controller::ExitController* exitController) {
	ExitCommand(exitController).execute();
}

void CommandDispatcher::dispatch(controller::WinController* winController) {
	WinCommand(winController).execute();
}
} /* namespace view */
