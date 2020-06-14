/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Player
*/

#ifndef PLAYER_H_
#define PLAYER_H_

#include <ECS/Component.h>
#include <Core.hpp>
#include <GameManager.h>

class Player : public Component
{
    public:
        static constexpr ComponentId Id = "Player"_hash;

    public:
        Player(SceneManager* manager);

    public:
        bool Initialize(void* args) override final;
        void Update(const float& deltaTime, GameManager* gameManager) override final;

    public:
        void bindKey(const std::string &action, const irr::EKEY_CODE &);

    private:
        SceneManager* m_SceneManager;
        PlayerData_t* m_Data;
};

#endif /* !PLAYER_H_ */