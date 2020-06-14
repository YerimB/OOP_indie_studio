#include <Scenes/MenuScene.hpp>
#include <GameManager.h>

// Systems
#include <ECS/ECS.h>

static void changeSceneToGame(GameManager* gameManager)
{
	gameManager->SetSceneChange(true);
	gameManager->SetNextScene(Scene::GAME);
}

static void quitGame(GameManager* gameManager)
{
    gameManager->m_globalVars.gameActive = false;
}

MenuScene::MenuScene() : Scene(Scene::MENU)
{
}

MenuScene::~MenuScene()
{
}

void MenuScene::LoadSystems(GameManager* gm)
{
    ButtonSystem* buttonSys = new ButtonSystem(gm->GetEntityManager());
    ImageSystem* imageSys = new ImageSystem(gm->GetEntityManager());

    gm->GetEntityManager()->AddSystem(std::move(buttonSys));
    gm->GetEntityManager()->AddSystem(std::move(imageSys));
}

void MenuScene::LoadAssets(GameManager* gm)
{
    gm->GetSoundManager()->AddSound(gm->GetSoundManager()->LoadSound("Assets/sound/menu.ogg"), "sndMenu", SoundManager::SoundType::MUSIC);
    this->AddTexture(gm->LoadTexture("Assets/textures/background_mario.png"), "texBg");
    gm->GetSoundManager()->AddSound(
        gm->GetSoundManager()->LoadSound("Assets/sound/menu.ogg"),
        "sndMenu",
        SoundManager::SoundType::MUSIC
    );

    this->AddTexture(this->GetTexture("Assets/textures/background_mario.png"), "texBg");
}

// Load Entities & Components
void MenuScene::LoadElements(GameManager* gm)
{
    Entity backgroundEntity("background");
    Entity playBtnEntity("playBtn");
    Entity quitBtnEntity("quitBtn");

    Image* background = new Image(gm->GetGuiEnvironment());
    if (background && background->Initialize(this->GetTexture("texBg")));
    {
        background->SetSize(1920, 1080);
        backgroundEntity.AddComponent(std::move(background), Image::Id);
    }

    Button* btnPlay = new Button(gm->GetGuiEnvironment());
    if (btnPlay->Initialize(nullptr))
    {
        btnPlay->SetButtonID(Button::ButtonID::PLAY);
        btnPlay->SetTexture(gm->LoadTexture("Assets/textures/btnPlay.png"));
        btnPlay->SetSize(398, 131);
        btnPlay->SetPosition({ 410, 720 / 2 + 100 });
        btnPlay->SetOnPress(changeSceneToGame);
        playBtnEntity.AddComponent(std::move(btnPlay), Button::Id);
    }

    Button* btnQuit = new Button(gm->GetGuiEnvironment());
    if (btnQuit->Initialize(nullptr))
    {
        btnQuit->SetButtonID(Button::ButtonID::QUIT);
        btnQuit->SetTexture(gm->LoadTexture("Assets/textures/btnQuit.png"));
        btnQuit->SetSize(250, 82);
        btnQuit->SetPosition({ 500, 720 / 2 + 300 });
        btnQuit->SetOnPress(quitGame);
        quitBtnEntity.AddComponent(std::move(btnQuit), Button::Id);
    }

    gm->GetEntityManager()->AddEntity(backgroundEntity);
    gm->GetEntityManager()->AddEntity(playBtnEntity);
    gm->GetEntityManager()->AddEntity(quitBtnEntity);
}

void MenuScene::Load(GameManager* gameManager)
{
    gameManager->GetGuiEnvironment()->clear();
    gameManager->GetSceneManager()->clear();

    this->LoadSystems(gameManager);
    this->LoadAssets(gameManager);
    this->LoadElements(gameManager);

    gameManager->GetSoundManager()->setLoop("sndMenu", (-1));
    gameManager->GetSoundManager()->PlaySound("sndMenu");
    // Add Camera to Scene.
    gameManager->GetSceneManager()->addCameraSceneNode(0, Vector3f(0, 5, -10), { 0, 0, 0 });
}

void MenuScene::Update(GameManager* gameManager)
{

}

void MenuScene::Unload(void)
{

}