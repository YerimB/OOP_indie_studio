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

        // std::cout << "Button " << pButton->GetButtonID() << std::endl;
        if (_EntityManager->GetInputManager()->IsButtonDown(pButton->GetButtonID()))
        {
            pButton->Update(deltaTime);
            _EntityManager->GetInputManager()->ResetButton(pButton->GetButtonID());
        }
    }
    // std::cout << "Button system done." << std::endl;
}