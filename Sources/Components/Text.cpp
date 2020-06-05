#include <Components/Text.h>

Text::Text()
{
	m_Text = "";
	m_Font = nullptr;
}

#include <iostream>

bool Text::Initialize(void *pText)
{
	if (pText == nullptr)
		return false;
	auto str = *(static_cast<std::string *>(pText));

	this->m_Text = str;
	return true;
}

void Text::Update(const float&)
{
}

void Text::SetText(const std::string& text)
{
	m_Text = text;
}

void Text::SetFont(GuiFont* font)
{
	m_Font = font;
}

const std::string& Text::GetText() const
{
	return m_Text;
}

const GuiFont* Text::GetFont() const
{
	return m_Font;
}

