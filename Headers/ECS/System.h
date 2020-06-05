#pragma once

#include <unordered_map>
#include <Core.hpp>
#include <ECS/Entity.h>

class System
{
public:
	virtual ~System() = default;

public:
	virtual bool Initialize() = 0;
	virtual void Update() = 0;
};