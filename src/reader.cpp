#include "reader.hpp"
#include <curl/curl.h>

size_t WriteCallback(char* contents, size_t size, size_t nmemb, void* userp)
{
	((std::string*)userp)->append((char*)contents, size * nmemb);
	return size * nmemb;
}

std::string GetLink(std::string code, Date date)
{
	std::string dt;
	if (!date.day.empty() && !date.month.empty() && !date.year.empty())
		dt = date.year + "-" + date.month + "-" + date.day + "/";

	return "http://api.nbp.pl/api/exchangerates/rates/A/" + code + "/" + dt + "?format=xml";
}

std::unordered_map<std::string, CurrencyConteiner>
GetCurrencies(const std::vector<std::string>& links)
{
	std::unordered_map<std::string, CurrencyConteiner> currencyMap;

	std::uint32_t datePos=0, codePos=0, strPricePos=0;
	std::string xmlData, date, code, strPrice;

	for (auto& i : links)
	{
		xmlData = ParseFromWeb(i);

		strPricePos = xmlData.find("<Mid>");
		strPrice = xmlData.substr(strPricePos+5, 6);
		
		codePos = xmlData.find("<Code>");
		code = xmlData.substr(codePos + 6, 3);

		datePos = xmlData.find("<EffectiveDate>");
		date = xmlData.substr(datePos + 15, 10);

		currencyMap.insert(std::pair <std::string, CurrencyConteiner>(code, CurrencyConteiner(date, strPrice)));
	}


	return currencyMap;
}

std::string ParseFromWeb(const std::string& link)
{
	curl_global_init(CURL_GLOBAL_ALL);

	std::string result;
	CURL* curl = curl_easy_init();

	curl_easy_setopt(curl, CURLOPT_URL, link.c_str());
	curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
	curl_easy_setopt(curl, CURLOPT_WRITEDATA, &result);

	curl_easy_perform(curl);

	curl_easy_cleanup(curl);

	return result;
}
