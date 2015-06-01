#pragma once

#include <string>
#include <vector>

class Localization;

class I18n
{
public:
	static void *currentLanguage;
	static void *languages;

public:
	static void chooseLanguage(const Localization &);
	static void chooseLanguage(const std::string &);
	static void get(const std::string &, const std::vector<std::string> &);
	static void *getCurrentLanguage();
	static void getLocaleFor(const std::string &);
	static void loadLanguages();
};
