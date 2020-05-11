#include <Irrlicht/irrlicht.h>

using namespace irr;

int main()
{
    IrrlichtDevice *device = createDevice(video::EDT_OPENGL, core::dimension2d<u32>(1280, 720));

	while (device->run());

	device->drop();
	return 0;
}