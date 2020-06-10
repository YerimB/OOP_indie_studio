/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Collider
*/

#include <Components/Collider.h>

Collider::Collider(SceneManager *p_Smgr)
{
    this->m_SceneManager = p_Smgr;
}

bool Collider::Initialize(void *args)
{
    if (!args)
        return (false);
    return (true);
}

void Collider::Update(const float &dTime, GameManager *) {}