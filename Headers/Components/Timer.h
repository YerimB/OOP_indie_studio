#pragma once

#include <chrono>
#include <ECS/Component.h>

class Timer : public Component
{
	public:
		Timer() = default;
		~Timer() = default;

	public:
		bool Initialize(void* args) override final;

	public:
		void Reset();
		void Update(const float& deltaTime, GameManager* gameManager) override final;

	public:
		void SetDuration(const float& duration);
		const float& GetDuration() const;

	private:
		float m_Duration;
		float m_InitialValue;
};