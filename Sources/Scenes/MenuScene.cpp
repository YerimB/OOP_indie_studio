#include <Scenes/MenuScene.hpp>
#include <GameManager.h>

// Systems
#include <ECS/ECS.h>

static void changeSceneToGame(GameManager* gameManager)
{
    gameManager->GetSoundManager()->PlaySound("sndPlay");
	gameManager->SetSceneChange(true);
	gameManager->SetNextScene(Scene::LUNCH_GAME);
}

static void quitGame(GameManager* gameManager)
{
    gameManager->GetSoundManager()->PlaySound("sndQuit");
    gameManager->m_globalVars.gameActive = false;
}

static void lowerSound(GameManager* gameManager)
{
    gameManager->GetSoundManager()->setVolume(SoundManager::SoundType::MUSIC, gameManager->GetSoundManager()->getVolume(SoundManager::SoundType::MUSIC) - 0.1f);
}

static void upperSound(GameManager* gameManager)
{
    gameManager->GetSoundManager()->setVolume(SoundManager::SoundType::MUSIC, gameManager->GetSoundManager()->getVolume(SoundManager::SoundType::MUSIC) + 0.1f);
}

static void lowerFX(GameManager* gameManager)
{
    gameManager->GetSoundManager()->setVolume(SoundManager::SoundType::SFX, gameManager->GetSoundManager()->getVolume(SoundManager::SoundType::SFX) - 0.1f);
    gameManager->GetSoundManager()->PlaySound("sndBeep");
}

static void upperFX(GameManager* gameManager)
{
    gameManager->GetSoundManager()->setVolume(SoundManager::SoundType::SFX, gameManager->GetSoundManager()->getVolume(SoundManager::SoundType::SFX) + 0.1f);
    gameManager->GetSoundManager()->PlaySound("sndBeep");
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

    this->AddTexture(gm->LoadTexture("Assets/textures/music.png"), "music");
    this->AddTexture(gm->LoadTexture("Assets/textures/fx.png"), "fx");

    gm->GetSoundManager()->AddSound(gm->GetSoundManager()->LoadSound("Assets/sound/beep.ogg"), "sndBeep", SoundManager::SoundType::SFX);
    gm->GetSoundManager()->AddSound(gm->GetSoundManager()->LoadSound("Assets/sound/beep.ogg"), "sndPlay", SoundManager::SoundType::SFX);
    gm->GetSoundManager()->AddSound(gm->GetSoundManager()->LoadSound("Assets/sound/beep.ogg"), "sndQuit", SoundManager::SoundType::SFX);
}

// Load Entities & Components
void MenuScene::LoadElements(GameManager* gm)
{
    Entity backgroundEntity("background");
    Entity playBtnEntity("playBtn");
    Entity quitBtnEntity("quitBtn");
    Entity speakerEntity("speaker");
    Entity btnUpperSoundEntity("upperSound");
    Entity btnLowerSoundEntity("lowerSound");
    Entity fxEntity("fx");
    Entity btnUpperFXEntity("upperFX");
    Entity btnLowerFXEntity("lowerFX");

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

    Image* speakerImage = new Image(gm->GetGuiEnvironment());
    if (speakerImage && speakerImage->Initialize(this->GetTexture("music")));
    {
        speakerImage->SetSize(60, 60);
        speakerImage->SetPosition({ 1735, 74 });
        speakerEntity.AddComponent(std::move(speakerImage), Image::Id);
    }

    Button* btnUpperSound = new Button(gm->GetGuiEnvironment());
    if (btnUpperSound->Initialize(nullptr))
    {
        btnUpperSound->SetButtonID(Button::ButtonID::UPPERMUSIC);
        btnUpperSound->SetTexture(gm->LoadTexture("Assets/textures/plus.png"));
        btnUpperSound->SetSize(50, 50);
        btnUpperSound->SetPosition({ 1835, 79 });
        btnUpperSound->SetOnPress(upperSound);
        btnUpperSoundEntity.AddComponent(std::move(btnUpperSound), Button::Id);
    }

    Button* btnLowerSound = new Button(gm->GetGuiEnvironment());
    if (btnLowerSound->Initialize(nullptr))
    {
        btnLowerSound->SetButtonID(Button::ButtonID::LOWERMUSIC);
        btnLowerSound->SetTexture(gm->LoadTexture("Assets/textures/minus.png"));
        btnLowerSound->SetSize(50, 50);
        btnLowerSound->SetPosition({ 1645, 79 });
        btnLowerSound->SetOnPress(lowerSound);
        btnLowerSoundEntity.AddComponent(std::move(btnLowerSound), Button::Id);
    }

    Image* fxImage = new Image(gm->GetGuiEnvironment());
    if (fxImage && fxImage->Initialize(this->GetTexture("fx")));
    {
        fxImage->SetSize(60, 60);
        fxImage->SetPosition({ 1735, 164 });
        fxEntity.AddComponent(std::move(fxImage), Image::Id);
    }

    Button* btnUpperFX = new Button(gm->GetGuiEnvironment());
    if (btnUpperFX->Initialize(nullptr))
    {
        btnUpperFX->SetButtonID(Button::ButtonID::UPPERFX);
        btnUpperFX->SetTexture(gm->LoadTexture("Assets/textures/plus.png"));
        btnUpperFX->SetSize(50, 50);
        btnUpperFX->SetPosition({ 1835, 169 });
        btnUpperFX->SetOnPress(upperFX);
        btnUpperFXEntity.AddComponent(std::move(btnUpperFX), Button::Id);
    }

    Button* btnLowerFX = new Button(gm->GetGuiEnvironment());
    if (btnLowerFX->Initialize(nullptr))
    {
        btnLowerFX->SetButtonID(Button::ButtonID::LOWERFX);
        btnLowerFX->SetTexture(gm->LoadTexture("Assets/textures/minus.png"));
        btnLowerFX->SetSize(50, 50);
        btnLowerFX->SetPosition({ 1645, 169 });
        btnLowerFX->SetOnPress(lowerFX);
        btnLowerFXEntity.AddComponent(std::move(btnLowerFX), Button::Id);
    }

    gm->GetEntityManager()->AddEntity(backgroundEntity);
    gm->GetEntityManager()->AddEntity(playBtnEntity);
    gm->GetEntityManager()->AddEntity(quitBtnEntity);
    gm->GetEntityManager()->AddEntity(speakerEntity);
    gm->GetEntityManager()->AddEntity(btnUpperSoundEntity);
    gm->GetEntityManager()->AddEntity(btnLowerSoundEntity);
    gm->GetEntityManager()->AddEntity(fxEntity);
    gm->GetEntityManager()->AddEntity(btnUpperFXEntity);
    gm->GetEntityManager()->AddEntity(btnLowerFXEntity);
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