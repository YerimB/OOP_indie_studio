#include <GameManager.h>

GameManager::GameManager()
{
    m_Device = nullptr;
    m_VideoDriver = nullptr;
    m_GuiEnvironment = nullptr;
    m_SceneManager = nullptr;
    m_EntityManager = nullptr;
    m_InputManager = nullptr;

    { // Players data
        { // Player 1
            m_globalVars.playersData[0].playerID = 1;
            m_globalVars.playersData[0].characterID = 1;
            m_globalVars.playersData[0].bindingsMap = {
                std::pair<std::string, Binding>("UP", irr::KEY_KEY_Z),
                std::pair<std::string, Binding>("DOWN", irr::KEY_KEY_S),
                std::pair<std::string, Binding>("RIGHT", irr::KEY_KEY_D),
                std::pair<std::string, Binding>("LEFT", irr::KEY_KEY_Q),
                std::pair<std::string, Binding>("DROP", irr::KEY_KEY_E)
            };
        }
        { // Player 2
            m_globalVars.playersData[1].playerID = 2;
            m_globalVars.playersData[1].characterID = 2;
            m_globalVars.playersData[1].bindingsMap = {
                std::pair<std::string, Binding>("UP", irr::KEY_UP),
                std::pair<std::string, Binding>("DOWN", irr::KEY_DOWN),
                std::pair<std::string, Binding>("RIGHT", irr::KEY_RIGHT),
                std::pair<std::string, Binding>("LEFT", irr::KEY_LEFT),
                std::pair<std::string, Binding>("DROP", irr::KEY_KEY_M)
            };
        }
        { // Player 3
            m_globalVars.playersData[2].playerID = 3;
            m_globalVars.playersData[2].characterID = 3;
            m_globalVars.playersData[2].bindingsMap = {
                std::pair<std::string, Binding>("UP", irr::KEY_RETURN),
                std::pair<std::string, Binding>("DOWN", irr::KEY_RETURN),
                std::pair<std::string, Binding>("RIGHT", irr::KEY_RETURN),
                std::pair<std::string, Binding>("LEFT", irr::KEY_RETURN),
                std::pair<std::string, Binding>("DROP", irr::KEY_RETURN)
            };
        }
        { // Player 4
            m_globalVars.playersData[3].playerID = 4;
            m_globalVars.playersData[3].characterID = 4;
            m_globalVars.playersData[3].bindingsMap = {
                std::pair<std::string, Binding>("UP", irr::KEY_RETURN),
                std::pair<std::string, Binding>("DOWN", irr::KEY_RETURN),
                std::pair<std::string, Binding>("RIGHT", irr::KEY_RETURN),
                std::pair<std::string, Binding>("LEFT", irr::KEY_RETURN),
                std::pair<std::string, Binding>("DROP", irr::KEY_RETURN)
            };
        }
    }
    this->m_lastFrameTime = std::chrono::duration_cast<std::chrono::milliseconds>\
    (std::chrono::system_clock::now().time_since_epoch());
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

    irr::core::array<irr::SJoystickInfo> info;
    m_Device->activateJoysticks(info);
}

// First step:  Unloads the current scene if there is one.
// Second step: Loads the scene matching the ID passed as parameter.
void GameManager::LoadScene(const Scene::SceneID &sceneID)
{
    if (sceneID != Scene::SceneID::UNDEFINED)
        m_Scenes[sceneID]->Unload();
    m_EntityManager->ClearAll();
    m_SoundManager->Clear();
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
        this->m_Scenes[this->m_CurrentSceneID]->Update(this);
        this->m_EntityManager->Update();
        this->m_VideoDriver->endScene();
        if (m_globalVars.sceneChanged == true)
        {
            this->LoadScene(static_cast<Scene::SceneID>(m_globalVars.newScene));
            m_globalVars.sceneChanged = false;
        }
        this->waitBeforeNextFrame(60); // Maintain fps at 60
    }
    if (m_Device->run())
        m_Device->closeDevice();
}

// Loads the texture linked to the path passed as parameter and return a pointer to it.
Texture *GameManager::LoadTexture(const std::string &path)
{
    return (this->m_VideoDriver->getTexture(path.c_str()));
}

// Wait for a certain time before launching next frame
void GameManager::waitBeforeNextFrame(const size_t &fps)
{
    auto nowTime = std::chrono::duration_cast<std::chrono::milliseconds>\
        (std::chrono::system_clock::now().time_since_epoch());
    while (nowTime.count() - m_lastFrameTime.count() < 1000 / fps)
        nowTime = std::chrono::duration_cast<std::chrono::milliseconds>\
        (std::chrono::system_clock::now().time_since_epoch());
    this->m_lastFrameTime = std::chrono::duration_cast<std::chrono::milliseconds>\
    (std::chrono::system_clock::now().time_since_epoch());
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