/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Image
*/

#ifndef IMAGE_H_
#define IMAGE_H_

#include <ECS/Component.h>
#include <Core.hpp>
#include <GameManager.h>

class Image : public Component
{
    public:
		static constexpr ComponentId Id = "Image"_hash;
    
    public:
        Image(GuiEnvironment *GUIEnv);
    
    public:
        bool Initialize(void *args) override final;
        void Update(const float &deltaTime, GameManager *gameManager) override final;

    public:
        void SetTexture(Texture *texture);
        void SetColor(const Color &color = {255, 255, 255, 255});

    public:
        GuiImage *GetImage(void);
        Texture *GetTexture(void);
        const Color &GetColor(void);
    
    private:
        GuiEnvironment *m_GUIEnvironment;
        GuiImage *m_Image = nullptr;
        Texture *m_Texture = nullptr;
        Color m_clr;
};

#endif /* !IMAGE_H_ */
