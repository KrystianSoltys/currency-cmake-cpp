#include "ui.hpp"

auto UI::Headline() -> std::string
{
	std::string toReturn;
	if (false)
		toReturn = ("---------------Konwerter Walut ", INFO::VERSION, "---------------");

	else 
		toReturn = ("---------------Currency Converter ", INFO::VERSION, "---------------");
		
	return toReturn;
}
