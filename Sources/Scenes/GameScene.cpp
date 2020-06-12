#include <Scenes/GameScene.hpp>
#include <GameManager.h>
#include <ECS/System/MoveSystem.h>
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

void GameScene::Load(GameManager* gameManager)
{
    gameManager->GetGuiEnvironment()->clear();
    gameManager->GetSceneManager()->clear();

    { // Create and Add Systems (Always first)
        // Create
        ButtonSystem* buttonSys = new ButtonSystem(gameManager->GetEntityManager());
        ImageSystem* imageSys = new ImageSystem(gameManager->GetEntityManager());
        TextSystem* textSys = new TextSystem(gameManager->GetEntityManager());
        RenderSystem* renderSys = new RenderSystem(gameManager->GetEntityManager());
        MoveSystem* moveSys = new MoveSystem(gameManager->GetEntityManager());
        // Add
        gameManager->GetEntityManager()->AddSystem(std::move(buttonSys));
        gameManager->GetEntityManager()->AddSystem(std::move(imageSys));
        gameManager->GetEntityManager()->AddSystem(std::move(textSys));
        gameManager->GetEntityManager()->AddSystem(std::move(renderSys));
        gameManager->GetEntityManager()->AddSystem(std::move(moveSys));
    }

    // Load Entities & Components
	{ // Back to menu button
        // Create components and entity
        Entity e1("BackButton");
        Button* b1 = new Button(gameManager->GetGuiEnvironment());

        // Initialize component and set attributes then add it to entity
        if (b1->Initialize(nullptr)) {
            b1->SetButtonID(Button::ButtonID::QUIT);
            b1->SetTexture(gameManager->LoadTexture("Assets/sand.jpg"));
            b1->SetText("Back to menu");
            b1->SetPosition({ 50, 50 });
            b1->SetSize(300, 100);
            b1->SetTextureToFit(true);
            b1->SetOnPress(changeSceneToMenu);
            e1.AddComponent(std::move(b1), Button::Id);
        }
        // When done, add entity to the entity manager.
        gameManager->GetEntityManager()->AddEntity(e1);
    }
    {
        Entity e2("AnimatedCharacter");
        Drawable* d1 = new Drawable(gameManager->GetSceneManager());
        Transform* t1 = new Transform();
        Collider* c1 = new Collider();
        Animator* a1 = new Animator(gameManager->GetSceneManager());
        std::string pathToMesh = "Assets/sydney.md2";

        c1->Initialize(nullptr);
        if (t1->Initialize(0) && d1->Initialize(&pathToMesh) && a1->Initialize(d1)) {
            a1->AddAnimation("idle", {0, 13, 15});
            a1->PlayAnimation("idle");
        }
        e2.AddComponent(d1, Drawable::Id);
        e2.AddComponent(t1, Transform::Id);
        //e2.AddComponent(a1, Animator::Id);
        e2.AddComponent(c1, Collider::Id);
        gameManager->GetEntityManager()->AddEntity(e2);
    }
    {
        Entity e3("Wall");
        Drawable* d2 = new Drawable(gameManager->GetSceneManager());
        Transform* t2 = new Transform();
        Collider* c2 = new Collider();
        std::string pathToMesh = "Assets/wall.md3";

        if (d2->Initialize(&pathToMesh) && t2->Initialize(nullptr) && c2->Initialize(nullptr))
        {

        }

        t2->SetPosition({ 20, 0, 0 });
        e3.AddComponent(d2, d2->Id);
        e3.AddComponent(t2, t2->Id);
        e3.AddComponent(c2, c2->Id);
        gameManager->GetEntityManager()->AddEntity(e3);
    }
    // Add Camera to Scene.
    gameManager->GetSceneManager()->addCameraSceneNode(0, Vector3f(0, 5, -50), { 0, 0, 0 });
}