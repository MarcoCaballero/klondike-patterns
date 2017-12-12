#ifndef MODEL_CARD_HPP_
#define MODEL_CARD_HPP_
#include <iostream>

namespace model {

class Card {
public:
	Card(int value, int suit, int color);
	Card(const Card &card);
	virtual ~Card();
	int getColor() const;
	void setColor(int color);
	int getSuit() const;
	int getValue() const;
	bool isVisible() const;
	void setVisibility(bool visibility);
	bool isPreviousValue(int value) const;
	bool isFollowingValue(int value) const;
	bool isEqualSuit(int suit) const;
	bool isEqualColor(int color) const;
	friend std::ostream& operator<<(std::ostream &strm, const Card &card);

private:
	int value;
	int suit;
	int color;
	bool visibility;
	int compareValue(int value) const;
};

} /* namespace controller */

#endif /* MODEL_CARD_HPP_ */
