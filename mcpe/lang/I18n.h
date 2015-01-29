#ifndef __I18L_H__
#define __I18L_H__

class I18n {
public:
	static std::string get(const std::string &);
	static std::string get(const std::string &, std::string &);
};

#endif
