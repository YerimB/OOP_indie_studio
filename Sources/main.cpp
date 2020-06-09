/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** main
*/

#include <Core.hpp>
#include <GameManager.h>
#include <Scenes/MenuScene.hpp>


int main()
{
    Unique<GameManager> gameManager = CreateUnique<GameManager>();
    MenuScene scene;

    gameManager->Initialize();
    gameManager->AddScene(&scene);

    gameManager->ProgramLoop();
	return 0;
}