#pragma once

#include <unordered_map>
#include <Core.hpp>
#include <ECS/Component.h>

class Entity
{
	using ComponentMap = std::unordered_map<ComponentId, Shared<Component>, std::hash<ComponentId>, std::equal_to<ComponentId>>;

	public:
		explicit Entity();

	public:
		void AddComponent(Shared<Component> component, const ComponentId& componentId);
		void RemoveComponent(ComponentId componentId);

	public:
		const EntityId &GetId() const;
		const ComponentMap &GetComponents() const;

		template<class TComponent>
		TComponent* GetComponent() const
		{
			auto& find = m_Components.find(TComponent::Id);

			if (find != m_Components.end())
				return static_cast<TComponent*>(find->second.get());
			return nullptr;
		}

	private:
		EntityId m_Id;
		ComponentMap m_Components;
};