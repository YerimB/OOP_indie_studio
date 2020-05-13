#pragma once

#include <cstddef>
#include <mutex>
#include <condition_variable>
#include <vector>
#include <Thread/Thread.hpp>
#include <Thread/ThreadPoolExpcetion.hpp>
#include <Core.hpp>

class ThreadPool
{
	public:
		enum class State
		{
			Active,
			Waiting,
			Dead
		};

	public:
		ThreadPool(const std::size_t& size);
		~ThreadPool();

	public:
		void StartAll();

	public:
		void AddThread(Thread& thread);
		void AddThread(Thread* thread);
		void AddThread(Unique<Thread>& thread);
		void RemoveThread(const std::string& name);
		void RemoveThread(const unsigned int& id);

	private:
		std::size_t m_ThreadCount;
		std::vector<Unique<Thread>> m_Threads;
		std::mutex m_Mutex;
		std::condition_variable m_ConditionVariable;
		State m_State;
};