#pragma once

#include <unordered_map>
#include <Core.hpp>
#include <ECS/Component.h>

class Entity
{
	using ComponentMap = std::unordered_map<ComponentId, Shared<Component>>;

	public:
		explicit Entity();

	public:
		void AddComponent(Shared<Component> component);
		void AddComponent(Shared<Component> component, const ComponentId& componentId);
		void RemoveComponent(Shared<Component> component);
		void RemoveComponent(ComponentId componentId);

	public:
		const EntityId &GetId() const;
		const ComponentMap &GetComponents() const;

		template<class TComponent>
		TComponent* GetComponent() const
		{
			auto find = m_Components.find(TComponent::Id);

			if (find != m_Components.end())
				return dynamic_cast<TComponent *>(find->second.get());
			return nullptr;
		}

	private:
		EntityId m_Id;
		ComponentMap m_Components;
};