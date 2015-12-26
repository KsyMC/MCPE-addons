#pragma once

#include "shared.h"

class Options
{
public:
	class Option
	{
	public:
		enum Type
		{
			TYPE_TOGGLE,
			TYPE_PROGRESS,
			TYPE_TEXT,
			TYPE_STEP
		};

		int type;		// 0
		string desc;	// 4

		~Option();
	};

	string filepath;	// 0

	void set(Option const *, string const &);

	string getStringValue(Option const *);
	bool getBooleanValue(Option const *);
	void toggle(Option const *, int);

	void save();
	void _load();

	string getUsername() const;

	static void _readBool(string const &, bool &);
	static void _readFloat(string const &, float &);
	static void _readInt(string const &, int &);
};
