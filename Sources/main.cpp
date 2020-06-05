#include <iostream>
#include <Irrlicht/irrlicht.h>
#include <Core.hpp>
#include <Bindable/Bindable.hpp>
#include <InputManager/InputManager.hpp>
#include <Thread/Thread.hpp>
#include <ECS/Entity.h>
#include <ECS/EntityManager.h>
#include <Components/Transform.h>
using namespace irr;

int main()
{
    IrrlichtDevice* device = createDevice(video::EDT_OPENGL, Dimension2u(1280, 720), 16, false, false, false);
    EntityManager manager;
    Entity player;

    manager.AddEntity(player);
    player.AddComponent(CreateShared<Transform>());

    if (player.GetComponent<Transform>()->Initialize(nullptr))
    {
        std::cout << "Player Transform Initialized" << std::endl;
    }

    while (device->run())
    {
    }

    device->drop();

	return 0;
}