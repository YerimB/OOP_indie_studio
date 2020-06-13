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
    m_Device->drop();
}

void GameManager::Initialize()
{
    m_Device = irr::createDevice(
        irr::video::EDT_OPENGL,
        Dimension2u(1920, 1080),
        16,
        false,
        false,
        false
    );
    m_VideoDriver = m_Device->getVideoDriver();
    m_GuiEnvironment = m_Device->getGUIEnvironment();
    m_SceneManager = m_Device->getSceneManager();
    m_InputManager = CreateUnique<InputManager>(m_Device);
    m_EntityManager = CreateShared<EntityManager>(m_SceneManager, m_GuiEnvironment, m_InputManager.get(), this);
    m_SoundManager = CreateUnique<SoundManager>();

    m_Device->setEventReceiver(m_InputManager.get());
}

// First step:  Unloads the current scene if there is one.
// Second step: Loads the scene matching the ID passed as parameter.
void GameManager::LoadScene(const Scene::SceneID &sceneID)
{
    if (sceneID != Scene::SceneID::UNDEFINED)
        m_Scenes[sceneID]->Unload();
    m_EntityManager->ClearAll();
    m_Scenes[sceneID]->Load(this);
    m_CurrentSceneID = sceneID;
}

// Adds the scene passed as parameters if its type doesn't already exists.
void GameManager::AddScene(Scene* scene)
{
    m_Scenes.emplace(scene->GetID(), scene);
}

void GameManager::RemoveScene(const Scene::SceneID& sceneId)
{
    m_Scenes.erase(sceneId);
    m_EntityManager->ClearAll();
}

// Program main loop.
void GameManager::ProgramLoop(void)
{
    this->LoadScene(Scene::SceneID::MENU);
    while (this->m_globalVars.gameActive == true && m_Device->run())
    {
        this->m_VideoDriver->beginScene(true, true, Color(255, 135, 206, 250));
        this->m_EntityManager->Update();
        this->m_VideoDriver->endScene();
        if (m_globalVars.sceneChanged == true)
        {
            this->LoadScene(static_cast<Scene::SceneID>(m_globalVars.newScene));
            m_globalVars.sceneChanged = false;
        }
    }
    if (m_Device->run())
        m_Device->closeDevice();
}

// Loads the texture linked to the path passed as parameter and return a pointer to it.
Texture *GameManager::LoadTexture(const std::string &path)
{
    return (this->m_VideoDriver->getTexture(path.c_str()));
}

// Getters

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

SoundManager* GameManager::GetSoundManager() const
{
    return m_SoundManager.get();
}

Scene *GameManager::GetCurrentScene() const
{
    return m_Scenes.at(m_CurrentSceneID);
}

// Setters

void GameManager::SetSceneChange(const bool &state)
{
    this->m_globalVars.sceneChanged = state;
}

void GameManager::SetNextScene(const Scene::SceneID &sID)
{
    this->m_globalVars.newScene = sID;
}