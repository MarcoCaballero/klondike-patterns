#include <view/console/utils/IOUtils.hpp>
#include <view/console/BoardView.hpp>
#include <model/Board.hpp>

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
