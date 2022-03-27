#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include "ui.hpp"
#include "reader.hpp"
#include <iostream>
#include <algorithm>

class Application
{
public:
	Application(int c, char** v);
	auto exec() -> int;

	struct Args
	{
		std::string base;
		std::string date;
		std::vector<std::string> targets;
	};
	enum class ParsingStatus { OK, Help, About, WrongVal, MissingVal, NoTargetCurrencies, UnknownArg };

private:
	int argc;
	char** argv;

	Args args;

	auto parseArgv() -> std::pair<ParsingStatus, std::string>;
	auto convert() const-> std::string;
	
	//auto checkDate() -> bool;
};


#endif // !APPLICATION_HPP
