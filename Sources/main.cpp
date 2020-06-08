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
    TextSystem textSystem(gameManager->GetEntityManager());
    Transform transform;
    Text text(gameManager->GetGuiEnvironment());

    transform.Initialize(nullptr);
    text.Initialize(&textStr);
    transform.SetPosition({ 100, 20, 0 });
    texttest.AddComponent(&transform, transform.Id);
    texttest.AddComponent(&text, text.Id);
   
    gameManager->GetEntityManager()->AddEntity(texttest);
    gameManager->GetEntityManager()->AddSystem(&textSystem);
    gameManager->GetSceneManager()->addCameraSceneNode(0, Vector3f(0, 5, -10), transform.GetPosition());

    while (gameManager->GetDevice()->run())
    {
        gameManager->GetVideoDriver()->beginScene(true, true, Color(255, 0, 100, 255));
        gameManager->GetEntityManager()->Update();
        gameManager->GetVideoDriver()->endScene();
    }
	return 0;
}