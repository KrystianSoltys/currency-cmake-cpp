

#include <iostream>
#include "reader.hpp"
#include <locale>

auto main(int argc, char** argv) -> int
{
	std::string cd = "USD";

	auto map = GetCurrencies({ GetLink(cd, Date("10", "03", "2022")) });

	
	std::cout << cd << ": " << map.at(cd).name << " - " << map.at(cd).price << " PLN\n";

	std::cin.get();
	

	return 0;
}

