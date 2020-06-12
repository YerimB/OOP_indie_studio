#include <Components/Timer.h>

bool Timer::Initialize(void* countdown)
{
	if (!countdown)
		return false;

	m_Duration = *static_cast<float*>(countdown);
	m_InitialValue = m_Duration;
	return true;
}

void Timer::Reset()
{
	m_Duration = m_InitialValue;
}

void Timer::Update(const float& deltaTime, GameManager*)
{
	m_Duration -= deltaTime;

	if (m_Duration <= 0)
	{
		// Callback function?
		m_Duration = 0;
	}
}

void Timer::SetDuration(const float& duration)
{
	m_Duration = duration < 0 ? 0 : duration;
}

const float& Timer::GetDuration() const
{
	return m_Duration;
}