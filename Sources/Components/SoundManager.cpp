/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** SoundManager
*/

#include <Components/SoundManager.h>

SoundManager::SoundManager(SceneManager *p_SceneManager)
{
    this->m_SceneManager = p_SceneManager;
}

bool SoundManager::Initialize(void *args)
{
    if (!args)
        return (false);
    return (true);
}

void SoundManager::Update(const float &dT, GameManager *) {}