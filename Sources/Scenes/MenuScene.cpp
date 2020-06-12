#include <Scenes/MenuScene.hpp>
#include <GameManager.h>

// Systems
#include <ECS/System/ButtonSystem.h>

// Components
#include <Components/Transform.h>

static void changeSceneToGame(GameManager* gameManager)
{
	gameManager->SetSceneChange(true);
	gameManager->SetNextScene(Scene::GAME);
}

MenuScene::MenuScene() : Scene(Scene::MENU)
{
}

MenuScene::~MenuScene()
{
}

void MenuScene::LoadSystems(GameManager *gm)
{
    // Create
    ButtonSystem* buttonSys = new ButtonSystem(gm->GetEntityManager());

    // Add
    gm->GetEntityManager()->AddSystem(std::move(buttonSys));
}

void MenuScene::LoadAssets(GameManager *gm)
{

}

// Load Entities & Components
void MenuScene::LoadElements(GameManager *gm)
{
	{ // Test button
        // Create components and entity
        Button* b1 = new Button(gm->GetGuiEnvironment());
        Entity e1("Block");

        // Initialize component and set attributes then add it to entity
        if (b1->Initialize(nullptr)) {
            b1->SetButtonID(Button::ButtonID::PLAY);
            b1->SetTexture(gm->LoadTexture("Assets/block.png"));
            b1->SetText("Totorina");
            b1->SetPosition({ 500, 200 });
            b1->SetOnPress(changeSceneToGame);
            e1.AddComponent(std::move(b1), Button::Id);
        }
        // When done, add entity to the entity manager.
        gm->GetEntityManager()->AddEntity(e1);
    }
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

void MenuScene::Update(GameManager *gameManager)
{

}

void MenuScene::Unload(void)
{

}