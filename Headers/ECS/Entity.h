#pragma once

#include <unordered_map>
#include <Core.hpp>
#include <ECS/Component.h>

class Entity
{
	public:
		explicit Entity(const EntityId& id);

	public:
		const EntityId& GetId() const;

	public:
		template<class TComponent>
		TComponent* GetComponent() const
		{
			auto find = m_Components.find(TComponent::Id);
			if (find != m_Components.end())
				return find->second.get();
			return nullptr;
		}

	private:
		EntityId m_Id;
		std::unordered_map<ComponentId, Component*> m_Components;
};