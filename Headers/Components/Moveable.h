/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Moveable
*/

#ifndef MOVEABLE_H_
#define MOVEABLE_H_

#include <ECS/Component.h>
#include <Core.hpp>

class Moveable : public Component
{
    public:
		static constexpr ComponentId Id = "Moveable"_hash;
    
    public:
        Moveable(SceneManager *p_SceneManager);
    
    public:
        bool Initialize(void* args = nullptr) override final;
		void Update(const float& deltaTime) override final;
    
    public: // Setters

    public: // Getters

    private:
		SceneManager *m_SceneManager = nullptr;
        Vector3i m_nextPosition;
};

#endif /* !MOVEABLE_H_ */
