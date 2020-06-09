#include <Scenes/GameScene.hpp>
#include <GameManager.h>

// Systems
#include <ECS/System/ButtonSystem.h>

// Components
#include <Components/Transform.h>

void changeSceneToMenu(GameManager* gameManager)
{
	gameManager->m_globalVars.sceneChanged = true;
	gameManager->m_globalVars.newScene = Scene::MENU;
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

        // Add
        gameManager->GetEntityManager()->AddSystem(std::move(buttonSys));
    }

    // Load Entities & Components
	{ // Test button
        // Create components and entity
        Button* b1 = new Button(gameManager->GetGuiEnvironment());
        Entity e1;

        // Initialize component and set attributes then add it to entity
        if (b1->Initialize(nullptr)) {
            b1->SetButtonID(Button::ButtonID::QUIT);
            b1->SetTexture(gameManager->LoadTexture("Assets/sand.png"));
            b1->SetText("Totorina");
            b1->SetPosition({ 500, 200 });
            b1->SetOnPress(changeSceneToMenu);
            e1.AddComponent(std::move(b1), Button::Id);
        }
        // When done, add entity to the entity manager.
        gameManager->GetEntityManager()->AddEntity(e1);
    }
    // Add Camera to Scene.
    gameManager->GetSceneManager()->addCameraSceneNode(0, Vector3f(0, 5, -10), { 0, 0, 0 });
}