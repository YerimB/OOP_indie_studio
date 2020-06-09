/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** GameManager
*/

#pragma once

#include <Core.hpp>

#include <Scenes/Scene.hpp>
#include <ECS/EntityManager.h>
#include <InputManager/InputManager.hpp>

class GameManager
{
	public:
		GameManager();
		~GameManager();

	public:
		void Initialize();
		void LoadScene(const Scene::SceneID &sceneID);

	public:
		Texture *LoadTexture(const std::string &path);

	public:
		irr::IrrlichtDevice* GetDevice() const;
		irr::video::IVideoDriver* GetVideoDriver() const;
		irr::gui::IGUIEnvironment* GetGuiEnvironment() const;
		irr::scene::ISceneManager* GetSceneManager() const;
		EntityManager* GetEntityManager() const;
		InputManager* GetInputManager() const;

	private:
		irr::IrrlichtDevice* m_Device;
		irr::video::IVideoDriver* m_VideoDriver;
		irr::gui::IGUIEnvironment* m_GuiEnvironment;
		irr::scene::ISceneManager* m_SceneManager;
		Shared<EntityManager> m_EntityManager;
		Unique<InputManager> m_InputManager;
		std::vector<Scene> m_Scenes;
};