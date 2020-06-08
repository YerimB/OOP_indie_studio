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

using namespace irr;

int main()
{
    IrrlichtDevice* device = createDevice(video::EDT_OPENGL, Dimension2u(1280, 720), 16, false, false, false);
    irr::video::IVideoDriver* driver = device->getVideoDriver();
    irr::gui::IGUIEnvironment* guiEnv = device->getGUIEnvironment();
    irr::scene::ISceneManager* sceneManager = device->getSceneManager();
    Shared<EntityManager> manager = CreateShared<EntityManager>(sceneManager);
    InputManager inputManager(device);
    RenderSystem renderSystem(manager);
    device->setEventReceiver(&inputManager);

    Entity player;
    Drawable drawable(sceneManager);
    Transform transform;

    std::string mesh = "Assets/bomberman_m.obj";

    drawable.Initialize(&mesh);
    player.AddComponent(&drawable, drawable.Id);
    player.AddComponent(&transform, transform.Id);

    renderSystem.OnEntityCreated(player);
    manager->AddEntity(player);
    manager->AddSystem(&renderSystem);

    sceneManager->addCameraSceneNode(0, irr::core::vector3df(0, 5, -10), transform.GetPosition());

    while (device->run())
    {
        driver->beginScene(true, true, irr::video::SColor(255, 0, 100, 255));
        manager->Update();
        driver->endScene();
    }

    device->drop();
	return 0;
}