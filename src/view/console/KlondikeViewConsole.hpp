#ifndef VIEW_CONSOLE_KLONDIKEVIEWCONSOLE_HPP_
#define VIEW_CONSOLE_KLONDIKEVIEWCONSOLE_HPP_

#include <view/KlondikeView.hpp>


namespace view {

class KlondikeViewConsole: public KlondikeView {
public:
	KlondikeViewConsole();
	virtual ~KlondikeViewConsole();
	/*virtual*/ void visit(controller::StartController* startController);
	/*virtual*/ void visit(controller::NewCardController* newCardController);
	/*virtual*/ void visit(controller::MoveController* moveController);
};

} /* namespace view */

#endif /* VIEW_CONSOLE_KLONDIKEVIEWCONSOLE_HPP_ */
