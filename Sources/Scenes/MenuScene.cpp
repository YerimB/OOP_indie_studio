#include <Scenes/MenuScene.hpp>
#include <ECS/System/ButtonSystem.h>
#include <Components/Transform.h>
#include <GameManager.h>

void printTotorina(void)
{
    std::cout << "Totorina" << std::endl;
}

MenuScene::MenuScene() : Scene(Scene::MENU)
{
}

MenuScene::~MenuScene()
{
}

void MenuScene::Load(GameManager* gameManager)
{
    gameManager->GetGuiEnvironment()->clear();
    gameManager->GetSceneManager()->clear();

	// Load Entities, Components & Systems
    ButtonSystem* buttonSys = new ButtonSystem(gameManager->GetEntityManager());

    // Components
    Button* b1 = new Button(gameManager->GetGuiEnvironment());

    // Entities
    Entity e1;

    if (b1->Initialize(nullptr)) {
        b1->SetButtonID(Button::ButtonID::PLAY);
        b1->SetTexture(gameManager->LoadTexture("Assets/block.png"));
        b1->SetText("Totorina");
        b1->SetPosition({ 500, 200 });
        b1->SetOnPress(printTotorina);
        e1.AddComponent(std::move(b1), Button::Id);
    }

    buttonSys->OnEntityCreated(e1);
    gameManager->GetEntityManager()->AddSystem(std::move(buttonSys));
    gameManager->GetEntityManager()->AddEntity(e1);
    gameManager->GetSceneManager()->addCameraSceneNode(0, Vector3f(0, 5, -10), { 0, 0, 0 });
}