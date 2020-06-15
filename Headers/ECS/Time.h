#pragma once

#include <chrono>
#include <Core.hpp>

class Time
{
	public:
		Time();
		Time(const Time&) = delete;
		Time(Time&&) = delete;
		Time& operator=(const Time&) = delete;
		Time& operator=(Time&&) = delete;
		~Time() = default;

	public:
		const double GetDeltaTime();

	private:
		std::chrono::milliseconds m_lastFrameTime;
};