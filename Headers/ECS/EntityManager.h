#pragma once

#include <unordered_map>
#include <algorithm>
#include <Irrlicht/irrlicht.h>
#include <Core.hpp>
#include <ECS/Entity.h>
#include <ECS/Component.h>
#include <ECS/System/System.h>

class EntityManager
{
	public:
		EntityManager();
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
		void AddSystem(const BaseSystem* system);
		void RemoveSystem(const BaseSystem* system);
		void ClearEntities();
		void ClearComponents();
		void ClearSystems();
		void ClearAll();
		irr::scene::ISceneManager* GetSceneManager() const { return m_SceneManager; }

	private:
		std::unordered_map<EntityId, Entity> m_Entities;
		std::vector<std::vector<Shared<Component>>> m_Components;
		std::vector<BaseSystem*> m_Systems;
		irr::scene::ISceneManager* m_SceneManager;
};