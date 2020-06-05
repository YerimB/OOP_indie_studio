#include <iostream>
#include <Irrlicht/irrlicht.h>
#include <Irrlicht/driverChoice.h>
#include <Core.hpp>
#include <Bindable/Bindable.hpp>
#include <InputManager/InputManager.hpp>
#include <Thread/Thread.hpp>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

using namespace irr;

using namespace irr;

using namespace core;
using namespace scene;
using namespace video;
using namespace io;
using namespace gui;

#include "Map.hpp"

#ifdef _IRR_WINDOWS_
#pragma comment(lib, "Irrlicht.lib")
#pragma comment(linker, "/subsystem:windows /ENTRY:mainCRTStartup")
#endif

void BindableTest(Vector2f &a)
{
    std::cout << "Position: X = " << a.X <<" Y = " << a.Y << std::endl;
    if (a.Y > 1500)
        a.Y = 0;
}

void createNewCube3D(ISceneManager* smgr, int nb, int x, int y, video::IVideoDriver* driver, const irr::io::path &texture_path)
{
    smgr->addCubeSceneNode(10.F, nullptr, nb, core::vector3df(x, 0, y));
    smgr->getSceneNodeFromId(nb)->setMaterialTexture(0, driver->getTexture(texture_path));
    smgr->getSceneNodeFromId(nb)->setMaterialFlag(video::EMF_LIGHTING, false);
}

int main()
{
    IrrlichtDevice* device = createDevice(video::EDT_OPENGL, Dimension2u(1280, 720), 16, false, false, false);
    // InputManager receiver(device);
    // Thread thread(0, "InputManager Thread");

    // Vector2f a = Vector2f(0.2f, 0.2f);
    // Unique<IBindable> bindPosition = CreateUnique<Bindable<Vector2f>>(a, BindableTest, 0, "PlayerPosition");

    // device->setEventReceiver(&receiver);
    // receiver.AddBindable<Vector2f>(bindPosition);
    // thread.Start(&InputManager::RunKeyboardManager, &receiver);
    // thread.Status();

    device->setWindowCaption(L"Irrlicht Engine - 2D Graphics Demo");

    video::IVideoDriver* driver = device->getVideoDriver();
    ISceneManager* smgr = device->getSceneManager();
    IGUIEnvironment* guienv = device->getGUIEnvironment();
    int sizeSquare = 0;
    std::vector<irr::io::path> arr_asset;
    arr_asset.push_back("./Assets/block.png");
    arr_asset.push_back("./Assets/star.jpeg");
    arr_asset.push_back("./Assets/pow.jpeg");
    arr_asset.push_back("./Assets/sand.jpg");
        
    Map map = Map(smgr, driver, arr_asset);
    
    map.CreateMap();
    while(device->run())
    {
        driver->beginScene(true, true, SColor(255,100,101,140));

        smgr->drawAll();
        guienv->drawAll();
        driver->endScene();
    }

    device->drop();
    return 0;
}