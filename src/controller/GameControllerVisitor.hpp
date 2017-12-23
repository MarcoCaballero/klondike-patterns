#ifndef CONTROLLER_GAMECONTROLLERVISITOR_HPP_
#define CONTROLLER_GAMECONTROLLERVISITOR_HPP_


namespace controller {

class GameControllerVisitor {
public:
	virtual void visit(class StartController*) = 0;
	virtual void visit(class NewCardController*) = 0;
};

} /* namespace view */

#endif /* CONTROLLER_GAMECONTROLLERVISITOR_HPP_ */
