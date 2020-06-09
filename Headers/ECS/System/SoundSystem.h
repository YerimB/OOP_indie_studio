/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** SoundSystem
*/

#ifndef SOUNDSYSTEM_H_
#define SOUNDSYSTEM_H_

#include <ECS/System/System.h>
#include <ECS/EntityManager.h>
#include <Components/SoundManager.h>

class SoundSystem : public System<SoundManager>
{
    using BaseType = System<SoundManager>;

    public:
        SoundSystem(EntityManager *pEntityManager);
    
    public:
        virtual void Update(const double &deltaTime) override;
};

#endif /* !SOUNDSYSTEM_H_ */