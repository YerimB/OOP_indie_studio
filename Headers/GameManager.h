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

typedef struct PlayersData_s
{
	bool isActive = false;
	bool hasStatusChanged = false;
	int playerID = 0;
	int characterID = 0;
	bool changedCharacterID = false;
	std::unordered_map<std::string, Binding> bindingsMap;
	Vector2i position = {(-1), (-1)};
} PlayerData_t;

typedef struct GameGlobalVariables_s
{
	bool gameActive = true;

	// Has scene been changed ?
	bool sceneChanged = false;
	// If scene has been changed, which one is to load ?
	Scene::SceneID newScene = Scene::UNDEFINED;

	// Players
	const int maxPlayerNumber = 4;
	int currentPlayerNumber = 0;
	std::array<PlayerData_t, 4> playersData;
	const std::unordered_map<size_t, std::string> meshIDMap = {
		std::pair<size_t, std::string>(1, "Mario"),
		std::pair<size_t, std::string>(2, "Luigi"),
		std::pair<size_t, std::string>(3, "Koopa"),
		std::pair<size_t, std::string>(4, "Star")
	};

	// Map
	size_t mapSize = 0;
	std::vector<std::string> map;

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
		Texture *LoadTexture(const std::string &path);

	public:
		void waitBeforeNextFrame(const size_t &fps);

	public: // Getters
		irr::IrrlichtDevice* GetDevice() const;
		irr::video::IVideoDriver* GetVideoDriver() const;
		irr::gui::IGUIEnvironment* GetGuiEnvironment() const;
		irr::scene::ISceneManager* GetSceneManager() const;
		EntityManager* GetEntityManager() const;
		InputManager* GetInputManager() const;
		SoundManager* GetSoundManager() const;
		Scene* GetCurrentScene() const;
		GameVars_t m_globalVars;
	
	public: // Setters
		void SetSceneChange(const bool &state);
		void SetNextScene(const Scene::SceneID &sceneID);

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
		std::unordered_map<Scene::SceneID, Scene*> m_Scenes;
		Scene::SceneID m_CurrentSceneID = Scene::SceneID::UNDEFINED;
		std::chrono::milliseconds m_lastFrameTime;
};
