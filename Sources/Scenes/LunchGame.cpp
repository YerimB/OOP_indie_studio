/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** LunchGame
*/

#include <Scenes/LunchGame.hpp>
#include <GameManager.h>

// Systems
#include <ECS/System/ButtonSystem.h>
#include <ECS/ECS.h>

// Components
#include <Components/Transform.h>

static void changeSceneToGame(GameManager* gameManager)
{
	gameManager->SetSceneChange(true);
	gameManager->SetNextScene(Scene::GAME);
}

static void test(GameManager* gameManager)
{
	std::cout << "TEST\n";
}

static void changeCharacter(GameManager* gameManager)
{
	// gameManager->GetEntityManager()->get
}

LunchGame::LunchGame() : Scene(Scene::LUNCH_GAME)
{
}

LunchGame::~LunchGame()
{
}

void LunchGame::LoadSystems(GameManager* gm)
{
    ButtonSystem* buttonSys = new ButtonSystem(gm->GetEntityManager());
    ImageSystem* imageSys = new ImageSystem(gm->GetEntityManager());
    TextSystem* textSys = new TextSystem(gm->GetEntityManager());
    RenderSystem* renderSys = new RenderSystem(gm->GetEntityManager());

    gm->GetEntityManager()->AddSystem(std::move(buttonSys));
    gm->GetEntityManager()->AddSystem(std::move(imageSys));
    gm->GetEntityManager()->AddSystem(std::move(textSys));
    gm->GetEntityManager()->AddSystem(std::move(renderSys));
}

void LunchGame::LoadAssets(GameManager* gm)
{
    this->AddTexture(gm->LoadTexture("Assets/textures/block.png"), "Block");
    this->AddTexture(gm->LoadTexture("Assets/textures/pow.jpeg"), "Pow");
    this->AddTexture(gm->LoadTexture("Assets/textures/mario_bg.jpeg"), "Bg");

    auto sm = gm->GetSceneManager();
    this->AddMesh(sm->getMesh("Assets/mario.b3d"), "Mario");
    this->AddMesh(sm->getMesh("Assets/luigi.b3d"), "Luigi");
    this->AddMesh(sm->getMesh("Assets/koopa.b3d"), "Koopa");
    this->AddMesh(sm->getMesh("Assets/star.b3d"), "Star");
}

