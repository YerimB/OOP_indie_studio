#include <Core.hpp>
#include <GameManager.h>
#include <Scenes/MenuScene.hpp>
#include <Scenes/GameScene.hpp>
#include <Scenes/LunchGame.hpp>

int main()
{
    Unique<GameManager> gameManager = CreateUnique<GameManager>();
    MenuScene menu;
    LunchGame luncher;
    GameScene game;

    gameManager->Initialize();
    gameManager->AddScene(&menu);
    gameManager->AddScene(&luncher);
    gameManager->AddScene(&game);

    gameManager->ProgramLoop();
	return 0;
}