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
		return "--------------- Konwerter Walut " + INFO::VERSION + " ---------------\n";

	
	return ("--------------- Currency Converter " + INFO::VERSION + " ---------------\n");
}

auto UI::About() const noexcept -> std::string
{
	if (lang == Language::Polish)
		return ("Przelicznik walut wykonany, przy uzyciu API exchangerate.host\n"
				"Projekt zrealizowany w celu nauki jezyka C++ i systemu CMake, autor: Krystian Soltys(2022)\n"
				"github.com/KrystianSoltys\n");


	return ("Currency costs converter, made using exchangerate.host API\n"
			"C++ and CMake learning project made by Krystian Soltys(2022)\n"
			"github.com/KrystianSoltys\n");
}

auto UI::Help() const noexcept -> std::string
{
	if (lang == Language::Polish)
		return ("Przelicznik walut wykonany, przy uzyciu API exchangerate.host\n"
				"Dostepne argumenty:\n"
				"-t -> waluty docelowe, np. [-t USD EUR CHF] (WYMAGANE)\n"
				"-b -> waluta podstawowa (domyslnie PLN), np. [-b PLN]\n"
				"-d -> data cen walut (domyslnie dzis), np. [-d RRRR-MM-DD]\n"
				"--help -> ta wiadomosc\n"
				"--about -> informcaje i autor\n\n"
				"Przyklad uzycia:\n"
				"currency -t USD CAD CZK -b EUR -d 2022-03-01\n");


	return ("Currency costs converter, made using exchangerate.host API\n"
			"Avaible arguments:\n"
			"-t -> target currencies, ex. [-t USD EUR CHF] (REQUIRED)\n"
			"-b -> base currency (default PLN), ex. [-b PLN]\n"
			"-d -> date of currency prices (defalut today), ex. [-d YYYY-MM-DD]\n"
			"--help -> this message\n"
			"--about -> credits\n\n"
			"Example of use:\n"
			"currency -t USD CAD CZK -b EUR -d 2022-03-01\n");
}

auto UI::MissingVal(std::string arg) const noexcept -> std::string
{
	if (lang == Language::Polish)
		return ("Brakujaca wartosc argumentu: \"" + arg + "\"\n");


	return ("Missing argument value: \"" + arg + "\"\n");
}

auto UI::WrongVal(std::string val) const noexcept -> std::string
{
	if (lang == Language::Polish)
		return ("Nieprawidlowa wartosc argumentu: \"" + val + "\"\n");


	return ("Incorrect argument value: \"" + val + "\"\n");
}

auto UI::NoTargetCurrencies() const noexcept -> std::string
{
	if (lang == Language::Polish)
		return ("Nie podano walut docelowych (uzyj argumentu --help).\n");

	return ("No target currencies provided (use --help argument for more inforamtion).\n");
}


auto UI::UnknownArg(std::string arg) const noexcept -> std::string
{
	if (lang == Language::Polish)
		return ("Nieznany argument: \"" + arg + "\"\n");

	return ("Unknown argument: \"" + arg + "\"\n");
}

auto UI::UnknownError() const noexcept -> std::string
{
	if (lang == Language::Polish)
		return ("Wystapil nieznany blad!\n");

	return ("Unknown error occured!\n");
}
