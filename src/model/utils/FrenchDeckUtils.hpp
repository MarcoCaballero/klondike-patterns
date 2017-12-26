#ifndef UTILS_FRENCHDECK_MODEL_UTILS_HPP_
#define UTILS_FRENCHDECK_MODEL_UTILS_HPP_
#include <model/Card.hpp>
#include <string>

namespace utils {
class FrenchDeckUtils {
public:
	virtual ~FrenchDeckUtils();
	static FrenchDeckUtils* instance();
	std::string getIcon(const model::Card& card) const;
	std::string getValue(const model::Card& card) const;
	std::string getConsoleView(const model::Card& card) const;
	bool isKing(const model::Card& card) const;
	bool isAce(const model::Card& card) const;
	bool isFullDeck(const int size) const;

private:
	static FrenchDeckUtils* frenchDeckUtils;
	static const std::string ICON_HEARTS;
	static const std::string ICON_SPADES;
	static const std::string ICON_DIAMS;
	static const std::string ICON_CLUBS;
	static const std::string KING;
	static const std::string ACE;
	static const int FULL_DECK;
	FrenchDeckUtils();
};
} /* namespace model */

#endif /* UTILS_FRENCHDECK_MODEL_UTILS_HPP */
