#include <ECS/Time.h>

Time::Time()
{
	this->m_lastFrameTime = std::chrono::duration_cast<std::chrono::milliseconds>\
    (std::chrono::system_clock::now().time_since_epoch());
}

#include <iostream>
const double Time::GetDeltaTime()
{
    auto nowTime = std::chrono::duration_cast<std::chrono::milliseconds>\
	(std::chrono::system_clock::now().time_since_epoch());
	double deltaTime = float(nowTime.count() - m_lastFrameTime.count()) / 1000.0f;

	this->m_lastFrameTime = nowTime;
	return (deltaTime);
}