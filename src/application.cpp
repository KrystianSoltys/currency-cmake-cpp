#include "application.hpp"

Application::Application(int c, char** v)
	: argc(c), argv(v)
{
}

auto Application::exec() -> int
{
	using std::cout; using std::endl;

	UI ui;
	cout << "\n";
	if (argc < 2)
	{
		cout <<  ui.About() << "\n";
		return EXIT_SUCCESS;
	}
	
	auto parsePair = parseArgv();


	switch (parsePair.first)
	{
		case ParsingStatus::OK:
		{
			cout << ui.About() << "\n"; //todo
			break;
		}
		case ParsingStatus::Help:
		{
			cout << ui.Help() << "\n";
			break;
		}
		case ParsingStatus::MissingVal:
		{
			cout << ui.MissingVal(parsePair.second) << "\n";
			break;
		}
		case ParsingStatus::WrongArg:
		{
			//todo
			cout << "Wrong arg provided.\n\n";
			break;
		}
		case ParsingStatus::UnknownArg:
		{
			cout << ui.UnknownArg(parsePair.second) << "\n";
			break;
		}

		default:
		{
			cout << ui.UnknownError() << "\n";
			return EXIT_FAILURE;
		}
	}

	return EXIT_SUCCESS;
}




auto Application::parseArgv() -> std::pair<ParsingStatus, std::string>
{
	using parsingPair =  std::pair<ParsingStatus, std::string>;

	for (int i = 1; i < argc; i++)
	{
		if (!strcmp(argv[i], "--help")) //strcmp returns 0 on success
		{
			return parsingPair(ParsingStatus::Help, "");
		}
		else if (!strcmp(argv[i], "-d"))
		{
			if (i + 1 >= argc)return parsingPair(ParsingStatus::MissingVal, "-d");
			args.date = argv[++i];
		}
		else if (!strcmp(argv[i], "-b"))
		{
			if (i + 1 >= argc)return parsingPair(ParsingStatus::MissingVal, "-b");
			args.base = argv[++i];
		}
		else if (!strcmp(argv[i], "-c"))
		{
			while (++i < argc && argv[i][0] != '-')
			{
				args.dest.push_back(argv[i]);
			}
			if (i < argc) --i;
		}
		else
		{
			return parsingPair(ParsingStatus::UnknownArg, argv[i]);
		}
	}

	return parsingPair(ParsingStatus::OK, "");
}
//
//auto Application::checkDate() -> bool
//{
//	std::string lastArg =argv[argc-1];
//
//	if (lastArg.size() == 10 &&
//		lastArg[2] == '-' &&
//		lastArg[5] == '-')
//		return true;
//
//
//	return false;
//}
