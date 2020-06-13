/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Button
*/

#include <Components/Button.h>
#include <iostream>

Button::Button(GuiEnvironment *GUIEnv)
{
    this->m_GUIEnvironment = GUIEnv;
}

bool Button::Initialize(void *args)
{
    this->m_Button = m_GUIEnvironment->addButton({0, 0, 100, 100});
    if (this->m_Button == nullptr) {
        return (false);
    } else if (args)
        this->SetButtonID(*static_cast<ButtonID *>(args));
    m_Button->setUseAlphaChannel(true);
    m_Button->setDrawBorder(false);
    return (true);
}

void Button::Update(const float& deltaTime, GameManager* gameManager)
{
    this->SetTriggered(false);
    // Use of callback function.
    if (this->m_OnPressFunction)
        this->m_OnPressFunction(gameManager);
}

// Setters

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

void Button::SetTextureToFit(const bool &state)
{
    this->m_Button->setScaleImage(state);
}

void Button::SetText(const std::string &str)
{
    std::wstring wStr(str.begin(), str.end());

    this->m_Button->setText(wStr.c_str());
}

void Button::SetFont(GuiFont *font)
{
    this->m_Button->setOverrideFont(font);
}

void Button::SetButtonID(const ButtonID &id)
{
    this->m_TypeID = id;
    this->m_Button->setID((irr::s32)id);
}

void Button::SetTriggered(const bool &state)
{
    this->m_triggered = state;
}

void Button::SetPosition(const Vector2i &np)
{
    this->m_Button->setRelativePosition(np);
}

void Button::SetSize(const irr::s32 &len, const irr::s32 &hei)
{
    Recti dims = {
        this->m_Button->getRelativePosition().UpperLeftCorner.X,
        this->m_Button->getRelativePosition().UpperLeftCorner.Y,
        this->m_Button->getRelativePosition().UpperLeftCorner.X + len,
        this->m_Button->getRelativePosition().UpperLeftCorner.Y + hei
    };
    this->m_Button->setRelativePosition(dims);
}

// Getters

const bool Button::IsPushButton(void)
{
    return (this->m_Button->isPushButton());
}

const bool &Button::IsTriggered(void) const
{
    return (this->m_triggered);
}

Texture *Button::GetTexture(void)
{
    return (this->m_Texture);
}

const wchar_t *Button::GetText(void)
{
    return (this->m_Button->getText());
}

const Button::ButtonID &Button::GetButtonID(void)
{
    return (this->m_TypeID);
}

const Vector2i Button::GetPosition(void)
{
    return (this->m_Button->getAbsolutePosition().UpperLeftCorner);
}