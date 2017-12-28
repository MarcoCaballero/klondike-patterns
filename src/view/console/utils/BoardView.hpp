#ifndef VIEW_CONSOLE_BOARDVIEW_HPP_
#define VIEW_CONSOLE_BOARDVIEW_HPP_

#include <controller/GameController.hpp>

namespace view {

class BoardView {
public:
	BoardView(controller::GameController*);
	virtual ~BoardView();
	void print();
private:
	controller::GameController* gameController;
};

} /* namespace view */

#endif /* VIEW_CONSOLE_BOARDVIEW_HPP_ */
