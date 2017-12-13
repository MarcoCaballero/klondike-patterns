#ifndef MODEL_BOARDCELLVISITOR_HPP_
#define MODEL_BOARDCELLVISITOR_HPP_

#include <model/Deck.hpp>
#include <model/Tableau.hpp>

namespace model {

class BoardCellVisitor {
public:
	BoardCellVisitor();
	virtual ~BoardCellVisitor();
	virtual void visitPushList(Tableau& tableau, const CardList& cards) = 0;
	virtual const CardList visitSublist(Deck& deck, int length) = 0;
	virtual const CardList visitSublist(Tableau& tableau, int length) = 0;
};

} /* namespace model */

#endif /* MODEL_BOARDCELLVISITOR_HPP_ */
