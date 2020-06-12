/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** RenderSystem
*/

#include <ECS/System/RenderSystem.h>

RenderSystem::RenderSystem(EntityManager* pEntityManager) :
BaseType(pEntityManager) {}

void RenderSystem::Update(const double &deltaTime)
{
    _EntityManager->GetSceneManager()->drawAll();
}
