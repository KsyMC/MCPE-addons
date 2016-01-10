#pragma once

#include <string>

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

		int type;			// 0
		std::string desc;	// 4

		~Option();
	};

	std::string filepath;	// 0

	void set(const Option *, const std::string &);

	std::string getStringValue(const Option *);
	bool getBooleanValue(const Option *);
	void toggle(const Option *, int);

	void save();
	void _load();

	std::string getUsername() const;

	static void _readBool(const std::string &, bool &);
	static void _readFloat(const std::string &, float &);
	static void _readInt(const std::string &, int &);
};
