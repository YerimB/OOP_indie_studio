/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** PlayerSystem
*/

#include <ECS/System/PlayerSystem.h>

PlayerSystem::PlayerSystem(EntityManager* pEntityManager) :
BaseType(pEntityManager) {}

void PlayerSystem::Update(const double &deltaTime)
{
    for (auto &compTuple : this->_components)
    {
        Player* player = std::get<Player*>(compTuple);

        if (!player)
            continue;
        player->Update(deltaTime, this->_EntityManager->GetGameManager());
    }
}
