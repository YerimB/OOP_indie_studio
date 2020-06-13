/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Collider
*/

#ifndef COLLIDER_H_
#define COLLIDER_H_

#include <ECS/Component.h>
#include <Core.hpp>
#include <GameManager.h>

class Collider : public Component
{
    public:
		static constexpr ComponentId Id = "Collider"_hash;
    
    public:
        Collider() = default;
    
    public:
        bool Initialize(void* args = nullptr) override final;
		void Update(const float& deltaTime, GameManager* gameManager) override final;
    
    public: // Setters

    public: // Getters

    private:
		SceneManager *m_SceneManager = nullptr;
};

#endif /* !COLLIDER_H_ */