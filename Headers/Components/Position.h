#pragma once

#include <Core.hpp>
#include <ECS/Component.h>

class Position : public Component
{
	public:
		static constexpr ComponentId Id = __COUNTER__;

	public:
		Position();
		Position(const Vector2f& position);
		~Position() = default;

	public:
		bool Initialize() override final;
		void Update() override final;

	public:
		const Vector2f& GetPosition() const;
		void SetPosition(const Vector2f& position);

	private:
		Vector2f m_Position;
};