/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** ButtonSystem
*/

#ifndef BUTTONSYSTEM_H_
#define BUTTONSYSTEM_H_

#include <ECS/System/System.h>
#include <ECS/EntityManager.h>
#include <Components/Button.h>

class ButtonSystem : public System<Button>
{
    using BaseType = System<Button>;

    public:
        ButtonSystem(EntityManager *pEntityManager);
    
    public:
        virtual void Update(const double &deltaTime) override;
};

#endif /* !BUTTONSYSTEM_H_ */