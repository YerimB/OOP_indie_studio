#include <Scenes/GameScene.hpp>
#include <GameManager.h>

GameScene::GameScene() : Scene(Scene::MENU)
{
}

GameScene::~GameScene()
{
}

void GameScene::Load(GameManager* gameManager)
{
	gameManager->GetGuiEnvironment()->clear();
	gameManager->GetSceneManager()->clear();

	// Load Entities, Components & Systems
}