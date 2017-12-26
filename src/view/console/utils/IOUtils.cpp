#include <view/console/utils/IOUtils.hpp>

using namespace std;

namespace view {
IOUtils* IOUtils::ioutils = nullptr;

IOUtils* IOUtils::instance() {
	if (!ioutils) {
		ioutils = new IOUtils();
	}
	return ioutils;
}

IOUtils::IOUtils() {
}

IOUtils::~IOUtils() {
}

void IOUtils::write(model::Board* board) {
	cout << board;
}

void IOUtils::write(std::string text) {
	cout << text;
}

void IOUtils::writeln(std::string text) {
	cout << text << endl;
}

std::string IOUtils::readString(std::string title) {
	string readLine;
	write(title);
	cin >> readLine;
	cin.clear();
	return readLine;
}

int IOUtils::readInt(std::string title) {
	int readLine;
	write(title);
	cin >> readLine;
	cin.clear();
	return readLine;
}
}
/* namespace view */
