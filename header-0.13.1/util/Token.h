#pragma once

#include "shared.h"

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
	string stringValue;			// 12

public:
	Token(string const &);
	bool compatibleWith(Token::Type) const;
	bool getBool(bool) const;
	const string &getText(string const &) const;
	int getValue(int) const;
	void _parseRandom();
	static Token tokenize(string const &);
};
