#pragma once

#include <mutex>
#include <queue>

template<typename T>
class SafeQueue
{
	public:
		SafeQueue() = default;
		~SafeQueue() = default;

	public:
		void Pop();
		bool TryPop(T& out);
		T Front();
		T Back();
		void Push(const T& value);
		const unsigned int& Size();
		bool Empty();

	private:
		std::queue<T> m_Queue;
		std::mutex m_Mutex;
};

#include <SafeContainer/SafeQueue.inl>