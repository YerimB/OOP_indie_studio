/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Collision
*/

#include <Components/Collision.h>

Collision::Collision(SceneManager *p_Smgr)
{
    this->m_SceneManager = p_Smgr;
}

bool Collision::Initialize(void *args)
{
    if (!args)
        return (false);
    return (true);
}

void Collision::Update(const float &dTime, GameManager *) {}