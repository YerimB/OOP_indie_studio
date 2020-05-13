#include <Thread/ThreadPool.hpp>

ThreadPool::ThreadPool(const std::size_t& size)
{
	m_ThreadCount = size;
	m_Threads = std::vector<Unique<Thread>>(m_ThreadCount);
	m_State = State::Waiting;

	for (std::size_t i = 0; i < m_ThreadCount; i += 1)
		m_Threads.emplace_back(CreateUnique<Thread>(static_cast<unsigned int>(i)));
}

ThreadPool::~ThreadPool()
{
	m_State = State::Dead;
	m_ConditionVariable.notify_all();

	for (auto& thread : m_Threads)
		thread->Wait();
}

void ThreadPool::AddThread(Thread& thread)
{
	if (m_State == State::Active)
		throw ThreadPoolException("Cannot add a Thread while the ThreadPool is running.");

	m_Threads.emplace_back(Unique<Thread>(&thread));
	m_ThreadCount += 1;
}

void ThreadPool::AddThread(Thread* thread)
{
	if (m_State == State::Active)
		throw ThreadPoolException("Cannot add a Thread while the ThreadPool is running.");

	m_Threads.emplace_back(Unique<Thread>(thread));
	m_ThreadCount += 1;
}

void ThreadPool::AddThread(Unique<Thread>& thread)
{
	if (m_State == State::Active)
		throw ThreadPoolException("Cannot add a Thread while the ThreadPool is running.");

	m_Threads.emplace_back(std::move(thread));
	m_ThreadCount += 1;
}

void ThreadPool::RemoveThread(const unsigned int& id)
{
	if (m_State == State::Active)
		throw ThreadPoolException("Cannot remove a Thread while the ThreadPool is running.");

	auto it = m_Threads.begin();
	while (it != m_Threads.end()) {
		if ((*it)->GetId() == id)
			break;
		it += 1;
	}

	if (it != m_Threads.end()) {
		m_Threads.erase(it);
		m_ThreadCount -= 1;
	}
}

void ThreadPool::RemoveThread(const std::string& name)
{
	if (m_State == State::Active)
		throw ThreadPoolException("Cannot remove a Thread while the ThreadPool is running.");

	auto it = m_Threads.begin();
	while (it != m_Threads.end()) {
		if ((*it)->GetName() == name)
			break;
		it += 1;
	}

	if (it != m_Threads.end()) {
		m_Threads.erase(it);
		m_ThreadCount -= 1;
	}
}