#include <Scenes/MenuScene.hpp>
#include <GameManager.h>

// Systems
#include <ECS/System/ButtonSystem.h>
#include <ECS/System/ImageSystem.h>

// Components
#include <Components/Transform.h>

static void changeSceneToGame(GameManager* gameManager)
{
	gameManager->SetSceneChange(true);
	gameManager->SetNextScene(Scene::GAME);
}

static void quitGame(GameManager* gameManager)
{
    gameManager->GetDevice()->drop();
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

}

// Load Entities & Components
void MenuScene::LoadElements(GameManager* gm)
{
        Entity backgroundEntity("background");
        Entity playBtnEntity("playBtn");
        Entity quitBtnEntity("quitBtn");

        Texture* texBg = gm->LoadTexture("Assets/menubg.png");
        Image* background = new Image(gm->GetGuiEnvironment());
        if (background->Initialize(texBg) && background)
        {
            background->SetSize(1280, 815);
            backgroundEntity.AddComponent(std::move(background), Image::Id);
        }

        Button* btnPlay = new Button(gm->GetGuiEnvironment());
        if (btnPlay->Initialize(nullptr))
        {
            btnPlay->SetButtonID(Button::ButtonID::PLAY);
            btnPlay->SetTexture(gm->LoadTexture("Assets/btnPlay.png"));
            btnPlay->SetSize(398, 131);
            btnPlay->SetPosition({ 100, 720 / 2 });
            btnPlay->SetOnPress(changeSceneToGame);
            playBtnEntity.AddComponent(std::move(btnPlay), Button::Id);
        }

        Button* btnQuit = new Button(gm->GetGuiEnvironment());
        if (btnQuit->Initialize(nullptr))
        {
            btnQuit->SetButtonID(Button::ButtonID::QUIT);
            btnQuit->SetTexture(gm->LoadTexture("Assets/btnQuit.png"));
            btnQuit->SetSize(250, 82);
            btnQuit->SetPosition({ 250, 720 / 2 + 200 });
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
    // Add Camera to Scene.
    gameManager->GetSceneManager()->addCameraSceneNode(0, Vector3f(0, 5, -10), { 0, 0, 0 });
}


/*

gameManager->GetGuiEnvironment()->clear();
    gameManager->GetSceneManager()->clear();

    { // Create and Add Systems (Always first)
        ButtonSystem* buttonSys = new ButtonSystem(gameManager->GetEntityManager());
        ImageSystem* imageSys = new ImageSystem(gameManager->GetEntityManager());

        gameManager->GetEntityManager()->AddSystem(std::move(buttonSys));
        gameManager->GetEntityManager()->AddSystem(std::move(imageSys));
    }

    // Load Entities & Components
	{
        Entity backgroundEntity;
        Entity playBtnEntity;
        Entity quitBtnEntity;

        Texture* texBg = gameManager->LoadTexture("Assets/menubg.png");
        Image* background = new Image(gameManager->GetGuiEnvironment());
        if (background->Initialize(texBg) && background)
        {
            background->SetSize(1280, 815);
            backgroundEntity.AddComponent(std::move(background), Image::Id);
        }

        Button* btnPlay = new Button(gameManager->GetGuiEnvironment());
        if (btnPlay->Initialize(nullptr))
        {
            btnPlay->SetButtonID(Button::ButtonID::PLAY);
            btnPlay->SetTexture(gameManager->LoadTexture("Assets/btnPlay.png"));
            btnPlay->SetSize(398, 131);
            btnPlay->SetPosition({ 100, 720 / 2 });
            btnPlay->SetOnPress(cbChangeSceneToGame);
            playBtnEntity.AddComponent(std::move(btnPlay), Button::Id);
        }

        Button* btnQuit = new Button(gameManager->GetGuiEnvironment());
        if (btnQuit->Initialize(nullptr))
        {
            btnQuit->SetButtonID(Button::ButtonID::QUIT);
            btnQuit->SetTexture(gameManager->LoadTexture("Assets/btnQuit.png"));
            btnQuit->SetSize(250, 82);
            btnQuit->SetPosition({ 250, 720 / 2 + 200 });
            btnQuit->SetOnPress(cbQuitGame);
            quitBtnEntity.AddComponent(std::move(btnQuit), Button::Id);
        }

        gameManager->GetEntityManager()->AddEntity(backgroundEntity);
        gameManager->GetEntityManager()->AddEntity(playBtnEntity);
        gameManager->GetEntityManager()->AddEntity(quitBtnEntity);
    }

    gameManager->GetSceneManager()->addCameraSceneNode(0, Vector3f(0, 5, -10), { 0, 0, 0 });

*/

void MenuScene::Update(GameManager* gameManager)
{

}

void MenuScene::Unload(void)
{

}