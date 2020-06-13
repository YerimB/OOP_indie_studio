#pragma once

#include <unordered_map>
#include <algorithm>
#include <Irrlicht/irrlicht.h>
#include <Core.hpp>
#include <ECS/Entity.h>
#include <ECS/Component.h>
#include <ECS/System/System.h>
#include <InputManager/InputManager.hpp>

class EntityManager
{
	public:
		EntityManager(irr::scene::ISceneManager* manager, irr::gui::IGUIEnvironment* env, InputManager* im, GameManager* gameManager);
		~EntityManager();
		EntityManager(const EntityManager&) = delete;
		EntityManager(EntityManager&&) = delete;
		EntityManager& operator=(const EntityManager&) = delete;
		EntityManager& operator=(EntityManager&&) = delete;

	public:
		bool Initialize();
		void Update();

	public:
		void AddEntity(const Entity& entity);
		void RemoveEntity(const Entity& entity);
		void AddSystem(BaseSystem* system);
		void RemoveSystem(BaseSystem* system);
		void ClearEntities();
		void ClearComponents();
		void ClearSystems();
		void ClearAll();
		Entity& GetEntity(const std::string& name);
		irr::scene::ISceneManager* GetSceneManager() const { return m_SceneManager; }
		irr::gui::IGUIEnvironment* GetGuiEnvironment() const { return m_GuiEnvironment; }
		InputManager* GetInputManager() const { return m_InputManager; }
		GameManager* GetGameManager() const { return m_GameManager; }

	private:
		std::unordered_map<EntityId, Entity> m_Entities;
		std::vector<std::vector<Shared<Component>>> m_Components;
		std::vector<BaseSystem*> m_Systems;
		irr::scene::ISceneManager* m_SceneManager;
		irr::gui::IGUIEnvironment* m_GuiEnvironment;
		InputManager* m_InputManager;
		GameManager* m_GameManager;
};