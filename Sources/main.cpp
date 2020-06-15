#include <Core.hpp>
#include <GameManager.h>
#include <Scenes/MenuScene.hpp>
#include <Scenes/GameScene.hpp>
#include <Scenes/LunchGame.hpp>
#include <Scenes/VictoryScene.hpp>

int main()
{
    Unique<GameManager> gameManager = CreateUnique<GameManager>();
    MenuScene menu;
    LunchGame luncher;
    GameScene game;
    VictoryScene victory;

    gameManager->Initialize();
    gameManager->AddScene(&menu);
    gameManager->AddScene(&luncher);
    gameManager->AddScene(&game);
    gameManager->AddScene(&victory);

    gameManager->ProgramLoop();
	return 0;
}