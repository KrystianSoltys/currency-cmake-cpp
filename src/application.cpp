#include "application.hpp"


Application::Application(int c, char** v)
	: argc(c), argv(v)
{
}

auto Application::exec() -> int
{
	std::vector<std::string> linksVec;
	
	std::string d, m, y;

	bool isDateSet = checkDate();
	std::uint16_t len = (isDateSet ? argc - 1 : argc);

	if (isDateSet)
	{
		std::string dateStr = argv[argc - 1];
		d = dateStr.substr(0, 2);
		m = dateStr.substr(3, 2);
		y = dateStr.substr(6, 4);
	}

	for (std::uint16_t i = 1; i < len; i++)
	{
		linksVec.push_back(GetLink(argv[i], Date(d, m, y)));
	}
	
	auto map = GetCurrencies(linksVec);

	for (std::uint16_t i = 1; i < len; i++)
	{
		std::cout << argv[i] << ": " << map.at(argv[i]).price << "\t" << map.at(argv[i]).date << std::endl;
	}

	return 0;
}

auto Application::checkDate() -> bool
{
	std::string lastArg =argv[argc-1];

	if (lastArg.size() == 10 &&
		lastArg[2] == '-' &&
		lastArg[5] == '-')
		return true;


	return false;
}
