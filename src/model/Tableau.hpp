#ifndef MODEL_TABLEAU_HPP_
#define MODEL_TABLEAU_HPP_
#include <model/BoardCell.hpp>

namespace model {

class Tableau: public BoardCell {
public:
	Tableau(std::string name);
	Tableau(std::string name, const CardList& cards);
	Tableau(Tableau& tableau);
	virtual ~Tableau();
	const CardList getSubList(int length);
	bool isFullOfInvisible();
	void push(const Card& card);
	bool isAllowedPush(const Card& card);
	bool isFull();

private:
	std::string name;
	CardList cards;
};

} /* namespace model */

#endif /* MODEL_TABLEAU_HPP_ */