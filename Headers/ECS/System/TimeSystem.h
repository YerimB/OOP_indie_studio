#pragma once

#include <ECS/System/System.h>
#include <ECS/EntityManager.h>
#include <Components/Timer.h>

class TimeSystem : public System<Timer>
{
	using BaseType = System<Timer>;

    public:
        TimeSystem(EntityManager* pEntityManager);

    public:
        virtual void Update(const double& deltaTime) override;
};