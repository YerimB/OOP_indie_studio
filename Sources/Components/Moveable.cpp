/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Moveable
*/

#include <Components/Moveable.h>

Moveable::Moveable(SceneManager *p_Smgr)
{
    this->m_SceneManager = p_Smgr;
}

bool Moveable::Initialize(void *args)
{
    if (!args)
        return (false);
    return (true);
}

void Moveable::Update(const float &dT) {}