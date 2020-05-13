#pragma once

#include <SafeContainer/SafeQueue.hpp>

template<typename T>
void SafeQueue<T>::Pop()
{
	std::lock_guard<std::mutex> lock(m_Mutex);

	m_Queue.pop();
}

template<typename T>
bool SafeQueue<T>::TryPop(T& out)
{
	std::lock_guard<std::mutex> lock(m_Mutex);

	if (m_Queue.empty())
		return false;

	out = m_Queue.front();
	m_Queue.pop();

	return true;
}

template<typename T>
T SafeQueue<T>::Front()
{
	std::lock_guard<std::mutex> lock(m_Mutex);

	return m_Queue.front();;
}

template<typename T>
T SafeQueue<T>::Back()
{
	std::lock_guard<std::mutex> lock(m_Mutex);

	return m_Queue.back();
}

template<typename T>
void SafeQueue<T>::Push(const T& value)
{
	std::lock_guard<std::mutex> lock(m_Mutex);

	m_Queue.push(value);
}

template<typename T>
const unsigned int& SafeQueue<T>::Size()
{
	std::lock_guard<std::mutex> lock(m_Mutex);

	return m_Queue.size();
}

template<typename T>
bool SafeQueue<T>::Empty()
{
	std::lock_guard<std::mutex> lock(m_Mutex);

	return m_Queue.empty();
}
