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
#include <Components/Transform.h>
#include <GameManager.h>

void printTotorina(void)
{
    std::cout << "Totorina" << std::endl;
}

int main()
{
    Unique<GameManager> gameManager = CreateUnique<GameManager>();
    Entity e1;

    gameManager->Initialize();

    // Add systems first
    ButtonSystem buttonSys(gameManager->GetEntityManager());
    gameManager->GetEntityManager()->AddSystem(&buttonSys);

    // Components
    Transform transform;
    Button b1(gameManager->GetGuiEnvironment());

    transform.Initialize(nullptr);
    transform.SetPosition({ 200, 500, 0 });

    if (b1.Initialize(nullptr)) {
        b1.SetButtonID(Button::ButtonID::PLAY);
        b1.SetTexture(gameManager->LoadTexture("Assets/block.png"));
        b1.SetText("Totorina");
        b1.SetPosition({500, 200});
        b1.SetOnPress(printTotorina);
        e1.AddComponent(&b1, Button::Id);
    }

    gameManager->GetEntityManager()->AddEntity(e1);
    gameManager->GetSceneManager()->addCameraSceneNode(0, Vector3f(0, 5, -10), transform.GetPosition());

    while (gameManager->GetDevice()->run()) {
        gameManager->GetVideoDriver()->beginScene(true, true, Color(255, 0, 100, 255));
        gameManager->GetEntityManager()->Update();
        gameManager->GetVideoDriver()->endScene();
    }
	return 0;
}