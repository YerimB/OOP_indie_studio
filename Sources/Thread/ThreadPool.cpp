#include <Thread/ThreadPool.hpp>

ThreadPool::ThreadPool()
{
	m_ThreadCount = 0;
	m_State = State::Waiting;
}

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

void ThreadPool::StartAll()
{
	for (auto& thread : m_Threads)
		thread->Start(&ThreadPool::StartThread, this);
}

void ThreadPool::StopAll()
{
	m_State = State::Waiting;
	m_ConditionVariable.notify_all();

	for (auto& thread : m_Threads)
		thread->Wait();
}

void ThreadPool::StartThread()
{
	while (m_State != State::Dead && m_State != State::Waiting) {
		{
			std::unique_lock<std::mutex> u_lock(m_Mutex);

			m_ConditionVariable.wait(u_lock, [this]() {
				return !m_Tasks.Empty() || m_State == State::Dead || m_State == State::Waiting;
			});

			if (m_State == State::Dead || m_State == State::Waiting)
				break;

			ITask* task = nullptr;
			if (m_Tasks.TryPop(task)) {
				if (task != nullptr)
					task->Run();
			}
		}

		std::this_thread::sleep_for(std::chrono::milliseconds(10));
	}
}

void ThreadPool::AddTask(ITask& task)
{
	m_Tasks.Push(&task);
}

void ThreadPool::AddTask(ITask* task)
{
	m_Tasks.Push(task);
}

void ThreadPool::AddTask(Unique<ITask>& task)
{
	m_Tasks.Push(task.get());
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