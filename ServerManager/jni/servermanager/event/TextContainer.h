#pragma once

#include <string>
#include <vector>

class TextContainer
{
protected:
	bool needTranslation;

	std::string text;
	std::vector<std::string> params;

public:
	TextContainer(std::string const &text, bool needTranslation = false);
	TextContainer(std::string const &text, std::vector<std::string> const &params);

	void setText(std::string const &text);
	std::string getText() const;

	bool isNeedTranslation() const;

	std::vector<std::string> getParameters() const;
	std::string getParameter(int index) const;

	void setParameters(std::vector<std::string> params);
	void setParameter(int index, std::string const &str);

	TextContainer &operator =(TextContainer const &other);
};
