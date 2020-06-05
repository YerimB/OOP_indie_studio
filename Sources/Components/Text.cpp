#include <Components/Text.h>

Text::Text()
{
	m_Text = "";
	m_Font = nullptr;
}

bool Text::Initialize(void* pText)
{
	if (pText == nullptr)
		return false;

	auto pStr = static_cast<std::string*>(pText);
	std::string str = *pStr;

	m_Text = std::string(str);
	
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

