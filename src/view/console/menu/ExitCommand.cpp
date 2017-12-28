#include <view/console/menu/ExitCommand.hpp>
#include <view/console/utils/IOUtils.hpp>

using namespace controller;
using namespace model;
using namespace std;

namespace view {

ExitCommand::ExitCommand(ExitController* exitController) :
		Command("", exitController), exitController(exitController) {

}

ExitCommand::~ExitCommand() {
}

void ExitCommand::executeChild() {
	IOUtils* io = IOUtils::instance();
	io->writeln("Are you sure?");
	system("pause");
	io->writeln("GoodBye Player");
	exitController->exitGame();
}

} /* namespace view */
