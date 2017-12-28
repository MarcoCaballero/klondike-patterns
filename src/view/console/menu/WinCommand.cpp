#include <view/console/menu/WinCommand.hpp>
#include <view/console/utils/IOUtils.hpp>

using namespace controller;
using namespace model;
using namespace std;

namespace view {

WinCommand::WinCommand(WinController* winController):Command("", winController), winController(winController) {
}

WinCommand::~WinCommand() {
}

void WinCommand::executeChild() {
	IOUtils::instance()->writeln("\n YOU HAVE WON !!!!!!!! \n");
	IOUtils::instance()->writeln("\n Ready to play again?, Starting new match... \n");
	winController->control();
}

} /* namespace view */
