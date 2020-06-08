/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Animator
*/

#ifndef ANIMATOR_H_
#define ANIMATOR_H_

#include <ECS/Component.h>
#include <Core.hpp>

class Animator : public Component
{
    public:
		static constexpr ComponentId Id = "Animator"_hash;
    
    public:
        Animator(SceneManager *p_SceneManager);
    
    public:
        bool Initialize(void* args = nullptr) override final;
		void Update(const float& deltaTime) override final;
    
    public: // Setters

    public: // Getters

    private:
		SceneManager *m_SceneManager = nullptr;
};

#endif /* !ANIMATOR_H_ */
