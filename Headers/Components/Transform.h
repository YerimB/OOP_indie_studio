#pragma once

#include <ECS/Component.h>
#include <Core.hpp>

class Transform : public Component
{
	public:
		static constexpr ComponentId Id = "Transform"_hash;

	public:
		Transform(const Vector3f& position = { 0, 0, 0 }, const Vector3f& rotation = { 0, 0, 0 }, const Vector3f& scale = { 0, 0, 0 });

	public:
		bool Initialize(void *args) override final;
		void Update(const float& deltaTime) override final;

	public:
		void SetPosition(const Vector3f& position);
		void SetRotation(const Vector3f& rotation);
		void SetScale(const Vector3f& scale);

	public:
		const Vector3f& GetPosition() const;
		const Vector3f& GetRotation() const;
		const Vector3f& GetScale() const;

	private:
		Vector3f m_Position;
		Vector3f m_Rotation;
		Vector3f m_Scale;
};