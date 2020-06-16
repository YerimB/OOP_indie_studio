/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** VictoryScene
*/

#include <Scenes/VictoryScene.hpp>
#include <GameManager.h>

// Systems
#include <ECS/System/ButtonSystem.h>
#include <ECS/ECS.h>

// Components
#include <Components/Transform.h>

float dir = 0.05;
float dir2 = 0.05;

static void changeSceneToGame(GameManager* gameManager)
{
}

static void changeSceneToMenu(GameManager* gameManager)
{
	gameManager->SetSceneChange(true);
	gameManager->SetNextScene(Scene::MENU);
}

static void quitGame(GameManager* gameManager)
{
}

VictoryScene::VictoryScene() : Scene(Scene::VICTORY)
{
}

VictoryScene::~VictoryScene()
{
}

void VictoryScene::LoadSystems(GameManager* gameManager)
{
    ButtonSystem* buttonSys = new ButtonSystem(gameManager->GetEntityManager());
    ImageSystem* imageSys = new ImageSystem(gameManager->GetEntityManager());
    TextSystem* textSys = new TextSystem(gameManager->GetEntityManager());
    RenderSystem* renderSys = new RenderSystem(gameManager->GetEntityManager());

    gameManager->GetEntityManager()->AddSystem(std::move(buttonSys));
    gameManager->GetEntityManager()->AddSystem(std::move(imageSys));
    gameManager->GetEntityManager()->AddSystem(std::move(textSys));
    gameManager->GetEntityManager()->AddSystem(std::move(renderSys));
}

void VictoryScene::LoadAssets(GameManager* gameManager)
{
    gameManager->GetSoundManager()->AddSound(
        gameManager->GetSoundManager()->LoadSound("Assets/sound/end_game.ogg"),
        "sndEnd",
        SoundManager::SoundType::MUSIC
    );

    this->AddTexture(gameManager->LoadTexture("Assets/textures/block.png"), "Block");
    this->AddTexture(gameManager->LoadTexture("Assets/textures/btnHome.png"), "iconHome");

    auto sm = gameManager->GetSceneManager();
    this->AddMesh(sm->getMesh("Assets/mario.b3d"), "Mario");
    this->AddMesh(sm->getMesh("Assets/luigi.b3d"), "Luigi");
    this->AddMesh(sm->getMesh("Assets/koopa.b3d"), "Koopa");
    this->AddMesh(sm->getMesh("Assets/star.b3d"), "Star");
    this->AddMesh(sm->getMesh("Assets/bob-omb.b3d"), "Bob-omb");
    this->AddMesh(sm->getMesh("Assets/blooper.b3d"), "Blooper");
}

