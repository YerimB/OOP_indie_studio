/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** main
*/

#include <iostream>
#include <Irrlicht/irrlicht.h>
#include <Core.hpp>
#include <InputManager/InputManager.hpp>
#include <Thread/Thread.hpp>
#include <ECS/Entity.h>
#include <ECS/EntityManager.h>
#include <ECS/System/ButtonSystem.h>
#include <Components/Button.h>
#include <GameManager.h>

int main()
{
    Unique<GameManager> gameManager = CreateUnique<GameManager>();

    gameManager->Initialize();

    // Add systems first
    ButtonSystem buttonSystem(gameManager->GetEntityManager());

    // Components
    Button button(gameManager->GetGuiEnvironment());
    button.Initialize(0); // Button::PLAY ?

    // Entity
    Entity buttonEntity;
    buttonEntity.AddComponent(&button, button.Id);

    // Add Entity
    buttonSystem.OnEntityCreated(buttonEntity);
    gameManager->GetEntityManager()->AddEntity(buttonEntity);
    gameManager->GetEntityManager()->AddSystem(&buttonSystem);

    gameManager->GetSceneManager()->addCameraSceneNode(0, Vector3f(0, 5, -10), { 0, 0, 0 });

    while (gameManager->GetDevice()->run()) {
        //gameManager->GetInputManager()->OnEvent();
        gameManager->GetVideoDriver()->beginScene(true, true, Color(255, 0, 100, 255));
        gameManager->GetEntityManager()->Update();
        gameManager->GetVideoDriver()->endScene();
    }
	return 0;
}