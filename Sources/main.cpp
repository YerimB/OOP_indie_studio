/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** main
*/

#include <Irrlicht/irrlicht.h>

namespace irr
{
	int launch()
	{
		IrrlichtDevice *device = createDevice(video::EDT_SOFTWARE, \
					core::dimension2d<u32>(1280, 720), 32, 0, 0, 0, 0);
		gui::IGUIEnvironment *guienv = nullptr;
		video::IVideoDriver *driver = nullptr;
		scene::ISceneManager *smgr = nullptr;

		if (!device)
			return (84);
		device->setWindowCaption(L"Irrlicht window");
		smgr = device->getSceneManager();
		driver = device->getVideoDriver();
		guienv = device->getGUIEnvironment();

		guienv->addStaticText(L"Hello World ! Totorina la palpolita.", \
		core::rect<s32>(10, 10, 260, 22), true);
		scene::IAnimatedMesh *mesh = smgr->getMesh("my_assets/faerie.md2");
		if (!mesh) {
			device->drop();
			return (84);
		}
		scene::IAnimatedMeshSceneNode *node = smgr->addAnimatedMeshSceneNode(mesh);
		if (node) {
			node->setMaterialFlag(video::EMF_LIGHTING, false);
			node->setMD2Animation(scene::EMAT_STAND);
			// node->setMaterialTexture(0, driver->getTexture("my_assets/sydney.md2"));
		}
		smgr->addCameraSceneNode(0, core::vector3df(0, 30, -40), core::vector3df(0, 5, 0));
		while (device->run()) {
			driver->beginScene(true, true, video::SColor(255, 100, 101, 140));
			smgr->drawAll();
			guienv->drawAll();
			driver->endScene();
		}
		device->drop();
		return 0;
	}
}

int main()
{
	return (irr::launch());
}