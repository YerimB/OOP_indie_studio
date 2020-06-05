#include <ECS/Entity.h>

Entity::Entity()
{
	m_Id = __COUNTER__;
}

void Entity::AddComponent(Component* component)
{
	component->SetEntityId(m_Id);
	m_Components.emplace(std::make_pair(component->GetId(), component));
}

void Entity::AddComponent(Component* component, const ComponentId& componentId)
{
	component->SetEntityId(m_Id);
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

const std::unordered_map<ComponentId, Component*>& Entity::GetComponents() const
{
	return m_Components;
}
