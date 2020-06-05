#include <ECS/Entity.h>

Entity::Entity(const EntityId& id)
{
	m_Id = id;
}

const EntityId& Entity::GetId() const
{
	return m_Id;
}