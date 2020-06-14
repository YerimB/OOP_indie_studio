#include <ECS/System/TimeSystem.h>

TimeSystem::TimeSystem(EntityManager* pEntityManager) : BaseType(pEntityManager)
{}

void TimeSystem::Update(const double& deltaTime)
{
	for (auto compTupl : _components)
	{
		Timer* timer = std::get<Timer*>(compTupl);

		if (timer)
		{
			if (timer->GetDuration() > 0)
			{
				timer->Update(deltaTime, nullptr);
			}
			else
			{
				timer->GetDuration();
			}
		}
	}
}