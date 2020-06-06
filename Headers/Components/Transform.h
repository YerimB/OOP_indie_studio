#pragma once

#include <ECS/Component.h>
#include <Core.hpp>

class Transform : public Component
{
	public:
		static constexpr ComponentId Id = "Transform"_hash;

	public:
		Transform(const Vector3f& position = { 0, 0, 0 }, const float& rotation = 0, const float& scale = 1);

	public:
		bool Initialize(void *args) override final;
		void Update(const float& deltaTime) override final;

	public:
		void SetPosition(const Vector3f& position);
		void SetRotation(const float& rotation);
		void SetScale(const float& scale);

	public:
		const Vector3f& GetPosition() const;
		const float& GetRotation() const;
		const float& GetScale() const;

	private:
		Vector3f m_Position;
		float m_Rotation;
		float m_Scale;
};