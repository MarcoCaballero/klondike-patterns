#ifndef MODEL_CARDLIST_HPP_
#define MODEL_CARDLIST_HPP_
#include <iostream>
#include <assert.h>
#include <vector>
#include <model/Card.hpp>

namespace model {

class CardList {
public:
	CardList();
	CardList(std::vector<Card>& cards);
	CardList(const CardList& cardlist);
	virtual ~CardList();
	Card& getCard() ;
	Card& getCard(int pos) ;
	std::vector<Card>& getCards() ;
	CardList* getSubList(int length);
	void pushFront(const Card& card);
	void pushBack(const Card& card);
	void pushFront(CardList& cards);
	void pushBack(CardList& cards);
	void pop();
	void popList(int length);
	bool isEmpty() const;
	bool isFullOfInvisible();
	int size() const;
	friend std::ostream& operator<<(std::ostream &strm,
			const CardList &cardlist);

private:
	std::vector<Card> cards;
};

} /* namespace model */

#endif /* MODEL_CARDLIST_HPP_ */
