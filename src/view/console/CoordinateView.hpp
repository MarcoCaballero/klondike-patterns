#ifndef VIEW_CONSOLE_COORDINATEVIEW_HPP_
#define VIEW_CONSOLE_COORDINATEVIEW_HPP_

#include <view/console/utils/CoordinateChecker.hpp>
#include <controller/Coordinate.hpp>
#include <controller/GameController.hpp>

namespace view {

class CoordinateView {
public:
	CoordinateView();
	virtual ~CoordinateView();
	controller::Coordinate readCoordinate(controller::GameController * gameController);
};

} /* namespace view */

#endif /* VIEW_CONSOLE_COORDINATEVIEW_HPP_ */
