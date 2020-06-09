/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Collision
*/

#ifndef COLLISION_H_
#define COLLISION_H_

#include <ECS/Component.h>
#include <Core.hpp>
#include <GameManager.h>

class Collision : public Component
{
    public:
		static constexpr ComponentId Id = "Collision"_hash;
    
    public:
        Collision(SceneManager *p_SceneManager);
    
    public:
        bool Initialize(void* args = nullptr) override final;
		void Update(const float& deltaTime, GameManager* gameManager) override final;
    
    public: // Setters

    public: // Getters

    private:
		SceneManager *m_SceneManager = nullptr;
};

#endif /* !COLLISION_H_ */