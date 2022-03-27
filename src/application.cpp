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
			cout << ui.Headline() << "\n";
			cout << convert() << "\n";
			break;
		}
		case ParsingStatus::Help:
		{
			cout << ui.Help() << "\n";
			break;
		}
		case ParsingStatus::About:
		{
			cout << ui.About() << "\n";
			break;
		}
		case ParsingStatus::WrongVal:
		{
			cout << ui.WrongVal(parsePair.second) << "\n";
			break;
		}
		case ParsingStatus::MissingVal:
		{
			cout << ui.MissingVal(parsePair.second) << "\n";
			break;
		}
		case ParsingStatus::NoTargetCurrencies:
		{
			cout << ui.NoTargetCurrencies() << "\n";
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
		else if (!strcmp(argv[i], "--about"))
		{
			return parsingPair(ParsingStatus::About, "");
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
		else if (!strcmp(argv[i], "-t"))
		{
			while (++i < argc && argv[i][0] != '-')
			{
				args.targets.push_back(argv[i]);
			}
			if (i < argc) --i;
		}
		else
		{
			return parsingPair(ParsingStatus::UnknownArg, argv[i]);
		}
	}

	//date check
	if (!args.date.empty())
	{
		if (args.date.size() != 10 ||
			args.date[4] != '-' ||
			args.date[7] != '-')
			return parsingPair(ParsingStatus::WrongVal, args.date);
	}
	

	//base check
	if (!args.base.empty())
	{
		if (args.base.size() != 3) return parsingPair(ParsingStatus::WrongVal, args.base);
	}
	
	//dest check
	if (args.targets.empty()) return parsingPair(ParsingStatus::NoTargetCurrencies, "");
	else
	{
		for (auto i : args.targets)
		{
			if (i.size() != 3) return parsingPair(ParsingStatus::WrongVal, i);;
		}
	}
	
	

	return parsingPair(ParsingStatus::OK, "");
}
auto Application::convert() const -> std::string
{
	std::vector<std::string> links;

	for (auto& i : args.targets)
	{
		links.push_back(GetLink(args.base, args.date, i));
	}

	auto resultVec = GetCurrencies(links);

	std::string toReturn;

	for (auto& i : resultVec)
	{
		toReturn += "1 " + i.base + " = " + i.price + " " + i.targ + "\t(" + i.date + ")\n";
	}

	return toReturn;
}