/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** AnimatorSystem
*/

#ifndef ANIMATORSYSTEM_H_
#define ANIMATORSYSTEM_H_

#include <ECS/System/System.h>
#include <ECS/EntityManager.h>

#include <Components/Drawable.h>
#include <Components/Animator.h>

class AnimatorSystem : public System<Drawable, Animator>
{
    using BaseType = System<Drawable, Animator>;

    public:
        AnimatorSystem(EntityManager* pEntityManager);
    
    public:
        virtual void Update(const double &deltaTime) override;
};

#endif /* !ANIMATORSYSTEM_H_ */
