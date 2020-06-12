/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** GameManager
*/

#pragma once

#include <Core.hpp>
#include <ECS/EntityManager.h>
#include <InputManager/InputManager.hpp>
#include <SoundManager.h>
#include <Scenes/Scene.hpp>

enum SocketMode {
	NONE = (-1),
	LOCAL,
};

typedef struct GameGlobalVariables_s
{
	// Has scene been changed ?
	bool sceneChanged = false;
	// If scene has been changed, which one is to load ?
	Scene::SceneID newScene = Scene::UNDEFINED;

	// Current connection mode to the game.
	SocketMode currentSocketMode = SocketMode::NONE;
	// Add vars if needed.
} GameVars_t;

class GameManager
{
	public:
		GameManager();
		~GameManager();

	public:

	public:
		void Initialize();
		void AddScene(Scene* scene);
		void RemoveScene(const Scene::SceneID& sceneId);
		void ProgramLoop(void);
	
	public:
		void LoadScene(const Scene::SceneID &sceneID);

	public:
		Texture *LoadTexture(const std::string &path);

	public: // Getters
		irr::IrrlichtDevice* GetDevice() const;
		irr::video::IVideoDriver* GetVideoDriver() const;
		irr::gui::IGUIEnvironment* GetGuiEnvironment() const;
		irr::scene::ISceneManager* GetSceneManager() const;
		EntityManager* GetEntityManager() const;
		InputManager* GetInputManager() const;
		SoundManager* GetSoundManager() const;
	
	public: // Setters
		void SetSceneChange(const bool &state);
		void SetNextScene(const Scene::SceneID &sceneID);
		void SetSocketMode(const SocketMode &);

	private: // Irrlicht mandatory
		irr::IrrlichtDevice* m_Device;
		irr::video::IVideoDriver* m_VideoDriver;
		irr::gui::IGUIEnvironment* m_GuiEnvironment;
		irr::scene::ISceneManager* m_SceneManager;
	
	private: // ECS
		Shared<EntityManager> m_EntityManager;
		Unique<InputManager> m_InputManager;
		Unique<SoundManager> m_SoundManager;
	
	private: // Game management
		GameVars_t m_globalVars;
		std::unordered_map<Scene::SceneID, Scene*> m_Scenes;
};
