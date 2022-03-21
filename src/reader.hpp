#ifndef READER_HPP
#define READER_HPP

#include <unordered_map>
#include <string>

struct CurrencyConteiner
{
	CurrencyConteiner(std::string _name, std::string _price)
		: name(_name), price(_price) {}
	std::string name;
	std::string price;
};

struct Date
{
	using uint = std::uint8_t;
	
	Date(std::string d, std::string m, std::string y)
		: day(d), month(m), year(y) {}

	std::string day;
	std::string month;
	std::string year;
};

std::string
GetLink(std::string code, Date date = Date("", "", ""));

std::unordered_map<std::string, CurrencyConteiner>			//<currency code, other info> --> ex. <"USD", {"US Dollar", 4.24}>
GetCurrencies(const std::vector<std::string>& links);

std::string
ParseFromWeb(const std::string& link);

#endif // !READER_HPP
