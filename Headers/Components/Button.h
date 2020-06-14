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

class GameManager;

class Button : public Component
{
    public:
		static constexpr ComponentId Id = "Button"_hash;
        typedef void (*callback_function)(GameManager *);
        enum ButtonID { // Add types here
            UNDEFINED = (-1),
            QUIT,
            PLAY,
            CHANGEPLAYER1,
            CHANGEPLAYER2,
            CHANGEPLAYER3,
            CHANGEPLAYER4,
            BUTTON_CHANGE_1,
            BUTTON_CHANGE_2,
            BUTTON_CHANGE_3,
            BUTTON_CHANGE_4,
            LOWERMUSIC,
            UPPERMUSIC,
            LOWERFX,
            UPPERFX,
        };
    
    public:
        Button(GuiEnvironment *GUIEnv);
    
    public:
        bool Initialize(void* args = nullptr) override final;
		void Update(const float& deltaTime, GameManager* gameManager) override final;
    
    public: // Setters
        void SetOnPress(callback_function f);
        void SetAsPushButton(const bool &);
        void SetTexture(Texture *p_Texture);
        void SetPressedTexture(Texture *p_Texture);
        void SetTextureToFit(const bool &state);
        void SetText(const std::string &str);
        void SetFont(GuiFont *font);
        void SetButtonID(const ButtonID &id);
        void SetTriggered(const bool &state);
        void SetPosition(const Vector2i &newPosition);
        void SetSize(const irr::s32 &len, const irr::s32 &hei);

    public: // Getters
        const bool IsPushButton(void);
        const bool &IsTriggered(void) const;
        Texture *GetTexture(void);
        const wchar_t *GetText(void);
        const ButtonID &GetButtonID(void);
        const Vector2i GetPosition(void);

    private:
		GuiEnvironment *m_GUIEnvironment = nullptr;
        GuiButton *m_Button = nullptr;
        Texture *m_Texture = nullptr;
        callback_function m_OnPressFunction;
        bool m_triggered = false;
        ButtonID m_TypeID = UNDEFINED;
};

#endif /* !BUTTON_H_ */
