/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Entity
*/

#include <ECS/Entity.h>
#include <ECS/Hash.h>

Entity::Entity(const std::string& name)
{
	m_Id = Hash::HashString(name, name.length());
	m_Name = name;
}

void Entity::AddComponent(Component* component, const ComponentId& componentId)
{
	component->SetEntityId(m_Id);
	m_Components.emplace(componentId, component);
}

void Entity::RemoveComponent(ComponentId componentId)
{
	m_Components.erase(componentId);
}

void Entity::SetName(const std::string& name)
{
	m_Name = name;
}

const EntityId& Entity::GetId() const
{
	return m_Id;
}

const Entity::ComponentMap &Entity::GetComponents() const
{
	return m_Components;
}

const std::string& Entity::GetName() const
{
	return m_Name;
}
