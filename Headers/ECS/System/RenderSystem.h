/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** RenderSystem
*/

#ifndef RENDERSYSTEM_H_
#define RENDERSYSTEM_H_

#include <ECS/System/System.h>
#include <ECS/EntityManager.h>

class Renderable; //TODO
class TransformComponent; //TODO

class RenderSystem : public System<Renderable, TransformComponent>
{
    using BaseType = System<Renderable, TransformComponent>;

    public:
        RenderSystem(EntityManager *pEntityManager);
    
    public:
        virtual void Update(const double &deltaTime) override;
};

#endif /* !RENDERSYSTEM_H_ */
