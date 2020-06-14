/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** SoundManager
*/

#include <SoundManager.h>

SoundManager::SoundManager()
{
    FMOD::SoundGroup *musicSG = nullptr;
    FMOD::SoundGroup *sfxSG = nullptr;

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
    m_System->createSoundGroup("SFX", &sfxSG);
    m_SoundGroupMap.emplace(SoundType::SFX, std::move(sfxSG));
    m_System->createSoundGroup("Music", &musicSG);
    m_SoundGroupMap.emplace(SoundType::MUSIC, std::move(musicSG));
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

const bool SoundManager::AddSound(FMOD::Sound *sound, const std::string &ID, const SoundType &type)
{
    sound->setSoundGroup(m_SoundGroupMap.at(type));
    this->m_SoundMap.emplace(ID, std::move(sound));

    return true;
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
    for (auto &elem : m_SoundMap)
        elem.second->release();
    this->m_SoundMap.clear();
}

void SoundManager::setVolume(const SoundType &type, float volume)
{
    this->m_SoundGroupMap.at(type)->setVolume(volume);
}

float SoundManager::getVolume(const SoundType &type)
{
    float volume;
    this->m_SoundGroupMap.at(type)->getVolume(&volume);
    return (volume);
}

void SoundManager::setLoop(const std::string &soundID, int loopcount) const
{
    if (this->m_SoundMap.find(soundID) == m_SoundMap.end())
        std::cerr << "FMOD Error setting loop to sound : " << \
        m_fmodDebug << std::endl;
    this->m_SoundMap.at(soundID)->setMode(FMOD_LOOP_NORMAL);
    this->m_SoundMap.at(soundID)->setLoopCount(loopcount);
}

SoundManager::~SoundManager()
{
    for (auto &elem : m_SoundGroupMap)
        elem.second->release();
    for (auto &elem : m_SoundMap)
        elem.second->release();
}