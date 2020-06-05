#include <Components/Text.h>

Text::Text(const std::string& text)
{
	m_Text = text;
}

bool Text::Initialize(void*)
{
	return true;
}

void Text::Update(const float&)
{
}

void Text::SetText(const std::string& text)
{
	m_Text = text;
}

const std::string Text::GetText() const
{
	return m_Text;
}

