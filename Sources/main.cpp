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
#include <GameManager.h>

using namespace irr;

int main()
{
    Unique<GameManager> gameManager = CreateUnique<GameManager>();
    Entity player;
    std::string mesh = "Assets/bomberman_m.obj";

    gameManager->Initialize();
    RenderSystem renderSystem(gameManager->GetEntityManager());
    Drawable drawable(gameManager->GetSceneManager());
    Transform transform;

    drawable.Initialize(&mesh);
    player.AddComponent(&drawable, drawable.Id);
    player.AddComponent(&transform, transform.Id);
    renderSystem.OnEntityCreated(player);
    gameManager->GetEntityManager()->AddEntity(player);
    gameManager->GetEntityManager()->AddSystem(&renderSystem);
    gameManager->GetSceneManager()->addCameraSceneNode(0, irr::core::vector3df(0, 5, -10), transform.GetPosition());

    while (gameManager->GetDevice()->run())
    {
        gameManager->GetVideoDriver()->beginScene(true, true, irr::video::SColor(255, 0, 100, 255));
        gameManager->GetEntityManager()->Update();
        gameManager->GetVideoDriver()->endScene();
    }
	return 0;
}