// Load Entities & Components
void VictoryScene::LoadElements(GameManager* gameManager)
{
    {
        Entity cubeEntity("cube1");
        Transform* t0 = new Transform();
        Collider* cl0 = new Collider(Collider::Tag::None);
        Cube* c0 = new Cube(gameManager->GetSceneManager());

        if (c0->Initialize(this->GetTexture("Block")))
        {
            // c0->SetTexture(texture);
            cubeEntity.AddComponent(t0, Transform::Id);
            cubeEntity.AddComponent(c0, Cube::Id);
            cubeEntity.AddComponent(cl0, Collider::Id);
            c0->SetPosition(Vector3f(0, -50, 100));
            c0->SetScale(Vector3f(2, 3, 1));
            gameManager->GetEntityManager()->AddEntity(cubeEntity);
        }  
    }

    auto &gv = gameManager->m_globalVars;
    const auto &pRank = gv.playersRanking;
    { // Player WINNER 1st
        Entity e2("Player1");
        Drawable* d2 = new Drawable(gameManager->GetSceneManager());
        Transform* t2 = new Transform();
        Collider *newCollider = new Collider(Collider::Tag::Player1);
        Animator* a = new Animator(gameManager->GetSceneManager());
        const std::string meshID(gv.meshIDMap.at((pRank[pRank.size() - 1])));

        if (t2->Initialize(0) && d2->Initialize(this->GetMesh(meshID)) && \
        a->Initialize(d2->GetDrawable())) {
            a->AddAnimation("Idle", {0, 300, 30});
			a->PlayAnimation("Idle");
            e2.AddComponent(a, Animator::Id);
            e2.AddComponent(d2, Drawable::Id);
            e2.AddComponent(newCollider, Drawable::Id);
            e2.AddComponent(t2, Transform::Id);
            d2->SetScale(Vector3f(0.3, 0.3, 0.3));
            d2->SetPosition({0, 1.4, 0});
            d2->SetRotation(Vector3f(10, 0, 0));
        }
        gameManager->GetEntityManager()->AddEntity(e2);
    }
    
    {
        Entity cubeEntity2("cube2");
        Transform* t1 = new Transform();
        Collider* cl1 = new Collider(Collider::Tag::None);
        Cube* c1 = new Cube(gameManager->GetSceneManager());

        if (c1->Initialize(this->GetTexture("Block")))
        {
            // c1->SetTexture(texture);
            cubeEntity2.AddComponent(t1, Transform::Id);
            cubeEntity2.AddComponent(c1, Cube::Id);
            cubeEntity2.AddComponent(cl1, Collider::Id);
            c1->SetPosition(Vector3f(-20, -50, 92));
            c1->SetRotation(Vector3f(0, -5, 0));
            c1->SetScale(Vector3f(2, 2, 1));
            gameManager->GetEntityManager()->AddEntity(cubeEntity2);
        }  
    }

    { // Player 2nd
        Entity e3("Player2");
        Drawable* d3 = new Drawable(gameManager->GetSceneManager());
        Transform* t3 = new Transform();
        Collider *newCollider = new Collider(Collider::Tag::Player1);
        Animator* a = new Animator(gameManager->GetSceneManager());
        const std::string meshID(gv.meshIDMap.at((pRank[pRank.size() - 2])));

        if (t3->Initialize(0) && d3->Initialize(this->GetMesh(meshID)) && \
        a->Initialize(d3->GetDrawable())) {
            a->AddAnimation("Idle", {0, 300, 30});
			a->PlayAnimation("Idle");
            e3.AddComponent(a, Animator::Id);
            e3.AddComponent(d3, Drawable::Id);
            e3.AddComponent(newCollider, Drawable::Id);
            e3.AddComponent(t3, Transform::Id);
            d3->SetScale(Vector3f(0.3, 0.3, 0.3));
            d3->SetPosition({-2, 0.7, 0});
            d3->SetRotation(Vector3f(10, 0, 0));
        }
        gameManager->GetEntityManager()->AddEntity(e3);
    }

    {
        Entity cubeEntity3("cube3");
        Transform* t2 = new Transform();
        Collider* cl2 = new Collider(Collider::Tag::None);
        Cube* c2 = new Cube(gameManager->GetSceneManager());

        if (c2->Initialize(this->GetTexture("Block")))
        {
            // c2->SetTexture(texture);
            cubeEntity3.AddComponent(t2, Transform::Id);
            cubeEntity3.AddComponent(c2, Cube::Id);
            cubeEntity3.AddComponent(cl2, Collider::Id);
            c2->SetPosition(Vector3f(19.5, -50, 85));
            c2->SetScale(Vector3f(2, 1, 1));
            c2->SetRotation(Vector3f(0, 5, 0));
            gameManager->GetEntityManager()->AddEntity(cubeEntity3);
        }  
    }

    { // Player 3rd
        Entity e4("Player3");
        Drawable* d4 = new Drawable(gameManager->GetSceneManager());
        Transform* t4 = new Transform();
        Collider *newCollider = new Collider(Collider::Tag::Player1);
        Animator* a = new Animator(gameManager->GetSceneManager());
        const std::string meshID(gv.meshIDMap.at((pRank[pRank.size() - 3])));

        if (t4->Initialize(0) && d4->Initialize(this->GetMesh(meshID)) && \
        a->Initialize(d4->GetDrawable())) {
            a->AddAnimation("Idle", {0, 300, 30});
			a->PlayAnimation("Idle");
            e4.AddComponent(a, Animator::Id);
            e4.AddComponent(d4, Drawable::Id);
            e4.AddComponent(newCollider, Drawable::Id);
            e4.AddComponent(t4, Transform::Id);
            d4->SetScale(Vector3f(0.3, 0.3, 0.3));
            d4->SetPosition({2, -0.2, 0});
            d4->SetRotation(Vector3f(10, 0, 0));
        }
        gameManager->GetEntityManager()->AddEntity(e4);
    }

    { // Last Player 4th
        Entity e5("Player4");
        Drawable* d5 = new Drawable(gameManager->GetSceneManager());
        Transform* t5 = new Transform();
        Collider *newCollider = new Collider(Collider::Tag::Player1);
        Animator* a = new Animator(gameManager->GetSceneManager());
        const std::string meshID(gv.meshIDMap.at((pRank[0])));

        if (t5->Initialize(0) && d5->Initialize(this->GetMesh(meshID)) && \
        a->Initialize(d5->GetDrawable())) {
            a->AddAnimation("Run", {301, 320, 30});
			a->PlayAnimation("Run");
            e5.AddComponent(a, Animator::Id);
            e5.AddComponent(d5, Drawable::Id);
            e5.AddComponent(newCollider, Drawable::Id);
            e5.AddComponent(t5, Transform::Id);
            d5->SetScale(Vector3f(0.3, 0.3, 0.3));
            d5->SetPosition({2, -5, 0});
            d5->SetRotation(Vector3f(0, 90, 0));
        }
        gameManager->GetEntityManager()->AddEntity(e5);
    }

    { // Back to menu button
        Entity e1("BackButton");
        Button* b1 = new Button(gameManager->GetGuiEnvironment());

        if (b1->Initialize(nullptr)) {
            b1->SetButtonID(Button::ButtonID::QUIT);
            b1->SetTexture(this->GetTexture("iconHome"));
            b1->SetPosition({ 20, 20 });
            b1->SetSize(80, 80);
            b1->SetTextureToFit(true);
            b1->SetOnPress(changeSceneToMenu);
            e1.AddComponent(std::move(b1), Button::Id);
        }
        gameManager->GetEntityManager()->AddEntity(e1);
    }

    { // Bob-omb
        Entity e6("Bob-omb");
        Drawable* d6 = new Drawable(gameManager->GetSceneManager());
        Transform* t6 = new Transform();
        Collider *newCollider = new Collider(Collider::Tag::Player1);
        // Animator* a = new Animator(gameManager->GetSceneManager());

        if (t6->Initialize(0) && d6->Initialize(this->GetMesh("Bob-omb")))
        //  && a->Initialize(d6->GetDrawable())) {
        {
            // a->AddAnimation("Run", {301, 320, 30});
			// a->PlayAnimation("Run");
            // e6.AddComponent(a, Animator::Id);
            e6.AddComponent(d6, Drawable::Id);
            e6.AddComponent(newCollider, Drawable::Id);
            e6.AddComponent(t6, Transform::Id);
            d6->SetScale(Vector3f(0.3, 0.3, 0.3));
            d6->SetPosition({5, -5, 0});
            d6->SetRotation(Vector3f(0, 180, 0));
        }
        gameManager->GetEntityManager()->AddEntity(e6);
    }
}

