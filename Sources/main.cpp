// #include <iostream>
// #include <Irrlicht/irrlicht.h>
// #include <Irrlicht/driverChoice.h>
// #include <Core.hpp>
// #include <Thread/Thread.hpp>
// #include <iostream>
// #include <fstream>
// #include <string>
// #include <sstream>
// #include <vector>

// using namespace irr;

// using namespace irr;

// using namespace core;
// using namespace scene;
// using namespace video;
// using namespace io;
// using namespace gui;

// #include "Map.hpp"

// #ifdef _IRR_WINDOWS_
// #pragma comment(lib, "Irrlicht.lib")
// #pragma comment(linker, "/subsystem:windows /ENTRY:mainCRTStartup")
// #endif

#include <Core.hpp>
#include <GameManager.h>
#include <Scenes/MenuScene.hpp>
#include <Scenes/GameScene.hpp>
#include <Scenes/LunchGame.hpp>


// void BindableTest(Vector2f &a)
// {
//     std::cout << "Position: X = " << a.X <<" Y = " << a.Y << std::endl;
//     if (a.Y > 1500)
//         a.Y = 0;
// }

// void createNewCube3D(ISceneManager* smgr, int nb, int x, int y, video::IVideoDriver* driver, const irr::io::path &texture_path)
// {
//     smgr->addCubeSceneNode(10.F, nullptr, nb, core::vector3df(x, 0, y));
//     smgr->getSceneNodeFromId(nb)->setMaterialTexture(0, driver->getTexture(texture_path));
//     smgr->getSceneNodeFromId(nb)->setMaterialFlag(video::EMF_LIGHTING, false);
// }

int test = 0;

// int main()
// {
//     IrrlichtDevice* device = createDevice(video::EDT_OPENGL, Dimension2u(1280, 720), 16, false, false, false);
//     // InputManager receiver(device);
//     // Thread thread(0, "InputManager Thread");
//     // Vector2f a = Vector2f(0.2f, 0.2f);
//     // Unique<IBindable> bindPosition = CreateUnique<Bindable<Vector2f>>(a, BindableTest, 0, "PlayerPosition");
//     // device->setEventReceiver(&receiver);
//     // receiver.AddBindable<Vector2f>(bindPosition);
//     // thread.Start(&InputManager::RunKeyboardManager, &receiver);
//     // thread.Status();
//     device->setWindowCaption(L"Irrlicht Engine - 2D Graphics Demo");
//     video::IVideoDriver* driver = device->getVideoDriver();
//     ISceneManager* smgr = device->getSceneManager();
//     IGUIEnvironment* guienv = device->getGUIEnvironment();
//     int sizeSquare = 0;
//     std::vector<irr::io::path> arr_asset;
//     arr_asset.push_back("./Assets/block.png");
//     arr_asset.push_back("./Assets/star.jpeg");
//     arr_asset.push_back("./Assets/pow.jpeg");
//     arr_asset.push_back("./Assets/sand.jpg");
//     Map map = Map(smgr, driver, arr_asset);
//     map.CreateMap();
//     while(device->run())
//     {
//         driver->beginScene(true, true, SColor(255,100,101,140));
//         smgr->drawAll();
//         guienv->drawAll();
//         driver->endScene();
//     }
//     device->drop();
//     return 0;
// }

// struct SAppContext
// {
//     IrrlichtDevice *device;
//     s32             counter;
// };

// // Define some values that we'll use to identify individual GUI controls.
// enum
// {
//     GUI_ID_QUIT_BUTTON = 101,
//     GUI_ID_CHANGE_BLOCK_LEFT,
//     GUI_ID_CHANGE_BLOCK_RIGHT,
// };

// void setSkinTransparency(s32 alpha, irr::gui::IGUISkin * skin)
// {
//     for (s32 i=0; i<irr::gui::EGDC_COUNT ; ++i)
//     {
//         video::SColor col = skin->getColor((EGUI_DEFAULT_COLOR)i);
//         col.setAlpha(alpha);
//         skin->setColor((EGUI_DEFAULT_COLOR)i, col);
//     }
// }

// class MyEventReceiver : public IEventReceiver
// {
// public:
//     MyEventReceiver(SAppContext & context) : Context(context) { }

//     virtual bool OnEvent(const SEvent& event)
//     {
//         if (event.EventType == EET_GUI_EVENT)
//         {
//             s32 id = event.GUIEvent.Caller->getID();
//             IGUIEnvironment* env = Context.device->getGUIEnvironment();

//             switch(event.GUIEvent.EventType)
//             {
//                 case EGET_BUTTON_CLICKED:
//                 switch(id)
//                 {
//                     case GUI_ID_CHANGE_BLOCK_LEFT:
//                         test = 1;
//                         break;
//                     case GUI_ID_CHANGE_BLOCK_RIGHT:
//                         test = 2;
//                         break;
//                     default:
//                         break;
//                 }
//             }
//         }

//         return false;
//     }

//     private:
//     SAppContext & Context;
// };

// int main()
// {
//     IrrlichtDevice *device = createDevice( video::EDT_SOFTWARE, dimension2d<u32>(640, 480), 16, false, false, false, 0);

//     if (!device)
//         return 1;
//     device->setWindowCaption(L"Hello World! - Irrlicht Engine Demo");

//     IVideoDriver* driver = device->getVideoDriver();
//     ISceneManager* smgr = device->getSceneManager();
//     IGUIEnvironment* guienv = device->getGUIEnvironment();

