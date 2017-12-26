#ifndef VIEW_KLONDIKEVIEW_HPP_
#define VIEW_KLONDIKEVIEW_HPP_

#include <controller/GameController.hpp>
#include <controller/GameControllerVisitor.hpp>
#include <controller/NewCardController.hpp>
#include <controller/MoveController.hpp>
#include <controller/StartController.hpp>
#include <controller/FlipController.hpp>

namespace view {

class KlondikeView: public controller::GameControllerVisitor {
public:
	virtual ~KlondikeView();
	static KlondikeView* instance();
	static std::string getSingletonConfigure();

	void interact(controller::GameController* controller);
	virtual void visit(controller::StartController* startController) override {}
	virtual void visit(controller::NewCardController* newCardController) override {}
	virtual void visit(controller::MoveController* newCardController) override {}
	virtual void visit(controller::FlipController* flipController) override {}
protected:
	KlondikeView(void);
private:
	static KlondikeView* klondikeView;
	static const std::map<std::string, KlondikeView*> klondikeViewMap;
	static std::map<std::string, KlondikeView*> registerMap();
};

} /* namespace view */

#endif /* VIEW_KLONDIKEVIEW_HPP_ */
