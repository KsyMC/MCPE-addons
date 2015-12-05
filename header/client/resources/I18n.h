#pragma once

#include <string>
#include <vector>

class Localization;

class I18n
{
public:
	static void mCurrentLanguage;
	static void mFormatDictionary;
	static void mLanguages;

public:
	static void _addFormatToDictionary(std::string const &, std::vector<std::string> const &);
	static void _getFormatParmas(std::string const &, std::vector<std::string>  &);
	static void _getKeyExists(std::string const &);
	static void _initFormatDictionary();
	static void chooseLanguage(Localization const &);
	static void chooseLanguage(std::string const &);
	static void get(std::string const &);
	static void get(std::string const &, std::vector<std::string> const &);
	static void getCurrentLanguage();
	static void getLocaleFor(std::string const &);
	static void getSupportedLocales();
	static void loadLanguages();
};
