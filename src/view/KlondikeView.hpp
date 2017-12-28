#ifndef VIEW_KLONDIKEVIEW_HPP_
#define VIEW_KLONDIKEVIEW_HPP_

#include <controller/GameController.hpp>
#include <controller/GameControllerVisitor.hpp>
#include <controller/NewCardController.hpp>
#include <controller/StartController.hpp>
#include <controller/FlipController.hpp>
#include <controller/MoveListController.hpp>
#include <controller/MoveCardController.hpp>
#include <controller/ExitController.hpp>
#include <controller/WinController.hpp>

namespace view {

class KlondikeView: public controller::GameControllerVisitor {
public:
	virtual ~KlondikeView();
	static KlondikeView* instance();
	static std::string getSingletonConfigure();

	void interact(controller::GameController* controller);
	virtual void visit(controller::StartController* startController) = 0;
	virtual void visit(controller::NewCardController* newCardController) = 0;
	virtual void visit(controller::MoveCardController* newCardController) = 0;
	virtual void visit(controller::MoveListController* moveListController) = 0;
	virtual void visit(controller::FlipController* flipController)= 0;
	virtual void visit(controller::ExitController* exitController)= 0;
	virtual void visit(controller::WinController* winController)= 0;
protected:
	KlondikeView(void);
private:
	static KlondikeView* klondikeView;
	static const std::map<std::string, KlondikeView*> klondikeViewMap;
	static std::map<std::string, KlondikeView*> registerMap();
};

} /* namespace view */

#endif /* VIEW_KLONDIKEVIEW_HPP_ */
