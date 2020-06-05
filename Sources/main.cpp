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
    Entity player;

    Shared<Transform> transform = CreateShared<Transform>();
    Shared<Text> text = CreateShared<Text>();

    player.AddComponent(transform, transform->Id);
    player.AddComponent(text, text->Id);
    manager.AddEntity(player);

    if (player.GetComponent<Transform>()->Initialize(nullptr))
        std::cout << player.GetComponent<Transform>()->GetPosition().X << std::endl;

    if (player.GetComponent<Text>()->Initialize(&std::string("Ceci est un texte")))
        std::cout << player.GetComponent<Text>()->GetText() << std::endl;

    while (device->run())
    {
    }

    device->drop();

	return 0;
}