void LunchGame::LoadElements(GameManager* gameManager)
{
    // Entity backgroundEntity("background");

    // Image* background = new Image(gameManager->GetGuiEnvironment());
    // if (background && background->Initialize(this->GetTexture("Bg")))
    // {
    //     background->SetSize(1000, 100);
    //     backgroundEntity.AddComponent(std::move(background), Image::Id);
    // }

    // gameManager->GetEntityManager()->AddEntity(backgroundEntity);

    Entity playBtnEntity("playBtn");
    Button* btnPlay = new Button(gameManager->GetGuiEnvironment());
    if (btnPlay->Initialize(nullptr))
    {
        btnPlay->SetButtonID(Button::ButtonID::PLAY);
        btnPlay->SetTexture(gameManager->LoadTexture("Assets/textures/btnPlay.png"));
        btnPlay->SetSize(398, 131);
        btnPlay->SetPosition({ 800, 850 });
        btnPlay->SetOnPress(changeSceneToGame);
        playBtnEntity.AddComponent(std::move(btnPlay), Button::Id);
    }
    gameManager->GetEntityManager()->AddEntity(playBtnEntity);

    {
        Entity e1("Player01");
        Drawable* d1 = new Drawable(gameManager->GetSceneManager());
        Transform* t1 = new Transform();
        Collider *newCollider = new Collider();
        Button* b1 = new Button(gameManager->GetGuiEnvironment());

        if (b1->Initialize(nullptr)) {
            b1->SetButtonID(Button::ButtonID::CHANGEPLAY);
            b1->SetTexture(this->GetTexture("Pow"));
            b1->SetPosition({ 1575, 700 });
            b1->SetSize(100, 100);
            b1->SetTextureToFit(true);
            b1->SetOnPress(test);
            e1.AddComponent(std::move(b1), Button::Id);
        }
        if (t1->Initialize(0) && d1->Initialize(this->GetMesh("Mario"))) {
            e1.AddComponent(d1, Drawable::Id);
            e1.AddComponent(newCollider, Drawable::Id);
            e1.AddComponent(t1, Transform::Id);
            d1->SetScale(Vector3f(0.3, 0.3, 0.3));
            d1->SetPosition({-10, -2, 0});
            d1->SetRotation(Vector3f(0, 200, 0));
        }
        gameManager->GetEntityManager()->AddEntity(e1);
    }

    {
        Entity e2("Player02");
        Drawable* d2 = new Drawable(gameManager->GetSceneManager());
        Transform* t2 = new Transform();
        Collider *newCollider = new Collider();
        Button* b2 = new Button(gameManager->GetGuiEnvironment());

        if (b2->Initialize(nullptr)) {
            b2->SetButtonID(Button::ButtonID::CHANGEPLAY2);
            b2->SetTexture(this->GetTexture("Pow"));
            b2->SetPosition({ 1075, 700 });
            b2->SetSize(100, 100);
            b2->SetTextureToFit(true);
            b2->SetOnPress(test);
            e2.AddComponent(std::move(b2), Button::Id);
        }
        if (t2->Initialize(0) && d2->Initialize(this->GetMesh("Luigi"))) {
            e2.AddComponent(d2, Drawable::Id);
            e2.AddComponent(t2, Transform::Id);
            e2.AddComponent(newCollider, Drawable::Id);
            d2->SetRotation(Vector3f(0, 200, 0));
            d2->SetScale(Vector3f(0.3, 0.3, 0.3));
            d2->SetPosition(Vector3f(-3,-2, 0));
        }
        gameManager->GetEntityManager()->AddEntity(e2);
    }

    {
        Entity e3("Player03");
        Drawable* d3 = new Drawable(gameManager->GetSceneManager());
        Transform* t3 = new Transform();
        Collider *newCollider = new Collider();
        Button* b3 = new Button(gameManager->GetGuiEnvironment());

        if (b3->Initialize(nullptr)) {
            b3->SetButtonID(Button::ButtonID::CHANGEPLAY3);
            b3->SetTexture(this->GetTexture("Pow"));
            b3->SetPosition({ 675, 700 });
            b3->SetSize(100, 100);
            b3->SetTextureToFit(true);
            b3->SetOnPress(test);
            e3.AddComponent(std::move(b3), Button::Id);
        }

        if (t3->Initialize(0) && d3->Initialize(this->GetMesh("Koopa"))) {
            e3.AddComponent(d3, Drawable::Id);
            e3.AddComponent(t3, Transform::Id);
            e3.AddComponent(newCollider, Drawable::Id);
            d3->SetRotation(Vector3f(0, 140, 0));
            d3->SetScale(Vector3f(0.3, 0.3, 0.3));
            d3->SetPosition(Vector3f(3,-2, 0));
        }
        gameManager->GetEntityManager()->AddEntity(e3);
    }

    {
        Entity e4("e4");
        Drawable* d4 = new Drawable(gameManager->GetSceneManager());
        Transform* t4 = new Transform();
        Collider *newCollider = new Collider();
        Button* b4 = new Button(gameManager->GetGuiEnvironment());

        if (b4->Initialize(nullptr)) {
            b4->SetButtonID(Button::ButtonID::CHANGEPLAY4);
            b4->SetTexture(this->GetTexture("Pow"));
            b4->SetPosition({ 175, 700 });
            b4->SetSize(100, 100);
            b4->SetTextureToFit(true);
            b4->SetOnPress(test);
            e4.AddComponent(std::move(b4), Button::Id);
        }

        if (t4->Initialize(0) && d4->Initialize(this->GetMesh("Star"))) {
            e4.AddComponent(d4, Drawable::Id);
            e4.AddComponent(t4, Transform::Id);
            e4.AddComponent(newCollider, Drawable::Id);
            d4->SetRotation(Vector3f(0, 140, 0));
            d4->SetScale(Vector3f(0.3, 0.3, 0.3));
            d4->SetPosition(Vector3f(10,-2, 0));
        }
        gameManager->GetEntityManager()->AddEntity(e4);
    }

    // { // Back to menu button
    //     // Create components and entity
    //     Entity e7("e7");
    //     Button* b2 = new Button(gameManager->GetGuiEnvironment());

    //     // Initialize component and set attributes then add it to entity
    //     if (b2->Initialize(nullptr)) {
    //         b2->SetButtonID(Button::ButtonID::UNDEFINED);
    //         b2->SetTexture(gameManager->LoadTexture("Assets/sand.jpg"));
    //         b2->SetText("Change Character");
    //         b2->SetPosition({ 100, 100 });
    //         b2->SetSize(100, 100);
    //         b2->SetTextureToFit(true);
    //         b2->SetOnPress(changeCharacter);
    //         e7.AddComponent(std::move(b2), Button::Id);
    //     }
    //     // When done, add entity to the entity manager.
    //     gameManager->GetEntityManager()->AddEntity(e7);
    // }
}

void LunchGame::Load(GameManager* gameManager)
{
    gameManager->GetGuiEnvironment()->clear();
    gameManager->GetSceneManager()->clear();

    // Load Entities & Components
    this->LoadSystems(gameManager);
    this->LoadAssets(gameManager);
    this->LoadElements(gameManager);
	
    // Add Camera to Scene.
    gameManager->GetSceneManager()->addCameraSceneNode(0, Vector3f(0, 0, 10), { 0, 0, 0 });
}

void LunchGame::Update(GameManager* gameManager)
{

}

void LunchGame::Unload(void)
{

}