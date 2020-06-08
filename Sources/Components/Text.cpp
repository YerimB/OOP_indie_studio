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
}

bool Text::Initialize(void *pText)
{
	if (pText == nullptr)
		return false;
	this->m_Text = *(static_cast<std::string *>(pText));
	return true;
}

void Text::Update(const float&) {}

void Text::SetText(const std::string& text)
{
	m_Text = text;
}

void Text::SetFont(GuiFont* font)
{
	if (!font)
		return;
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

void Text::Add(void) {}