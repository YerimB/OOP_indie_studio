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
    gameManager->GetSceneManager()->addCameraSceneNode(0, Vector3f(0, 5, -10), { 0, 0, 0 });

    gameManager->ProgramLoop();
	return 0;
}