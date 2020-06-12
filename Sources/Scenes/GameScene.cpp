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

void GameScene::LoadSystems(GameManager *gm)
{
    // Create
    ButtonSystem* buttonSys = new ButtonSystem(gm->GetEntityManager());
    ImageSystem* imageSys = new ImageSystem(gm->GetEntityManager());
    TextSystem* textSys = new TextSystem(gm->GetEntityManager());
    RenderSystem* renderSys = new RenderSystem(gm->GetEntityManager());

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

    {
        Entity e2("AnimatedCharacter");
        Drawable* d1 = new Drawable(gm->GetSceneManager());
        Transform* t1 = new Transform();
        Animator* a1 = new Animator(gm->GetSceneManager());
        Collider* c1 = new Collider();

        if (t1->Initialize(0) && d1->Initialize(&pathToMesh) && a1->Initialize(d1) && c1->Initialize(nullptr)) {
            a1->AddAnimation("idle", {0, 13, 15});
            a1->PlayAnimation("idle");
            e2.AddComponent(d1, Drawable::Id);
            e2.AddComponent(t1, Transform::Id);
            //e2.AddComponent(a1, Animator::Id);
            e2.AddComponent(c1, Collider::Id);
            gm->GetEntityManager()->AddEntity(e2);
        }

        e2.AddComponent(d1, Drawable::Id);
        e2.AddComponent(t1, Transform::Id);
        e2.AddComponent(a1, Animator::Id);
        e2.AddComponent(c1, Collider::Id);
        gameManager->GetEntityManager()->AddEntity(e2);
    }

    // Add Camera to Scene.
    gameManager->GetSceneManager()->addCameraSceneNode(0, Vector3f(0, 100, 0), { 0, 0, 0 });
}