void VictoryScene::Load(GameManager* gameManager)
{
    gameManager->GetGuiEnvironment()->clear();
    gameManager->GetSceneManager()->clear();

    this->LoadSystems(gameManager);
    this->LoadAssets(gameManager);
    this->LoadElements(gameManager);

    gameManager->GetSoundManager()->setLoop("sndEnd", (-1));
    gameManager->GetSoundManager()->PlaySound("sndEnd");

    // Add Camera to Scene.
    gameManager->GetSceneManager()->addCameraSceneNode(0, Vector3f(0, 5, -10), { 0, 0, 0 });
}

void VictoryScene::Update(GameManager* gameManager)
{
    Entity* e1 = gameManager->GetEntityManager()->GetEntity("Player4");
    Drawable *d1 = e1->GetComponent<Drawable>();

    Entity* e2 = gameManager->GetEntityManager()->GetEntity("Bob-omb");
    Drawable *d2 = e2->GetComponent<Drawable>();

    d1->SetPosition(Vector3f(d1->GetPosition().X - dir, d1->GetPosition().Y, d1->GetPosition().Z));
    d2->SetPosition(Vector3f(d2->GetPosition().X - dir2, d2->GetPosition().Y, d2->GetPosition().Z));

    if (d1->GetPosition().X < -20)
    {
        dir = -0.05;
        d1->SetRotation(Vector3f(d1->GetPosition().X, 270, d1->GetPosition().Z));
    }
    if (d2->GetPosition().X < -20)
    {
        dir2 = -0.05;
        d2->SetRotation(Vector3f(d2->GetPosition().X, 0, d2->GetPosition().Z));
    }
    if (d1->GetPosition().X > 20)
    {
        dir = 0.05;
        d1->SetRotation(Vector3f(d1->GetPosition().X, 90, d1->GetPosition().Z));
    }
    if (d2->GetPosition().X > 20)
    {
        dir2 = 0.05;
        d2->SetRotation(Vector3f(d2->GetPosition().X, 180, d2->GetPosition().Z));
    }
}

void VictoryScene::Unload(void)
{

}