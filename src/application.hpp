#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include "ui.hpp"
#include "reader.hpp"
#include <iostream>

class Application
{
public:
	Application(int c, char** v);
	auto exec() -> int;

private:
	int argc;
	char** argv;

	auto checkDate() -> bool;
};


#endif // !APPLICATION_HPP
