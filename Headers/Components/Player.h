/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Player
*/

#ifndef PLAYER_H_
#define PLAYER_H_

#include <array>
#include <ECS/Component.h>
#include <Components/Transform.h>
#include <Components/Animator.h>
#include <Components/Timer.h>
#include <Core.hpp>
#include <GameManager.h>
#include <cmath>

class Player : public Component
{
    public:
        static constexpr ComponentId Id = "Player"_hash;

    public:
        Player(SceneManager* manager);

    public:
        bool Initialize(void* args) override final;
        void Update(const float& deltaTime, GameManager* gameManager) override;

    public:
        void bindKey(const std::string &action, const irr::EKEY_CODE &);
        void DropBomb(Entity& self, GameManager* gm);

    protected:
        void UpdateMap(Transform *pPos, GameVars_t *gVars);
        virtual void GetMovements(GameManager *gm, Entity &self);

    protected:
        std::array<int, 2> _previousPos;
        SceneManager* m_SceneManager;
        PlayerData_t* m_Data;
        Entity* m_Bomb = nullptr;
        bool m_oldMoveState = false;
};

#endif /* !PLAYER_H_ */
