#ifndef VIEW_CONSOLE_COORDINATEVIEW_HPP_
#define VIEW_CONSOLE_COORDINATEVIEW_HPP_

#include <view/console/utils/CoordinateChecker.hpp>
#include <model/Coordinate.hpp>
#include <controller/GameController.hpp>

namespace view {

class CoordinateView {
public:
	CoordinateView(controller::GameController * gameController);
	virtual ~CoordinateView();
	model::Coordinate readCoordinate();
	model::Coordinate readCoordinateLength();
	std::string readOrigin();
	std::string readKeyFlipSurvey();
private:
	controller::GameController * gameController;
	CoordinateChecker checker;
	std::string readKey(std::string title);
	std::string readTableauKey(std::string title);
};

} /* namespace view */

#endif /* VIEW_CONSOLE_COORDINATEVIEW_HPP_ */
