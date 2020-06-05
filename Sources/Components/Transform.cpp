#include <Components/Transform.h>

Transform::Transform(const Vector2f& position, const float& rotation, const float& scale)
{
	m_Position = position;
	m_Rotation = rotation;
	m_Scale = scale;

	Initialize(nullptr);
}

bool Transform::Initialize(void*)
{
	return true;
}

void Transform::SetPosition(const Vector2f& position)
{
	m_Position = position;
}

void Transform::SetRotation(const float& rotation)
{
	m_Rotation = rotation;
}

void Transform::SetScale(const float& scale)
{
	m_Scale = scale;
}

const Vector2f& Transform::GetPosition() const
{
	return m_Position;
}

const float& Transform::GetRotation() const
{
	return m_Rotation;
}

const float& Transform::GetScale() const
{
	return m_Scale;
}
