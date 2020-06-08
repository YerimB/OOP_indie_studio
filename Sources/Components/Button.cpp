/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Button
*/

#include <Headers/Components/Button.h>

Button::Button(GuiEnvironment *GUIEnv)
{
    this->m_GUIEnvironment = GUIEnv;
}

bool Button::Initialize(void *args)
{
    if (!args)
        return (false);
    this->m_Button = m_GUIEnvironment->addButton({0, 0, 100, 100});
    return (true);
}

void Button::Update(const float &)
{
    if (this->m_Button->isPushButton()) {
        return;
    }
    // ??
}

void Button::SetOnPress(callback_function f)
{
    this->m_OnPressFunction = f;
}

void Button::SetAsPushButton(const bool &val)
{
    if (!this->m_Button)
        return;
    this->m_Button->setIsPushButton(val);
}

void Button::SetTexture(Texture *t)
{
    this->m_Button->setImage(t);
}

void Button::SetPressedTexture(Texture *t)
{
    this->m_Button->setPressedImage(t);
}

void Button::SetText(GuiText *p_Text)
{
    this->m_Text = p_Text;
    this->m_Button->setText(this->m_Text->getText());
    this->m_Button->setOverrideFont(this->m_Text->getActiveFont());
}

const bool Button::IsPushButton(void)
{
    return (this->m_Button->isPushButton());
}

Texture *Button::GetTexture(void)
{
    return (this->m_Texture);
}

GuiText *Button::GetText(void)
{
    return (this->m_Text);
}