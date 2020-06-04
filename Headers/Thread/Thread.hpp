#pragma once

#include <thread>
#include <string>
#include <atomic>
#include <iostream>
#include <unordered_map>
#include <sstream>

class Thread
{
	public:
		enum class State
		{
			Active,
			Wait,
			Dead
		};

	public:
		Thread();
		Thread(const unsigned int& id);
		Thread(const unsigned int& id, const std::string& name);
		~Thread();

	public:
		template<typename T, typename ... TArgs>
		void Start(T&& function, TArgs&& ... args);
		void Status() const;
		void Wait();

	public:
		void SetState(const State& state);
		void SetName(const std::string& name);
		void SetId(const unsigned int& id);

	public:
		const State& GetState() const;
		const std::string& GetName() const;
		const unsigned int& GetId() const;

	private:
		void Init(const unsigned int& id, const std::string& name);

	private:
		const std::unordered_map<State, std::string> m_StateMap = {
			{ State::Active, "Active" },
			{ State::Wait, "Wait" },
			{ State::Dead, "Dead" }
		};

	private:
		unsigned int m_Id;
		std::string m_Name;
		std::atomic<State> m_State;
		std::thread m_Thread;
};

#include "Thread.inl"