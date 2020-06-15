#include <ECS/System/TimeSystem.h>
#include <ECS/EntityManager.h>

TimeSystem::TimeSystem(EntityManager* pEntityManager) : BaseType(pEntityManager)
{}

void TimeSystem::Update(const double& deltaTime)
{
	for (auto compTupl : _components)
	{
		Timer* timer = std::get<Timer*>(compTupl);

		if (timer != nullptr)
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