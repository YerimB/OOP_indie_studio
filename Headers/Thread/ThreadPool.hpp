#pragma once

#include <condition_variable>
#include <cstddef>
#include <functional>
#include <mutex>
#include <vector>

#include <Core.hpp>
#include <SafeContainer/SafeQueue.hpp>
#include <Thread/ITask.hpp>
#include <Thread/Thread.hpp>
#include <Thread/ThreadPoolExpcetion.hpp>
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
		ThreadPool();
		ThreadPool(const std::size_t& size);
		~ThreadPool();

	public:
		void StartAll();
		void StopAll();

	public:
		void AddTask(ITask& task);
		void AddTask(ITask* task);
		void AddTask(Unique<ITask>& task);
		void AddThread(Thread& thread);
		void AddThread(Thread* thread);
		void AddThread(Unique<Thread>& thread);
		void RemoveThread(const std::string& name);
		void RemoveThread(const unsigned int& id);

	private:
		void StartThread();

	private:
		std::size_t m_ThreadCount;
		std::vector<Unique<Thread>> m_Threads;
		std::mutex m_Mutex;
		std::condition_variable m_ConditionVariable;
		SafeQueue<ITask*> m_Tasks;
		State m_State;
};