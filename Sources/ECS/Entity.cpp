#include <ECS/Entity.h>

Entity::Entity()
{
	m_Id = __COUNTER__;
}

void Entity::AddComponent(Shared<Component> component, const ComponentId& componentId)
{
	component->SetEntityId(m_Id);
	m_Components.emplace(componentId, component);
}

void Entity::RemoveComponent(ComponentId componentId)
{
	m_Components.erase(componentId);
}

const EntityId& Entity::GetId() const
{
	return m_Id;
}

const Entity::ComponentMap &Entity::GetComponents() const
{
	return m_Components;
}
