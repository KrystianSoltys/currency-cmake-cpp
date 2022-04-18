#include "reader.hpp"
#include <curl/curl.h>

size_t WriteCallback(char* ptr, size_t size, size_t nmemb, void* userdata)
{
	((std::string*)userdata)->append((char*)ptr, size * nmemb);
	return size * nmemb;
}

std::string GetLink(std::string code, std::string date, std::string target)
{
	std::string toReturn = "http://api.exchangerate.host/";
	
	if (date.empty()) date = "latest";
	toReturn += date;

	if (code.empty()) code = DEFAULT_BASE_CURRENCY_CODE;
	toReturn += "?symbols=" + code;

	toReturn += "&base=" + target;

	toReturn += "&format=xml";

	return toReturn;
}

std::vector<CurrencyConteiner>
GetCurrencies(const std::vector<std::string>& links)
{
	std::vector<CurrencyConteiner> currencyVec;

	std::uint64_t datePos=0, codePos=0, strPricePos=0, targPos=0;
	std::string xmlData, date, code, strPrice, targ;

	for (auto& i : links)
	{
		xmlData = ParseFromWeb(i);

		strPricePos = xmlData.find("<rate>");
		strPrice = xmlData.substr(strPricePos+6, 5);
		
		codePos = xmlData.find("<base>");
		code = xmlData.substr(codePos + 6, 3);

		datePos = xmlData.find("<date>");
		date = xmlData.substr(datePos + 6, 10);

		targPos = xmlData.find("<code>");
		targ = xmlData.substr(targPos + 6, 3);


		currencyVec.push_back((CurrencyConteiner(code, date, strPrice, targ)));
	}

	
	return currencyVec;
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
