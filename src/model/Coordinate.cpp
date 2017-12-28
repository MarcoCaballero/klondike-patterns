#include <model/Coordinate.hpp>

using namespace std;

namespace model {

Coordinate::Coordinate(string origin, string target) :
		origin(origin), target(target), length(0) {
}

Coordinate::Coordinate(Coordinate const& copy) :
		origin(copy.origin), target(copy.target), length(copy.length)  {
}

Coordinate::~Coordinate() {
	// TODO Auto-generated destructor stub
}

const std::string& Coordinate::getOrigin() const {
	return origin;
}

const std::string& Coordinate::getTarget() const {
	return target;
}


int Coordinate::getLength() const {
	return length;
}

void Coordinate::setLength(int length) {
	this->length = length;
}




} /* namespace view */
