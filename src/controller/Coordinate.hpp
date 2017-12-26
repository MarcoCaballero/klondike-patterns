#ifndef CONTROLLER_COORDINATE_HPP_
#define CONTROLLER_COORDINATE_HPP_

#include <string>

namespace controller {

class Coordinate {
public:
	Coordinate(std::string origin, std::string target);
	Coordinate(Coordinate const& copy);
	virtual ~Coordinate();
	const std::string& getOrigin() const;
	const std::string& getTarget() const;
	bool check() const;
private:
	std::string origin;
	std::string target;
};

} /* namespace view */

#endif /* CONTROLLER_COORDINATE_HPP_ */
