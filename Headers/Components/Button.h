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
        enum ButtonID { // Add types here
            QUIT,
            PLAY,
        };
    
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
        void SetButtonID(const ButtonID &id);
        void SetTriggered(const bool &state);

    public: // Getters
        const bool IsPushButton(void);
        const bool &IsTriggered(void) const;
        Texture *GetTexture(void);
        GuiText *GetText(void);
        const ButtonID &GetButtonID(void);

    private:
		GuiEnvironment *m_GUIEnvironment = nullptr;
        GuiButton *m_Button = nullptr;
        Texture *m_Texture = nullptr;
        GuiText *m_Text = nullptr;
        callback_function m_OnPressFunction;
        bool m_triggered = false;
        ButtonID m_TypeID = static_cast<ButtonID>(-1);
};

#endif /* !BUTTON_H_ */
