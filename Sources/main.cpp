#include <iostream>
#include <Irrlicht/irrlicht.h>
#include <Core.hpp>
#include <Bindable/Bindable.hpp>
#include <InputManager/InputManager.hpp>
#include <Thread/Thread.hpp>

using namespace irr;

void BindableTest(Vector2f &a)
{
    std::cout << "Position: X = " << a.X <<" Y = " << a.Y << std::endl;
    if (a.Y > 1500)
        a.Y = 0;
}

int main()
{
    IrrlichtDevice* device = createDevice(video::EDT_OPENGL, core::dimension2d<u32>(1280, 720), 16, false, false, false);
    InputManager receiver(device);
    Thread thread(0, "InputManager Thread");

    Vector2f a = Vector2f(0.2f, 0.2f);
    UniqueBindable bindPosition = CreateBindable<Vector2f>(a, BindableTest, 0, "PlayerPosition");

    device->setEventReceiver(&receiver);
    receiver.AddBindable<Vector2f>(bindPosition);
    thread.Start(&InputManager::RunKeyboardManager, &receiver);

    while (device->run())
    {
    }

	return 0;
}