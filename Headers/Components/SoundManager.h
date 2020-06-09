/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** SoundManager
*/

#ifndef SOUNDMANAGER_H_
#define SOUNDMANAGER_H_

#include <ECS/Component.h>
#include <Core.hpp>

class SoundManager : public Component
{
    public:
		static constexpr ComponentId Id = "SoundManager"_hash;

    public:
        SoundManager(SceneManager *p_SceneManager);

    public:
        bool Initialize(void* args = nullptr) override final;
		void Update(const float& deltaTime) override final;

    public: // Setters

    public: // Getters

    private:
		SceneManager *m_SceneManager = nullptr;
};

#endif /* !SOUNDMANAGER_H_ */
