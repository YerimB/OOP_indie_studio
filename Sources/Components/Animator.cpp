/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Animator
*/

#include <Components/Animator.h>

Animator::Animator(SceneManager *p_Smgr)
{
    this->m_SceneManager = p_Smgr;
}

bool Animator::Initialize(void *args)
{
    if (!args)
        return (false);
    return (true);
}

void Animator::Update(const float &dT) {}