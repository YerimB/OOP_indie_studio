/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** PlayerSystem
*/

#ifndef PLAYERSYSTEM_H_
#define PLAYERSYSTEM_H_

#include <ECS/System/System.h>
#include <ECS/EntityManager.h>

#include <Components/Player.h>
#include <Components/Transform.h>

class PlayerSystem : public System<Player, Transform>
{
    using BaseType = System<Player, Transform>;

    public:
        PlayerSystem(EntityManager *pEntityManager);
    
    public:
        virtual void Update(const double &deltaTime) override;
};

#endif /* !PLAYERSYSTEM_H_ */
