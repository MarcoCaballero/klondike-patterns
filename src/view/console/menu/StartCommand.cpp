#include <view/console/utils/IOUtils.hpp>
#include <view/console/menu/StartCommand.hpp>

using namespace controller;
using namespace model;
using namespace std;

namespace view {

StartCommand::StartCommand(StartController* startController) :
		Command("Start new match", startController), startController(startController) {

}

StartCommand::~StartCommand() {
}

void StartCommand::executeChild() {
	IOUtils::instance()->writeln("\nKlondike v.2.0 \n");
	startController->start();
}

} /* namespace view */
