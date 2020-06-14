/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** main
*/

#include <Core.hpp>
#include <GameManager.h>
#include <Scenes/MenuScene.hpp>
#include <Scenes/GameScene.hpp>

int main()
{
    Unique<GameManager> gameManager = CreateUnique<GameManager>();
    MenuScene menu;
    std::cout << "lauch" << std::endl;
    GameScene game;

    gameManager->Initialize();
    gameManager->AddScene(&menu);
    gameManager->AddScene(&game);

    gameManager->ProgramLoop();
	return 0;
}