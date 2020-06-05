#include <iostream>
#include <Irrlicht/irrlicht.h>
#include <Core.hpp>
#include <Bindable/Bindable.hpp>
#include <InputManager/InputManager.hpp>
#include <Thread/Thread.hpp>
#include <ECS/Entity.h>
#include <ECS/EntityManager.h>
#include <Components/Position.h>

using namespace irr;

void BindableTest(Vector2f &a)
{
    std::cout << "Position: X = " << a.X <<" Y = " << a.Y << std::endl;
    if (a.Y > 1500)
        a.Y = 0;
}

int main()
{
    IrrlichtDevice* device = createDevice(video::EDT_OPENGL, Dimension2u(1280, 720), 16, false, false, false);
    EntityManager manager;
    Position position;
    Entity player(0);

    player.AddComponent(&position);

    auto result = player.GetComponent<Position>();

    std::cout << result->GetPosition().X << std::endl;

    while (device->run())
    {
    }

    device->drop();

	return 0;
}