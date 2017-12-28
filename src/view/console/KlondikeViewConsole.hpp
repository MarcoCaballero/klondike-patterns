#ifndef VIEW_CONSOLE_KLONDIKEVIEWCONSOLE_HPP_
#define VIEW_CONSOLE_KLONDIKEVIEWCONSOLE_HPP_

#include <view/console/menu/CommandDispatcher.hpp>
#include <view/KlondikeView.hpp>

namespace view {

class KlondikeViewConsole: public KlondikeView {
public:
	KlondikeViewConsole();
	virtual ~KlondikeViewConsole();
	void visit(controller::StartController* startController);
	void visit(controller::NewCardController* newCardController);
	void visit(controller::MoveCardController* moveController);
	void visit(controller::MoveListController* moveListController);
	void visit(controller::FlipController* flipController);
	void visit(controller::ExitController* exitController);
	void visit(controller::WinController* winController);
private:
	CommandDispatcher* menu;

};

} /* namespace view */

#endif /* VIEW_CONSOLE_KLONDIKEVIEWCONSOLE_HPP_ */
