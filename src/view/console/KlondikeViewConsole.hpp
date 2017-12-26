#ifndef VIEW_CONSOLE_KLONDIKEVIEWCONSOLE_HPP_
#define VIEW_CONSOLE_KLONDIKEVIEWCONSOLE_HPP_

#include <view/KlondikeView.hpp>

namespace view {

class KlondikeViewConsole: public KlondikeView {
public:
	KlondikeViewConsole();
	virtual ~KlondikeViewConsole();
	void visit(controller::StartController* startController);
	void visit(controller::NewCardController* newCardController);
	void visit(controller::MoveController* moveController);
	void visit(controller::FlipController* flipController);
};

} /* namespace view */

#endif /* VIEW_CONSOLE_KLONDIKEVIEWCONSOLE_HPP_ */
