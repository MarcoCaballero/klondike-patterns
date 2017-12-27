#ifndef VIEW_CONSOLE_UTILS_IOUTILS_HPP_
#define VIEW_CONSOLE_UTILS_IOUTILS_HPP_

#include <model/Board.hpp>
#include <iostream>
#include <string>

namespace view {

class IOUtils {
public:
	static IOUtils* instance();
	virtual ~IOUtils();
	void write(std::string text);
	void writeln(std::string text);
	void write(model::Board* board);
	std::string readString(std::string title);
	int readInt(std::string title);
private:
	IOUtils();
	static IOUtils* ioutils;
};

} /* namespace view */

#endif /* VIEW_CONSOLE_UTILS_IOUTILS_HPP_ */
