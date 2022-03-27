#ifndef UI_HPP
#define UI_HPP

#include <cstdint>
#include <string>
#include <locale>
#include <cstdlib>

namespace INFO
{
	static std::string VERSION = "v1.1"; //static is temp fix
}



class UI
{
public:
	UI();

	auto Headline() const noexcept							-> std::string;
	auto About() const noexcept								-> std::string;
	auto Help() const noexcept								-> std::string;
	auto MissingVal(std::string arg="") const noexcept		-> std::string;
	auto WrongVal(std::string val="") const noexcept		-> std::string;
	auto NoTargetCurrencies() const noexcept				-> std::string;
	auto UnknownArg(std::string arg="") const noexcept		-> std::string;
	auto UnknownError() const noexcept						-> std::string;

	enum class Language { Polish, English };
private:

	auto setLang() -> void;

	Language lang;

};


#endif //UI_HPP
