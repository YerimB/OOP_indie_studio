
#pragma once

#include <string>
#include <Core.hpp>

class Component
{
public:
	virtual ~Component() = default;

public:
	virtual bool Initialize() = 0;
	virtual void Update() = 0;

public:
	const ComponentId& GetId() const;
	const std::size_t& GetIndex() const;

private:
	ComponentId m_Id;
	std::size_t m_Index;
};