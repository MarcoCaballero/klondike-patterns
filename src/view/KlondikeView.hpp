#ifndef VIEW_KLONDIKEVIEW_HPP_
#define VIEW_KLONDIKEVIEW_HPP_

#include <controller/GameController.hpp>
#include <controller/GameControllerVisitor.hpp>
#include <controller/NewCardController.hpp>
#include <controller/StartController.hpp>

namespace view {

class KlondikeView: public controller::GameControllerVisitor {
public:
	virtual ~KlondikeView();
	static KlondikeView* instance();
	static std::string getSingletonConfigure();
	void interact(controller::GameController* controller);
	virtual void visit(controller::StartController* startController) override {}
	virtual void visit(controller::NewCardController* newCardController) override {}
protected:
	KlondikeView();
private:
	static KlondikeView* klondikeView;
};

} /* namespace view */

#endif /* VIEW_KLONDIKEVIEW_HPP_ */
