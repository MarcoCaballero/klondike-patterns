#ifndef MODEL_DECK_HPP_
#define MODEL_DECK_HPP_
#include <memory>
#include <model/BoardCell.hpp>

namespace model {

class Deck: public BoardCell, std::enable_shared_from_this<Deck> {
public:
	Deck(std::string name);
	Deck(std::string name, CardList& cards);
	Deck(Deck& deck);
	virtual ~Deck();
	bool isFullOfInvisible();
	void init();
	void shuffle();
	void restoreFromWaste(Deck& waste);
	CardList* getSubList(int length);
	void push(const Card& card);
	bool isAllowedPush(const Card& card);
	bool isFull();
	void discardCardTo(Deck& waste);

};

} /* namespace model */

#endif /* MODEL_DECK_HPP_ */
