/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** ButtonSystem
*/

#include <ECS/System/ButtonSystem.h>

ButtonSystem::ButtonSystem(EntityManager* pEntityManager) :
System<Button>(pEntityManager) {}

void ButtonSystem::Update(const double &deltaTime)
{
    for (auto &compTuple : this->_components) {
        Button *pButton = std::get<Button *>(compTuple);

        if (_EntityManager->GetInputManager()->IsButtonDown(pButton->GetButtonID()))
        {
            pButton->Update(deltaTime, this->_EntityManager->GetGameManager());
            _EntityManager->GetInputManager()->ResetButton(pButton->GetButtonID());
        }
    }
}