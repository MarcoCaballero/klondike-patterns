#include <model/Coordinate.hpp>

using namespace std;

namespace model {

Coordinate::Coordinate(string origin, string target) :
		origin(origin), target(target) {
}

Coordinate::Coordinate(Coordinate const& copy) :
		origin(copy.origin), target(copy.target) {
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


} /* namespace view */
