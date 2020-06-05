#pragma once

#include "Thread.hpp"

template<typename T, typename ... TArgs>
void Thread::Start(T&& function, TArgs&& ... args)
{
	SetState(State::Active);
	m_Thread = std::thread(function, std::forward<TArgs>(args)...);
}