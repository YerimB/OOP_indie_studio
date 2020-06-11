/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Entity
*/

#pragma once

#include <unordered_map>
#include <Core.hpp>
#include <ECS/Component.h>

class Entity
{
	using ComponentMap = std::unordered_map<ComponentId, Component*, std::hash<ComponentId>, std::equal_to<ComponentId>>;

	public:
		explicit Entity();

	public:
		void AddComponent(Component* component, const ComponentId& componentId);
		void RemoveComponent(ComponentId componentId);

	public:
		const EntityId &GetId() const;
		const ComponentMap &GetComponents() const;

		template<class TComponent>
		TComponent* GetComponent() const
		{
			auto findIt = m_Components.find(TComponent::Id);

			if (findIt != m_Components.end())
				return static_cast<TComponent*>(findIt->second);
			return nullptr;
		}

	private:
		EntityId m_Id;
		ComponentMap m_Components;
};