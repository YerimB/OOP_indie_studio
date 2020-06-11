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
		const std::chrono::duration<double>& GetDeltaTime();

	private:
		std::chrono::duration<double> m_DeltaTime;
		std::chrono::high_resolution_clock::time_point m_LastTime;
};