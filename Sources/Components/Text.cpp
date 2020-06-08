/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Text
*/

#include <Components/Text.h>
#include <iostream>

Text::Text(GuiEnvironment *GUIEnv)
{
	this->m_GUIEnvironment = GUIEnv;
	this->m_content = "Use SetText to modify content";
}

bool Text::Initialize(void *pText)
{
	if (pText != nullptr)
		this->m_content = *(static_cast<std::string *>(pText));
	this->m_Text = this->m_GUIEnvironment->addStaticText(
		(wchar_t *)m_content.data(),
		{0, 0, 100, 20}, true
	);
	this->m_Text->setNotClipped(false);
	return true;
}

void Text::Update(const float&) {}

void Text::SetText(const std::string& text)
{
	this->m_content = text;

	this->m_Text->setText((wchar_t *)m_content.data());
}

void Text::SetFont(GuiFont* font)
{
	if (!font)
		return;
	m_Font = font;
	this->m_Text->setOverrideFont(this->m_Font);
}

void Text::SetPosition(const Vector2i &v)
{
	this->m_Text->setRelativePosition(v);
}

void Text::SetColor(const Color &newColor)
{
	this->m_Text->setOverrideColor(newColor);
}

const std::string &Text::GetContent() const
{
	return m_content;
}

const GuiFont* Text::GetFont() const
{
	return m_Font;
}

const GuiText* Text::GetText() const
{
	return m_Text;
}