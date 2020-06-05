#pragma once

#include <unordered_map>
#include <Core.hpp>
#include <ECS/Entity.h>
#include <ECS/Component.h>
#include <ECS/System.h>

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
		void AddEntity(const EntityId& entityId);
		void AddEntity(const Entity& entity);
		void RemoveEntity(const EntityId& entityId);
		void RemoveEntity(const Entity& entity);

	private:
		std::unordered_map<EntityId, Entity> m_Entities;
		std::vector<std::vector<Shared<Component>>> m_Components;
		std::vector<System> m_Systems;
};