#include <Scenes/GameScene.hpp>
#include <GameManager.h>

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

        // Add
        gameManager->GetEntityManager()->AddSystem(std::move(buttonSys));
        gameManager->GetEntityManager()->AddSystem(std::move(imageSys));
        gameManager->GetEntityManager()->AddSystem(std::move(textSys));
        gameManager->GetEntityManager()->AddSystem(std::move(renderSys));
    }

    // Load Entities & Components
	{ // Back to menu button
        // Create components and entity
        Entity e1;
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
        Entity e2;
        Drawable* d1 = new Drawable(gameManager->GetSceneManager());
        Transform* t1 = new Transform();
        std::string pathToMesh = "Assets/bomberman_m.obj";

        if (t1->Initialize(0) and d1->Initialize(&pathToMesh)) {
            e2.AddComponent(d1, Drawable::Id);
            e2.AddComponent(t1, Transform::Id);
        }
        gameManager->GetEntityManager()->AddEntity(e2);
    }
    // Add Camera to Scene.
    gameManager->GetSceneManager()->addCameraSceneNode(0, Vector3f(0, 5, -10), { 0, 0, 0 });
}