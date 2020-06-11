/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** SoundManager
*/

#include <Components/SoundManager.h>
#include <fmodCoreWindows/fmod.hpp>

SoundManager::SoundManager(SceneManager *p_SceneManager)
{
    this->m_SceneManager = p_SceneManager;

    FMOD::System* system = nullptr;

    FMOD::System_Create(&system);
}

bool SoundManager::Initialize(void *args)
{
    if (!args)
        return (false);
    return (true);
}

void SoundManager::Update(const float &dT, GameManager *) {}