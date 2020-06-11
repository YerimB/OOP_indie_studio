/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** SoundManager
*/

#include <SoundManager.h>

SoundManager::SoundManager()
{
    m_fmodDebug = FMOD::System_Create(&(m_System));
    if (m_fmodDebug != FMOD_OK) {
        std::cerr << "FMOD Error : " << m_fmodDebug << std::endl;
        std::exit(84);
    }
    m_fmodDebug = m_System->init(256, FMOD_INIT_NORMAL, 0);
    if (m_fmodDebug != FMOD_OK) {
        std::cerr << "FMOD Error : " << m_fmodDebug << std::endl;
        std::exit(84);
    }
}

FMOD::Sound *SoundManager::LoadSound(const std::string &path)
{
    FMOD::Sound *tmp = nullptr;

    m_fmodDebug = this->m_System->createSound(
        path.c_str(),
        FMOD_DEFAULT,
        0, &tmp
    );
    if (m_fmodDebug != FMOD_OK)
        std::cerr << "FMOD Error Loading sound : " << \
        m_fmodDebug << std::endl;
    return (tmp);
}

const bool SoundManager::AddSound(FMOD::Sound *sound, const std::string &ID)
{
    this->m_SoundMap.emplace(ID, std::move(sound));
}

FMOD::Sound *SoundManager::GetSound(const std::string &soundID) const
{
    if (this->m_SoundMap.find(soundID) == m_SoundMap.end())
        return (nullptr);
    return (m_SoundMap.at(soundID));
}

void SoundManager::PlaySound(const std::string &soundID) const
{
    if (this->m_SoundMap.find(soundID) == m_SoundMap.end())
        return;
    this->m_System->playSound(m_SoundMap.at(soundID), 0, false, 0);
}

void SoundManager::Clear(void)
{
    this->m_SoundMap.clear();
}