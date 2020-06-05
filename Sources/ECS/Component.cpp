#include <ECS/Component.h>

const ComponentId& Component::GetId() const
{
	return m_Id;
}

const std::size_t& Component::GetIndex() const
{
	return m_Index;
}