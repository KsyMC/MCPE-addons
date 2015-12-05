#include "TextContainer.h"
#include "minecraftpe/I18n.h"

TextContainer::TextContainer(std::string const &text, bool needTranslation)
{
	this->needTranslation = needTranslation;

	this->text = text;
}

TextContainer::TextContainer(std::string const &text, std::vector<std::string> const &params)
{
	needTranslation = true;

	this->text = text;
	this->params = params;
}

void TextContainer::setText(std::string const &text)
{
	this->text = text;
}

std::string TextContainer::getText() const
{
	return text;
}

bool TextContainer::isNeedTranslation() const
{
	return needTranslation;
}

std::vector<std::string> TextContainer::getParameters() const
{
	return params;
}

std::string TextContainer::getParameter(int index) const
{
	if(index >= params.size())
		return "";

	return params[index];
}

void TextContainer::setParameters(std::vector<std::string> params)
{
	this->params = params;
}

void TextContainer::setParameter(int index, std::string const &str)
{
	params[index] = str;
}

TextContainer &TextContainer::operator =(TextContainer const &other)
{
	text = other.getText();
	params = other.getParameters();

	return *this;
}
