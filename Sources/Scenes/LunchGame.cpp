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

void LunchGame::Load(GameManager* gameManager)
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
            b1->SetText("Go!");
            b1->SetPosition({ 500, 600 });
            b1->SetSize(300, 100);
            b1->SetTextureToFit(true);
            b1->SetOnPress(changeSceneToGame);
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

        if (t1->Initialize(0) && d1->Initialize(&pathToMesh)) {
            e2.AddComponent(d1, Drawable::Id);
            e2.AddComponent(t1, Transform::Id);
            t1->SetRotation(Vector3f(0, 30, 0));
            t1->SetScale(Vector3f(2, 2, 2));
            t1->SetPosition(Vector3f(-10, -2, 0));
        }
        gameManager->GetEntityManager()->AddEntity(e2);
    }

    {
        Entity e3;
        Drawable* d2 = new Drawable(gameManager->GetSceneManager());
        Transform* t2 = new Transform();
        std::string pathToMesh = "Assets/bomberman_m.obj";

        if (t2->Initialize(0) && d2->Initialize(&pathToMesh)) {
            e3.AddComponent(d2, Drawable::Id);
            e3.AddComponent(t2, Transform::Id);
            t2->SetRotation(Vector3f(0, 10, 0));
            t2->SetScale(Vector3f(2, 2, 2));
            t2->SetPosition(Vector3f(-3,-2, 0));
        }
        gameManager->GetEntityManager()->AddEntity(e3);
    }

    {
        Entity e4;
        Drawable* d3 = new Drawable(gameManager->GetSceneManager());
        Transform* t3 = new Transform();
        std::string pathToMesh = "Assets/bomberman_m.obj";

        if (t3->Initialize(0) && d3->Initialize(&pathToMesh)) {
            e4.AddComponent(d3, Drawable::Id);
            e4.AddComponent(t3, Transform::Id);
            t3->SetRotation(Vector3f(0, -10, 0));
            t3->SetPosition(Vector3f(3, -2, 0));
            t3->SetScale(Vector3f(2, 2, 2));
        }
        gameManager->GetEntityManager()->AddEntity(e4);
    }

    {
        Entity e5;
        Drawable* d4 = new Drawable(gameManager->GetSceneManager());
        Transform* t4 = new Transform();
        std::string pathToMesh = "Assets/bomberman_m2.obj";

        if (t4->Initialize(0) && d4->Initialize(&pathToMesh)) {
            e5.AddComponent(d4, Drawable::Id);
            e5.AddComponent(t4, Transform::Id);
            t4->SetScale(Vector3f(2, 2, 2));
            t4->SetRotation(Vector3f(0, -30, 0));
            t4->SetPosition(Vector3f(10,-2, 0));
        }
        gameManager->GetEntityManager()->AddEntity(e5);
    }


    {
        Entity e6;
        Drawable* d5 = new Drawable(gameManager->GetSceneManager());
        Transform* t5 = new Transform();
        std::string pathToMesh = "Assets/Crate1.obj";

        Button* b3 = new Button(gameManager->GetGuiEnvironment());

        // Initialize component and set attributes then add it to entity
        if (b3->Initialize(nullptr)) {
            b3->SetButtonID(Button::ButtonID::UNDEFINED);
            b3->SetTexture(gameManager->LoadTexture("Assets/right_arrow.png"));
            // b3->SetText("Change Character");
            b3->SetPosition({ 800, 100 });
            b3->SetSize(100, 100);
            b3->SetTextureToFit(true);
            b3->SetOnPress(changeCharacter);
            e6.AddComponent(std::move(b3), Button::Id);
        }
        Button* b4 = new Button(gameManager->GetGuiEnvironment());

        // Initialize component and set attributes then add it to entity
        if (b4->Initialize(nullptr)) {
            b4->SetButtonID(Button::ButtonID::UNDEFINED);
            b4->SetTexture(gameManager->LoadTexture("Assets/left_arrow.png"));
            // b4->SetText("Chang");
            b4->SetPosition({ 400, 100 });
            b4->SetSize(100, 100);
            b4->SetTextureToFit(true);
            b4->SetOnPress(changeCharacter);
            e6.AddComponent(std::move(b4), Button::Id);
        }

        if (t5->Initialize(0) && d5->Initialize(&pathToMesh)) {
            e6.AddComponent(d5, Drawable::Id);
            e6.AddComponent(t5, Transform::Id);
            // t5->SetScale(Vector3f(2, 2, 2));
            t5->SetRotation(Vector3f(0, -30, 0));
            t5->SetPosition(Vector3f(0, 4, 0));
        }
        gameManager->GetEntityManager()->AddEntity(e6);
    }

    { // Back to menu button
        // Create components and entity
        Entity e7;
        Button* b2 = new Button(gameManager->GetGuiEnvironment());

        // Initialize component and set attributes then add it to entity
        if (b2->Initialize(nullptr)) {
            b2->SetButtonID(Button::ButtonID::UNDEFINED);
            b2->SetTexture(gameManager->LoadTexture("Assets/sand.jpg"));
            b2->SetText("Change Character");
            b2->SetPosition({ 100, 100 });
            b2->SetSize(100, 100);
            b2->SetTextureToFit(true);
            b2->SetOnPress(changeCharacter);
            e7.AddComponent(std::move(b2), Button::Id);
        }
        // When done, add entity to the entity manager.
        gameManager->GetEntityManager()->AddEntity(e7);
    }
    // Add Camera to Scene.
    gameManager->GetSceneManager()->addCameraSceneNode(0, Vector3f(0, 0, 10), { 0, 0, 0 });
}