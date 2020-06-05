/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** RenderSystem
*/

#include <RenderSystem.h>

RenderSystem::RenderSystem(EntityManager *pEntityManager) :
BaseType(pEntityManager) {}

void RenderSystem::Update(const double &deltaTime)
{
    for (auto &compTuple : this->_components) {
        TransformComponent *pTransform = std::get<TransformComponent *>(compTuple);
        Renderable *pRenderable = std::get<Renderable *>(compTuple);

        // Render code...
    }
}
