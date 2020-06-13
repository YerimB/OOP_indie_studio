#include <Scenes/GameScene.hpp>
#include <GameManager.h>
#include <ECS/System/MoveSystem.h>
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
    ButtonSystem* buttonSys = new ButtonSystem(gm->GetEntityManager());
    ImageSystem* imageSys = new ImageSystem(gm->GetEntityManager());
    TextSystem* textSys = new TextSystem(gm->GetEntityManager());
    RenderSystem* renderSys = new RenderSystem(gm->GetEntityManager());
    MoveSystem* moveSys = new MoveSystem(gm->GetEntityManager());
    PlayerSystem* playerSys = new PlayerSystem(gm->GetEntityManager());

    // Add
    gm->GetEntityManager()->AddSystem(std::move(buttonSys));
    gm->GetEntityManager()->AddSystem(std::move(imageSys));
    gm->GetEntityManager()->AddSystem(std::move(textSys));
    gm->GetEntityManager()->AddSystem(std::move(renderSys));
    gm->GetEntityManager()->AddSystem(std::move(moveSys));
    gm->GetEntityManager()->AddSystem(std::move(playerSys));
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
    this->AddMesh(sm->getMesh("Assets/bomberman_m.obj"), "Bomber");

    gm->GetSoundManager()->AddSound(
        gm->GetSoundManager()->LoadSound("Assets/sound/game.ogg"),
        "sndGame",
        SoundManager::SoundType::MUSIC
    );
}

// Load Entities & Components
void GameScene::LoadElements(GameManager* gm)
{
    { // Back to menu button
        // Create components and entity
        Entity e1("BackButton");
        Button* b1 = new Button(gm->GetGuiEnvironment());

        // Initialize component and set attributes then add it to entity
        if (b1->Initialize(nullptr)) {
            b1->SetButtonID(Button::ButtonID::QUIT);
            b1->SetTexture(this->GetTexture("iconHome"));
            b1->SetPosition({ 20, 20 });
            b1->SetSize(80, 80);
            b1->SetTextureToFit(true);
            b1->SetOnPress(changeSceneToMenu);
            e1.AddComponent(std::move(b1), Button::Id);
            // When done, add entity to the entity manager.
            gm->GetEntityManager()->AddEntity(e1);
        }
    }

    auto map = Map(gm);
    map.Initialize(20, this);
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
    // auto inputManager = gameManager->GetInputManager();
    // auto player1 = gameManager->GetEntityManager()->GetEntity("Player01");

    // if (inputManager->IsKeyDown(irr::KEY_KEY_Z))
    // {
    //     auto transform = player1.GetComponent<Transform>();
    //     auto position = transform->GetPosition();

    //     transform->SetPosition({ position.X + 0.5f, position.Y, position.Z });
    //     transform->SetRotation({ 0, 90, 0});
    // }
    // if (inputManager->IsKeyDown(irr::KEY_KEY_Q))
    // {
    //     auto transform = player1.GetComponent<Transform>();
    //     auto position = transform->GetPosition();

    //     transform->SetPosition({ position.X, position.Y, position.Z + 0.5f });
    //     transform->SetRotation({ 0, 0, 0});
    // }
    // if (inputManager->IsKeyDown(irr::KEY_KEY_S))
    // {
    //     auto transform = player1.GetComponent<Transform>();
    //     auto position = transform->GetPosition();

    //     transform->SetPosition({ position.X - 0.5f, position.Y, position.Z });
    //     transform->SetRotation({ 0, 270, 0});
    // }
    // if (inputManager->IsKeyDown(irr::KEY_KEY_D))
    // {
    //     auto transform = player1.GetComponent<Transform>();
    //     auto position = transform->GetPosition();

    //     transform->SetPosition({ position.X, position.Y, position.Z - 0.5f });
    //     transform->SetRotation({ 0, 180, 0});
    // }
    // if (inputManager->IsKeyDown(irr::KEY_KEY_B))
    // {
    //     // Bomb
    // }
}

void GameScene::Unload(void)
{
    
}