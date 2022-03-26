#include "ui.hpp"

UI::UI()
{
	setLang();
}

auto UI::setLang() -> void
{
	setlocale(LC_ALL, "");

	std::string localeStr(setlocale(LC_ALL, NULL));

	auto _place = localeStr.find('_');

	std::string langStr = localeStr.substr(0, _place);

	if (langStr == "Polish") lang = UI::Language::Polish;
	else lang = UI::Language::English;
}

auto UI::Headline() const noexcept -> std::string
{
	if (lang == Language::Polish)
		return "---------------Konwerter Walut " + INFO::VERSION + "---------------\n";

	
	return ("---------------Currency Converter " + INFO::VERSION + "---------------\n");
}

auto UI::About() const noexcept -> std::string
{
	if (lang == Language::Polish)
		return ("Przelicznik walut na PLN, przy uzyciu API Narodowego Banku Polskiego\n"
				"Projekt zrealizowany w celu nauki jezyka C++ i systemu CMake, autor: Krystian Soltys(2022)\n"
				"github.com/KrystianSoltys\n");


	return ("Currency costs to PLN getter via NPB (The National Bank of Poland) API\n"
			"C++ and CMake learning project made by Krystian Soltys(2022)\n"
			"github.com/KrystianSoltys\n");
}

auto UI::Help() const noexcept -> std::string
{
	if (lang == Language::Polish)
		return ("Przelicznik walut na PLN, przy uzyciu API Narodowego Banku Polskiego\n"
				"Dostepne argumenty:\n"
				"-c -> waluty docelowe, np. [-c USD EUR CHF]\n"
				"-b -> waluta podstawowa (domyslnie PLN), np. [-b PLN]\n"
				"-d -> data cen walut (domyslnie dzis), np. [-d 26-03-2022]\n\n"
				"Przyklad uzycia:\n"
				"currency -c USD CAD CZK -b EUR -d 01-03-2022\n");


	return ("Currency costs to PLN getter via NPB (The National Bank of Poland) API\n"
			"Avaible arguments:\n"
			"-c -> target currencies, ex. [-c USD EUR CHF]\n"
			"-b -> base currency (default PLN), ex. [-b PLN]\n"
			"-d -> date of currency prices (defalut today), ex. [-d 26-03-2022]\n\n"
			"Example of use:\n"
			"currency -c USD CAD CZK -b EUR -d 01-03-2022\n");
}

auto UI::MissingVal(std::string arg) const noexcept -> std::string
{
	if (lang == Language::Polish)
		return ("Brakujaca wartosc argumentu: \"" + arg + "\"\n");


	return ("Missing argument value: \"" + arg + "\"\n");
}


auto UI::UnknownArg(std::string arg) const noexcept -> std::string
{
	if (lang == Language::Polish)
		return ("Nieznany argument: " + arg + "\n");

	return ("Unknown argument: " + arg + "\n");
}

auto UI::UnknownError() const noexcept -> std::string
{
	if (lang == Language::Polish)
		return ("Wystapil nieznany blad!\n");

	return ("Unknown error occured!\n");
}
