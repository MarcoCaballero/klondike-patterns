#ifndef MODEL_DECK_HPP_
#define MODEL_DECK_HPP_
#include <model/BoardCell.hpp>

namespace model {

class Deck: public BoardCell {
public:
	Deck(std::string name);
	Deck(std::string name, CardList& cards);
	Deck(Deck& deck);
	virtual ~Deck();
	bool isFullOfInvisible();
	void init();
	void shuffle();
	void restoreFromWaste(Deck& waste);
	const CardList getSubList(int length);
	void push(const Card& card);
	bool isAllowedPush(const Card& card);
	bool isFull();
	void discardCard(Deck& waste);

};

} /* namespace model */

#endif /* MODEL_DECK_HPP_ */
