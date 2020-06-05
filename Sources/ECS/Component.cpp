/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Component
*/

#include <ECS/Component.h>

const ComponentId& Component::GetId() const
{
	return m_Id;
}

const EntityId& Component::GetEntityId() const
{
	return m_EntityId;
}

const std::size_t& Component::GetIndex() const
{
	return m_Index;
}

void Component::SetEntityId(const EntityId& entityId)
{
	m_EntityId = entityId;
}
