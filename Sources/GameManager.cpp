#include <GameManager.h>

GameManager::GameManager()
{
    m_Device = nullptr;
    m_VideoDriver = nullptr;
    m_GuiEnvironment = nullptr;
    m_SceneManager = nullptr;
    m_EntityManager = nullptr;
    m_InputManager = nullptr;
}

GameManager::~GameManager()
{
    m_SceneManager->drop();
    m_VideoDriver->drop();
    m_GuiEnvironment->drop();
    m_Device->drop();
}

void GameManager::Initialize()
{
    m_Device = createDevice(video::EDT_OPENGL, Dimension2u(1280, 720), 16, false, false, false);
    m_VideoDriver = m_Device->getVideoDriver();
    m_GuiEnvironment = m_Device->getGUIEnvironment();
    m_SceneManager = m_Device->getSceneManager();
    m_EntityManager = CreateShared<EntityManager>(m_SceneManager);
    m_InputManager = CreateUnique<InputManager>(m_Device);

    m_Device->setEventReceiver(m_InputManager.get());
}

irr::IrrlichtDevice* GameManager::GetDevice() const
{
    return m_Device;
}

irr::video::IVideoDriver* GameManager::GetVideoDriver() const
{
    return m_VideoDriver;
}

irr::gui::IGUIEnvironment* GameManager::GetGuiEnvironment() const
{
    return m_GuiEnvironment;
}

irr::scene::ISceneManager* GameManager::GetSceneManager() const
{
    return m_SceneManager;
}

EntityManager* GameManager::GetEntityManager() const
{
    return m_EntityManager.get();
}

InputManager* GameManager::GetInputManager() const
{
    return m_InputManager.get();
}