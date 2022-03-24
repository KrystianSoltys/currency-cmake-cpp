#include "application.hpp"


Application::Application(int c, char** v)
	: argc(c), argv(v)
{
}

auto Application::exec() -> int
{
	std::cout << "App working.." << std::endl;

	return 0;
}
