#ifndef MODEL_FOUNDATION_HPP_
#define MODEL_FOUNDATION_HPP_
#include <model/BoardCell.hpp>

namespace model {

class Foundation: public BoardCell {
public:
	Foundation(std::string name);
	Foundation(std::string name, const CardList& cards);
	Foundation(Foundation& foundation);
	virtual ~Foundation();
	void push(const Card& card);
	bool isAllowedPush(const Card& card);
	bool isFull();

private:
	bool checkSuit(int suit);
	bool checkValue(int value);
};

} /* namespace model */

#endif /* MODEL_FOUNDATION_HPP_ */
