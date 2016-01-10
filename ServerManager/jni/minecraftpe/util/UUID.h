#pragma once

#include <string>

namespace mce
{
	class UUID
	{
	public:
		int part[4];

		void fromString(const std::string &);
		std::string toString() const;
	};
};