//     IAnimatedMesh* mesh = smgr->getMesh("./media/sydney.md2");
//     if (!mesh)
//     {
//         device->drop();
//         return 1;
//     }
//     IAnimatedMeshSceneNode* node = smgr->addAnimatedMeshSceneNode(mesh);

//     if (node)
//     {
//         node->setMaterialFlag(EMF_LIGHTING, false);
//         node->setMD2Animation(scene::EMAT_STAND);
//         node->setMaterialTexture( 0, driver->getTexture("./media/sydney.bmp") );
//     }
//     node->setPosition(vector3df(-35,-10,-60));


//     scene::ISceneNode *cube = smgr->addCubeSceneNode(10.F, nullptr, 10, core::vector3df(0, 50, 0));;
//     cube->setMaterialTexture(0, driver->getTexture("./Assets/block.png"));
//     cube->setMaterialFlag(video::EMF_LIGHTING, false);

//     scene::ISceneNodeAnimator* anim = smgr->createRotationAnimator(core::vector3df(0, 1, 0));
//     if (anim)
//     {
//         cube->addAnimator(anim);
//         anim->drop();
//     }


//     IAnimatedMeshSceneNode* node2 = smgr->addAnimatedMeshSceneNode( mesh );
//     if (node2)
//     {
//         node2->setMaterialFlag(EMF_LIGHTING, false);
//         node2->setMD2Animation(scene::EMAT_STAND);
//         node2->setMaterialTexture( 0, driver->getTexture("./media/sydney.bmp") );
//     }
//     node2->setPosition(vector3df(-15,-10, -20));


//     IAnimatedMeshSceneNode* node3 = smgr->addAnimatedMeshSceneNode( mesh );
//     if (node3)
//     {
//         node3->setMaterialFlag(EMF_LIGHTING, false);
//         node3->setMD2Animation(scene::EMAT_STAND);
//         node3->setMaterialTexture( 0, driver->getTexture("./media/sydney.bmp") );
//     }
//     node3->setPosition(vector3df(5,-10, 20));


//     IAnimatedMeshSceneNode* node4 = smgr->addAnimatedMeshSceneNode( mesh );
//     if (node4)
//     {
//         node4->setMaterialFlag(EMF_LIGHTING, false);
//         node4->setMD2Animation(scene::EMAT_STAND);
//         node4->setMaterialTexture( 0, driver->getTexture("./media/sydney.bmp") );
//     }
//     node4->setPosition(vector3df(20,-10, 60));

//     smgr->addCameraSceneNode(0, vector3df(80,30,-40), vector3df(0,5,0));

//     SAppContext context;
//     context.device = device;
//     context.counter = 0;

//     MyEventReceiver receiver(context);
//     device->setEventReceiver(&receiver);

//     int HEIGHT_SCREEN = driver->getScreenSize().Height;
//     int WIDTH_SCREEN = driver->getScreenSize().Width;

//     guienv->addButton(rect<s32>(WIDTH_SCREEN / 2 + 100 ,HEIGHT_SCREEN / 6, WIDTH_SCREEN / 2 + 150, HEIGHT_SCREEN / 6 + 32), 0, GUI_ID_CHANGE_BLOCK_RIGHT, L">");
//     guienv->addButton(rect<s32>(WIDTH_SCREEN / 2 - 150 ,HEIGHT_SCREEN / 6, WIDTH_SCREEN / 2 - 100, HEIGHT_SCREEN / 6 + 32), 0, GUI_ID_CHANGE_BLOCK_LEFT, L"<");
//     while(device->run())
//     {
        
//         if (HEIGHT_SCREEN != driver->getScreenSize().Height || WIDTH_SCREEN != driver->getScreenSize().Width)
//         {
//             HEIGHT_SCREEN = driver->getScreenSize().Height;
//             WIDTH_SCREEN = driver->getScreenSize().Width;
//             guienv->getRootGUIElement()->getElementFromId(GUI_ID_CHANGE_BLOCK_RIGHT)->setRelativePosition(core::position2di(WIDTH_SCREEN / 2 + 100 ,HEIGHT_SCREEN / 6));
//             guienv->getRootGUIElement()->getElementFromId(GUI_ID_CHANGE_BLOCK_LEFT)->setRelativePosition(core::position2di(WIDTH_SCREEN / 2 - 150 ,HEIGHT_SCREEN / 6));            // guienv = device->getGUIEnvironment();            // guienv = device->getGUIEnvironment();
//         }
//         driver->beginScene(true, true, SColor(255,100,101,140));

//         smgr->drawAll();
//         guienv->drawAll();

//         if (test == 1)
//         {
//             smgr->getSceneNodeFromId(10)->setMaterialTexture(0, driver->getTexture("./Assets/block.png"));
//             smgr->getSceneNodeFromId(10)->setMaterialFlag(video::EMF_LIGHTING, false);
//             test = 0;
//         }
//         if (test == 2)
//         {
//             smgr->getSceneNodeFromId(10)->setMaterialTexture(0, driver->getTexture("./Assets/star.jpeg"));
//             smgr->getSceneNodeFromId(10)->setMaterialFlag(video::EMF_LIGHTING, false);
//             test = 0;
//         }

//         driver->endScene();
//     }
//     device->drop();

//     return 0;
// }

int main()
{
    Unique<GameManager> gameManager = CreateUnique<GameManager>();
    MenuScene menu;
    LunchGame luncher;
    GameScene game;

    gameManager->Initialize();
    gameManager->AddScene(&menu);
    gameManager->AddScene(&luncher);
    gameManager->AddScene(&game);

    gameManager->ProgramLoop();
	return 0;
}