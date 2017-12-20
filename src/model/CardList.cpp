#include <string>
#include <model/CardList.hpp>
using namespace std;

namespace model {

CardList::CardList() {
}

CardList::CardList(vector<Card>& cards) :
		cards(cards) {
}

CardList::CardList(const CardList& cardlist) :
		cards(cardlist.cards) {
}

CardList::~CardList() {
}

bool CardList::isEmpty() const {
	return cards.empty();
}

int CardList::size() const {
	return cards.size();
}

Card& CardList::getCard() {
	assert(!isEmpty());
	return cards.front();
}

Card& CardList::getCard(int pos) {
	assert(!isEmpty());
	return cards[pos];
}

std::vector<Card>& CardList::getCards() {
	return cards;
}

CardList* CardList::getSubList(int length) {
	CardList* sublist = new CardList();
	for (int i = 0; i < length; ++i) {
		sublist->pushBack(getCard(i));
	}
	return sublist;
}

void CardList::pushFront(const Card& card) {
	cards.insert(cards.begin(), card);
}

void CardList::pushBack(const Card& card) {
	cards.push_back(card);
}

void CardList::pushFront(CardList& cards) {
	for (int i = 0; i < cards.size(); ++i) {
		pushFront(cards.getCard(i));
	}
}

void CardList::pushBack(CardList& cards) {
	for (int i = 0; i < cards.size(); ++i) {
		pushBack(cards.getCard(i));
	}
}

void CardList::pop() {
	assert(!isEmpty());
	cards.erase(cards.begin());
}

void CardList::popList(int length) {
	assert(length < size());
	for (int i = 0; i < length; ++i) {
		pop();
	}
}

bool CardList::isFullOfInvisible() {
	bool status = true;
	for (auto &v : getCards()) {
		if (v.isVisible())
			status = false;
	}
	return status;
}

std::ostream& operator<<(std::ostream &strm, const CardList &cardlist) {
	for (auto &v : cardlist.cards) {
		strm << v;
	}
	return strm;
}

} /* namespace model */
