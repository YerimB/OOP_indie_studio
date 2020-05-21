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


    // START ALEXIS CODE

    video::IVideoDriver* driver = device->getVideoDriver();
    ISceneManager* smgr = device->getSceneManager();
    IGUIEnvironment* guienv = device->getGUIEnvironment();

    std::ifstream file("test.txt");
    std::string STRING; 
    std::string str;
    int sizeSquare = 0;
    while (std::getline(file, STRING)) {
        str += STRING;
        sizeSquare = STRING.size();
        str += '\n';
    }

    std::cout << "SIZE SQUARE  = " << sizeSquare << std::endl;

    std::vector<int> posX;
    std::vector<int> posY;

    int heightCamera = 0;
    int x = 0;
    int xActual = 0;
    int y = 0;
    int nb = 0;

    heightCamera = sizeSquare * 10;
    std::string lenghtX = std::to_string(sizeSquare);
    x = (int)lenghtX[1] - '0';
    if (x == 0) x = -40 * ((int)lenghtX[0] - '0');
    else x = -x * 10;
    xActual = x - 10;
    y = x - 10;

    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == '\n')
        {
            x = -90;
            y += 10;
        }

        if (str[i] == '1')
        {
            createNewCube3D(smgr, nb, x, y, driver, "./Assets/block.png");
            posX.push_back(x);
            posY.push_back(y);
            nb += 1;
        }

        if (str[i] == '2')
        {
            createNewCube3D(smgr, nb, x, y, driver, "./Assets/star.jpeg");
            posX.push_back(x);
            posY.push_back(y);
            nb += 1;
        }

        if (str[i] == '3')
        {
            createNewCube3D(smgr, nb, x, y, driver, "./Assets/pow.jpeg");
            posX.push_back(x);
            posY.push_back(y);
            nb += 1;
        }

        x += 10;
    }

    core::vector3df pos = smgr->getSceneNodeFromId(sizeSquare / 2)->getAbsolutePosition();

    std::cout << "POS X = " << pos.X << std::endl;

    smgr->addCubeSceneNode(10.F, nullptr, -2, core::vector3df(pos.X, 0, pos.Y), core::vector3df(0, 0, 0), core::vector3df(sizeSquare - 1, 0, sizeSquare - 1));
    smgr->getSceneNodeFromId(-2)->setMaterialTexture(0, driver->getTexture("./Assets/sand.jpg"));
    smgr->getSceneNodeFromId(-2)->setMaterialFlag(video::EMF_LIGHTING, false);

    pos = smgr->getSceneNodeFromId(-2)->getAbsolutePosition();

    std::cout << "POS X = " << pos.X << std::endl;

    smgr->addCameraSceneNode(0, vector3df(0, heightCamera, 10), vector3df(0,0,0));

    while(device->run())
    {
        driver->beginScene(true, true, SColor(255,100,101,140));

        smgr->drawAll();
        guienv->drawAll();
        driver->endScene();
    }

    device->drop();
    return 0;

    // END OF ALEXIS'S CODE
}