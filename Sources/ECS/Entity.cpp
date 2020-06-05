#include <ECS/Entity.h>

Entity::Entity(const EntityId& id)
{
	m_Id = id;
}

void Entity::AddComponent(Component* component)
{
	m_Components.emplace(std::make_pair(component->GetId(), component));
}

void Entity::AddComponent(Component* component, const ComponentId& componentId)
{
	m_Components.emplace(std::make_pair(componentId, component));
}

void Entity::RemoveComponent(Component* component)
{
	m_Components.erase(component->GetId());
}

void Entity::RemoveComponent(ComponentId componentId)
{
	m_Components.erase(componentId);
}

const EntityId& Entity::GetId() const
{
	return m_Id;
}