#include <ECS/Time.h>

Time::Time()
{
	m_LastTime = std::chrono::high_resolution_clock::now();

	GetDeltaTime();
}

const std::chrono::duration<double>& Time::GetDeltaTime()
{
	auto now = std::chrono::high_resolution_clock::now();
	m_DeltaTime = now - m_LastTime;
	m_LastTime = now;

	return m_DeltaTime;
}