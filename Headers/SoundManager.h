/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** SoundManager
*/

#ifndef SOUNDMANAGER_H_
#define SOUNDMANAGER_H_

#include <Core.hpp>
#include <iostream>
#include <unordered_map>

class SoundManager
{
    public:
        SoundManager();
        ~SoundManager() = default;
    
    public:
        FMOD::Sound *LoadSound(const std::string &path);
        const bool AddSound(FMOD::Sound *sound, const std::string &ID);
        FMOD::Sound *GetSound(const std::string &soundID) const;
        void PlaySound(const std::string &soundID) const;
        void Clear(void);
    
    private:
        FMOD::System *m_System = nullptr;
        FMOD_RESULT m_fmodDebug;
        std::unordered_map<std::string, FMOD::Sound *> m_SoundMap;
};

#endif /* !SOUNDMANAGER_H_ */
