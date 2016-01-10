#pragma once

#include <string>

// Size : 16
class Token
{
public:
	enum Type
	{

	};

public:
	char filler1[4];			// 0
	int value;					// 4
	Token::Type _type;			// 8
	std::string stringValue;	// 12

public:
	Token(const std::string &);
	bool compatibleWith(Token::Type) const;
	bool getBool(bool) const;
	const std::string &getText(const std::string &) const;
	int getValue(int) const;
	void _parseRandom();
	static Token tokenize(const std::string &);
};
