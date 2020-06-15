#include <Scenes/GameScene.hpp>
#include <GameManager.h>
#include <Map/Map.h>
// Systems
#include <ECS/ECS.h>

// Components
#include <Components/Transform.h>

static void changeSceneToMenu(GameManager* gameManager)
{
	gameManager->SetSceneChange(true);
	gameManager->SetNextScene(Scene::MENU);
}

GameScene::GameScene() : Scene(Scene::GAME)
{
}

GameScene::~GameScene()
{
}

void GameScene::LoadSystems(GameManager* gm)
{
    // Create
    AnimatorSystem* animSys = new AnimatorSystem(gm->GetEntityManager());
    ButtonSystem* buttonSys = new ButtonSystem(gm->GetEntityManager());
    ImageSystem* imageSys = new ImageSystem(gm->GetEntityManager());
    TextSystem* textSys = new TextSystem(gm->GetEntityManager());
    RenderSystem* renderSys = new RenderSystem(gm->GetEntityManager());
    MoveSystem* moveSys = new MoveSystem(gm->GetEntityManager());
    PlayerSystem* playerSys = new PlayerSystem(gm->GetEntityManager());
    TimeSystem* timeSys = new TimeSystem(gm->GetEntityManager());

    // Add
    gm->GetEntityManager()->AddSystem(std::move(animSys));
    gm->GetEntityManager()->AddSystem(std::move(buttonSys));
    gm->GetEntityManager()->AddSystem(std::move(imageSys));
    gm->GetEntityManager()->AddSystem(std::move(textSys));
    gm->GetEntityManager()->AddSystem(std::move(renderSys));
    gm->GetEntityManager()->AddSystem(std::move(moveSys));
    gm->GetEntityManager()->AddSystem(std::move(playerSys));
    gm->GetEntityManager()->AddSystem(std::move(timeSys));
}

void GameScene::LoadAssets(GameManager* gm)
{
    // Load textures
    this->AddTexture(gm->LoadTexture("Assets/textures/block.png"), "Block");
    this->AddTexture(gm->LoadTexture("Assets/textures/star.jpeg"), "Star");
    this->AddTexture(gm->LoadTexture("Assets/textures/pow.jpeg"), "Pow");
    this->AddTexture(gm->LoadTexture("Assets/textures/btnHome.png"), "iconHome");

    // Load Meshes
    auto sm = gm->GetSceneManager();
    this->AddMesh(sm->getMesh("Assets/mario.b3d"), "Mario");
    this->AddMesh(sm->getMesh("Assets/luigi.b3d"), "Luigi");
    this->AddMesh(sm->getMesh("Assets/koopa.b3d"), "Koopa");
    this->AddMesh(sm->getMesh("Assets/star.b3d"), "Star");
    this->AddMesh(sm->getMesh("Assets/bob-omb.b3d"), "Bomb");

    gm->GetSoundManager()->AddSound(
        gm->GetSoundManager()->LoadSound("Assets/sound/game2.ogg"),
        "sndGame",
        SoundManager::SoundType::MUSIC
    );
}

// Load Entities & Components
void GameScene::LoadElements(GameManager* gm)
{
    { // Back to menu button
        Entity e1("BackButton");
        Button* b1 = new Button(gm->GetGuiEnvironment());

        if (b1->Initialize(nullptr)) {
            b1->SetButtonID(Button::ButtonID::QUIT);
            b1->SetTexture(this->GetTexture("iconHome"));
            b1->SetPosition({ 20, 20 });
            b1->SetSize(80, 80);
            b1->SetTextureToFit(true);
            b1->SetOnPress(changeSceneToMenu);
            e1.AddComponent(std::move(b1), Button::Id);
            gm->GetEntityManager()->AddEntity(e1);
        }
    }

    auto map = Map(gm);
    map.Initialize(16, this);
}

void GameScene::Load(GameManager* gameManager)
{
    gameManager->GetGuiEnvironment()->clear();
    gameManager->GetSceneManager()->clear();

    this->LoadSystems(gameManager);
    this->LoadAssets(gameManager);
    this->LoadElements(gameManager);

    gameManager->GetSoundManager()->setLoop("sndGame", (-1));
    gameManager->GetSoundManager()->PlaySound("sndGame");
}

void GameScene::Update(GameManager* gameManager)
{

}

void GameScene::Unload(void)
{
    
}