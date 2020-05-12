#pragma once

#include "Thread.h"

template<typename T, typename ... TArgs>
void Thread::Start(const T&& function, TArgs&& ... args)
{
	SetState(State::Active);
	m_Thread = std::thread(function, std::forward<TArgs>(args)...);
}