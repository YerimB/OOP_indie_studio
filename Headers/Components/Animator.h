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
#include <GameManager.h>

class Animator : public Component
{
    public:
		static constexpr ComponentId Id = "Animator"_hash;
    
    public:
        Animator(SceneManager *p_SceneManager);
    
    public:
        bool Initialize(void* args = nullptr) override final;
        void Update(const float& deltaTime, GameManager* gameManager) override final;
    
    public:
        const bool AddAnimation(const std::string &sID, const Vector3i &p);
        void PlayAnimation(const std::string &sID);
        void StopAnimation(void);

    private:
        SceneManager *m_SceneManager = nullptr;
        AMeshNode *m_AnimatedMesh = nullptr;
        std::unordered_map<std::string, Vector3i /* start, end, speed */ > m_AnimationMap;
};

#endif /* !ANIMATOR_H_ */
