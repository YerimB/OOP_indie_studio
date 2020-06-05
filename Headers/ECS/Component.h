
#pragma once

#include <string>
#include <Core.hpp>

class Component
{
public:
	virtual ~Component() = default;

public:
	virtual bool Initialize(void *args) = 0;
	virtual void Update() = 0;

public:
	const ComponentId& GetId() const;
	const EntityId& GetEntityId() const;
	const std::size_t& GetIndex() const;

public:
	void SetEntityId(const EntityId& entityId);

private:
	EntityId m_EntityId;
	ComponentId m_Id;
	std::size_t m_Index;
};