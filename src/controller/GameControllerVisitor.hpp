#ifndef CONTROLLER_GAMECONTROLLERVISITOR_HPP_
#define CONTROLLER_GAMECONTROLLERVISITOR_HPP_


namespace controller {

class GameControllerVisitor {
public:
	virtual void visit(class StartController*) = 0;
	virtual void visit(class NewCardController*) = 0;
	virtual void visit(class MoveCardController*) = 0;
	virtual void visit(class FlipController*) = 0;
	virtual void visit(class MoveListController*) = 0;
	virtual void visit(class ExitController*) = 0;
	virtual void visit(class WinController*) = 0;
};

} /* namespace view */

#endif /* CONTROLLER_GAMECONTROLLERVISITOR_HPP_ */
