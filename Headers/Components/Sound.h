/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Sound
*/

#ifndef SOUND_H_
#define SOUND_H_

#include <ECS/Component.h>
#include <Core.hpp>
#include <GameManager.h>

class Sound : public Component
{
    public:
		static constexpr ComponentId Id = "Sound"_hash;

    public:
        Sound(SceneManager *p_SceneManager);

    public:
        bool Initialize(void* args = nullptr) override final;
		void Update(const float& deltaTime, GameManager* gameManager) override final;

    public: // Setters

    public: // Getters

    private:
		SceneManager *m_SceneManager = nullptr;
};

#endif /* !SOUND_H_ */
