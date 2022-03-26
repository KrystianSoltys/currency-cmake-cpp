#ifndef READER_HPP
#define READER_HPP

#include <unordered_map>
#include <string>


struct CurrencyConteiner
{
	CurrencyConteiner(std::string _base, std::string _date, std::string _price)
		: base(_base), date(_date), price(_price) {}

	std::string base;
	std::string date;
	std::string price;
};

struct Date
{	
	Date(std::string d, std::string m, std::string y)
		: day(d), month(m), year(y) {}

	std::string day;
	std::string month;
	std::string year;
};

std::string
GetLink(std::string code, Date date = Date("", "", ""));

std::vector<CurrencyConteiner>
GetCurrencies(const std::vector<std::string>& links);



std::string
ParseFromWeb(const std::string& link);

#endif // !READER_HPP
