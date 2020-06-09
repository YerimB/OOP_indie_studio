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
#include <ECS/System/RenderSystem.h>
#include <ECS/System/TextSystem.h>
#include <Components/Transform.h>
#include <Components/Text.h>
#include <Components/Image.h>
#include <GameManager.h>

int main()
{
    Unique<GameManager> gameManager = CreateUnique<GameManager>();
    Entity player;
    Entity imgtest;
    Entity texttest;
    std::string mesh = "Assets/bomberman_m.obj";
    std::string textStr = "Bon";

    gameManager->Initialize();

    // Add systems first
    TextSystem textSystem(gameManager->GetEntityManager());
    gameManager->GetEntityManager()->AddSystem(&textSystem);

    // Components
    Text text(gameManager->GetGuiEnvironment());
    Transform transform;

    transform.Initialize(nullptr);
    text.Initialize(&textStr);
    text.SetColor();
    text.SetText("Totorina");
    transform.SetPosition({ 200, 500, 0 });

    texttest.AddComponent(&transform, transform.Id);
    texttest.AddComponent(&text, text.Id);

    gameManager->GetEntityManager()->AddEntity(texttest);
    gameManager->GetSceneManager()->addCameraSceneNode(0, Vector3f(0, 5, -10), transform.GetPosition());

    while (gameManager->GetDevice()->run()) {
        gameManager->GetVideoDriver()->beginScene(true, true, Color(255, 0, 100, 255));
        gameManager->GetEntityManager()->Update();
        gameManager->GetVideoDriver()->endScene();
    }
	return 0;
}