/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Image
*/

#include <Components/Image.h>

Image::Image(irr::gui::IGUIEnvironment *GUIEnv)
{
    this->m_GUIEnvironment = GUIEnv;
    this->m_Image = nullptr;
}

bool Image::Initialize(void *args)
{
    irr::video::ITexture *texture = nullptr;

    if (!args)
        return false;
    texture = static_cast<irr::video::ITexture *>(args);
    this->m_Image = m_GUIEnvironment->addImage(texture, {0, 0});
    if (!this->m_Image)
        return (false);
    return (true);
}

void Image::Update(const float &) {}

irr::gui::IGUIImage *Image::GetImage()
{
    return (this->m_Image);
}