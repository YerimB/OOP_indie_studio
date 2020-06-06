/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** RenderSystem
*/

#include <ECS/System/RenderSystem.h>

 RenderSystem::RenderSystem(Shared<EntityManager> pEntityManager) :
 BaseType(pEntityManager) {}

 void RenderSystem::Update(const double &deltaTime)
 {
     for (auto &compTuple : this->_components) {
         Transform *pTransform = std::get<Transform*>(compTuple);
         Drawable *pRenderable = std::get<Drawable*>(compTuple);

         // Render code...
         auto obj = pRenderable->GetDrawable();
         obj->setPosition(pTransform->GetPosition());
     }
 }
