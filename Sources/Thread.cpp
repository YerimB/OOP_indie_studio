#include <Thread/Thread.h>

Thread::Thread()
{
	Init(0, std::string("Thread #0"));
}

Thread::Thread(const unsigned int& id)
{
	Init(id, std::string("Thread #" + id));
}

Thread::Thread(const unsigned int& id, const std::string& name)
{
	Init(id, name);
}

Thread::~Thread()
{
	if (m_Thread.joinable())
		m_Thread.join();
}

const Thread::State& Thread::GetState() const
{
	return m_State.load();
}

void Thread::SetState(const Thread::State& state)
{
	if (m_State.load() == state)
		return;

	m_State.store(state);
}

void Thread::Status() const
{
	std::stringstream ss;

	ss << m_Name << ": " << m_StateMap.find(m_State.load())->second << std::endl;
	std::cout << ss.str();

	ss.clear();
}

void Thread::Init(const unsigned int& id, const std::string& name)
{
	m_State = State::Wait;
	m_Id = id;
	m_Name = name;
}