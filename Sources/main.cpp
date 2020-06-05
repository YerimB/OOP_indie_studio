#include <iostream>
#include <Irrlicht/irrlicht.h>
#include <Core.hpp>
#include <Bindable/Bindable.hpp>
#include <InputManager/InputManager.hpp>
#include <Thread/Thread.hpp>
#include <ECS/Entity.h>
#include <ECS/EntityManager.h>
#include <Components/Transform.h>
#include <Components/Text.h>

using namespace irr;

int main()
{
    IrrlichtDevice* device = createDevice(video::EDT_OPENGL, Dimension2u(1280, 720), 16, false, false, false);
    EntityManager manager;
    Entity *player = new Entity();

    manager.AddEntity(*player);
    player->AddComponent(CreateShared<Transform>());
    player->AddComponent(CreateShared<Text>());

    if (player->GetComponent<Transform>()->Initialize(nullptr))
        std::cout << player->GetComponent<Transform>()->GetPosition().X << std::endl;

    if (player->GetComponent<Text>()->Initialize(new std::string("Ceci est un texte")))
        std::cout << player->GetComponent<Text>()->GetText() << std::endl;

    while (device->run())
    {
    }

    device->drop();
    delete player;

	return 0;
}