#include <model/BoardBuilder.hpp>
#include <model/Deck.hpp>

using namespace std;

namespace model {

BoardBuilder::BoardBuilder() {
}

BoardBuilder::~BoardBuilder() {
}

Board* BoardBuilder::getBoard() {
	return board.release();
}

void BoardBuilder::buildCells() {
	board = make_unique<Board>();
	map<std::string, std::shared_ptr<BoardCell>> cells;
	string name = board->getDeck();
	cout << "name" << name;
	cells[name] = make_shared<Deck>(name);

}

void BoardBuilder::buildDecks(const CardList& cards) {

}

void BoardBuilder::buildTableaus() {
}

void BoardBuilder::buildFoundations() {
}

} /* namespace model */
