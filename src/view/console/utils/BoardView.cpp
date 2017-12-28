#include <view/console/utils/IOUtils.hpp>
#include <view/console/utils/BoardView.hpp>

using namespace model;

namespace view {

BoardView::BoardView(controller::GameController* gameController): gameController(gameController) {
}

BoardView::~BoardView() {
}

void BoardView::print() {
	IOUtils::instance()->write(gameController->getBoard());
}


} /* namespace view */
