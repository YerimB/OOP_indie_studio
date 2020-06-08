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
#include <Irrlicht/irrlicht.h>

class Image : public Component
{
    public:
		static constexpr ComponentId Id = "Image"_hash;
    
    public:
        Image(GuiEnvironment *GUIEnv);
    
    public:
        bool Initialize(void *args) override final;
        void Update(const float &deltaTime) override final;
    
    public:
        GuiImage *GetImage();
    
    private:
        GuiEnvironment *m_GUIEnvironment;
        GuiImage *m_Image;
};

#endif /* !IMAGE_H_ */
