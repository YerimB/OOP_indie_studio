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
#include <Components/Transform.h>
#include <Components/Text.h>
#include <Components/Image.h>
#include <GameManager.h>

int main()
{
    Unique<GameManager> gameManager = CreateUnique<GameManager>();
    Entity player;
    Entity imgtest;
    std::string mesh = "Assets/bomberman_m.obj";

    gameManager->Initialize();
    RenderSystem renderSystem(gameManager->GetEntityManager());
    Image image(gameManager->GetGuiEnvironment());
    Drawable drawable(gameManager->GetSceneManager());
    Transform transform;

    image.Initialize(gameManager->LoadTexture("Assets/tnt.jpg"));
    drawable.Initialize(&mesh);
    player.AddComponent(&drawable, drawable.Id);
    player.AddComponent(&transform, transform.Id);
    renderSystem.OnEntityCreated(player);
    gameManager->GetEntityManager()->AddEntity(player);
    gameManager->GetEntityManager()->AddSystem(&renderSystem);
    gameManager->GetSceneManager()->addCameraSceneNode(0, Vector3f(0, 5, -10), transform.GetPosition());

    while (gameManager->GetDevice()->run())
    {
        gameManager->GetVideoDriver()->beginScene(true, true, Color(255, 0, 100, 255));
        gameManager->GetEntityManager()->Update();
        gameManager->GetVideoDriver()->endScene();
    }
	return 0;
}