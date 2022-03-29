#ifndef READER_HPP
#define READER_HPP

#include <unordered_map>
#include <string>
#include <vector>

const std::string DEFAULT_BASE_CURRENCY_CODE = "PLN";

struct CurrencyConteiner
{
	CurrencyConteiner(std::string _base, std::string _date, std::string _price, std::string _targ)
		: base(_base), date(_date), price(_price), targ(_targ) {}

	std::string base;
	std::string date;
	std::string price;
	std::string targ;
};


std::string
GetLink(std::string code, std::string date, std::string target);

std::vector<CurrencyConteiner>
GetCurrencies(const std::vector<std::string>& links);



std::string
ParseFromWeb(const std::string& link);

#endif // !READER_HPP
