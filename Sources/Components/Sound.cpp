/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Sound
*/

#include <Components/Sound.h>

Sound::Sound(SceneManager *p_SceneManager)
{
    this->m_SceneManager = p_SceneManager;

    FMOD::System* system = nullptr;

    FMOD::System_Create(&system);
}

bool Sound::Initialize(void *args)
{
    if (!args)
        return (false);
    return (true);
}

void Sound::Update(const float &dT, GameManager *) {}