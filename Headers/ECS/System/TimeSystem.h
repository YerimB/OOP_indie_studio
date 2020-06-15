#pragma once

#include <ECS/System/System.h>
#include <Components/Timer.h>

class EntityManager;

class TimeSystem : public System<Timer>
{
	using BaseType = System<Timer>;

    public:
        TimeSystem(EntityManager* pEntityManager);

    public:
        virtual void Update(const double& deltaTime) override;
};