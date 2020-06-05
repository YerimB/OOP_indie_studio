#pragma once

#include <unordered_map>
#include <Core.hpp>
#include <ECS/Component.h>

class Entity
{
	protected: // Usings...
		using ComponentMap = std::unordered_map<ComponentId, Component*>;

	public:
		explicit Entity();

	public:
		void AddComponent(Component* component);
		void AddComponent(Component* component, const ComponentId& componentId);
		void RemoveComponent(Component* component);
		void RemoveComponent(ComponentId componentId);

	public:
		const EntityId& GetId() const;
		const ComponentMap &GetComponents() const;

		template<class TComponent>
		TComponent* GetComponent() const
		{
			auto find = m_Components.find(TComponent::Id);

			if (find != m_Components.end())
				return dynamic_cast<TComponent*>(find->second);
			return nullptr;
		}

	private:
		EntityId m_Id;
		ComponentMap m_Components;
};