#include <view/console/menu/FlipCardCommand.hpp>
#include <view/console/utils/IOUtils.hpp>

using namespace controller;
using namespace model;
using namespace std;

namespace view {

FlipCardCommand::FlipCardCommand(FlipController* flipController) :
		Command("Flip card: ", flipController), flipController(flipController) {
}

FlipCardCommand::~FlipCardCommand() {
}

void FlipCardCommand::executeChild() {
	IOUtils* ioutils = IOUtils::instance();
	string key = CoordinateView(flipController).readKeyFlipSurvey();
	if (flipController->getBoard()->isFullOfInvisible(key)) {
		flipController->flip(key);
	} else {
		ioutils->writeln("Error: not allowed flip");
	}
}

} /* namespace view */
