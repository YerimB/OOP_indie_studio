/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Button
*/

#ifndef BUTTON_H_
#define BUTTON_H_

#include <ECS/Component.h>
#include <Core.hpp>

class Button : public Component
{
    public:
		static constexpr ComponentId Id = "Button"_hash;
        typedef void (*callback_function)(void);
    
    public:
        Button(GuiEnvironment *GUIEnv);
    
    public:
        bool Initialize(void* args = nullptr) override final;
		void Update(const float& deltaTime) override final;
    
    public: // Setters
        void SetOnPress(callback_function func);
        void SetAsPushButton(const bool &);
        void SetTexture(Texture *p_Texture);
        void SetPressedTexture(Texture *p_Texture);
        void SetText(GuiText *p_Text);

    public: // Getters
        const bool IsPushButton(void);
        Texture *GetTexture(void);
        GuiText *GetText(void);

    private:
		GuiEnvironment *m_GUIEnvironment = nullptr;
        GuiButton *m_Button = nullptr;
        Texture *m_Texture = nullptr;
        GuiText *m_Text = nullptr;
        callback_function m_OnPressFunction;
};

#endif /* !BUTTON_H_ */
