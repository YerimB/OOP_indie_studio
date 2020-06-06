/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** main
*/

#include <iostream>
#include <Irrlicht/irrlicht.h>
#include <Core.hpp>
#include <Bindable/Bindable.hpp>
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
    Shared<EntityManager> manager = CreateShared<EntityManager>();
    RenderSystem renderSystem(manager);

    Entity player;
    Shared<Drawable> drawable = CreateShared<Drawable>(sceneManager);
    Shared<Transform> transform = CreateShared<Transform>();
    player.AddComponent(drawable, drawable->Id);
    player.AddComponent(transform, transform->Id);

    renderSystem.OnEntityCreated(player);

    //guiEnv->addButton();
    //irr::scene::ISceneManager* sceneManager = device->getSceneManager();

    ////irr::scene::IMeshLoader* loader = new Meshloader()
    ////loader->createMesh("blblbl");

    ////driver->drawMeshBuffer(aMesh->getMeshBuffer(aMesh->getMaterial()));

    //irr::scene::IAnimatedMeshSceneNode* mesh = sceneManager->addAnimatedMeshSceneNode(sceneManager->getMesh(""));
    ////irr::video::ITexture* texture = sceneManager->getTexture

    //irr::video::SMaterial mat;
    //irr::video::ITexture* texture = driver->getTexture("TEXTURE");
    //irr::scene::IAnimatedMesh* aMesh;
    //mat.setTexture(0, texture);

    //mesh->setPosition({ 0, 0, 0 });
    //mesh->setRotation({ 0, 0, 0 });

    //mesh->setMaterialTexture(0, nullptr);

    //driver->drawMeshBuffer(mesh->getMesh()->getMeshBuffer(mat));
    //// ==
    //sceneManager->drawAll();


    while (device->run()) {}
    device->drop();
	return 0;
}