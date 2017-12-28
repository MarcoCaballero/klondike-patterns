#ifndef KLONDIKE_HPP_
#define KLONDIKE_HPP_
#include <controller/LogicBuilder.hpp>
#include <view/KlondikeView.hpp>

class Klondike {
public:
public:
	Klondike();
	virtual ~Klondike();
	void play();
private:
	controller::Logic* logic;
	view::KlondikeView* klondikeView;
};

#endif /* KLONDIKE_HPP_ */
