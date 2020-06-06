#include <Components/Transform.h>

Transform::Transform(const Vector3f& position, const Vector3f& rotation, const Vector3f& scale)
{
	m_Position = position;
	m_Rotation = rotation;
	m_Scale = scale;
}

bool Transform::Initialize(void*)
{
	return true;
}

void Transform::Update(const float&)
{
}

void Transform::SetPosition(const Vector3f& position)
{
	m_Position = position;
}

void Transform::SetRotation(const Vector3f& rotation)
{
	m_Rotation = rotation;
}

void Transform::SetScale(const Vector3f& scale)
{
	m_Scale = scale;
}

const Vector3f& Transform::GetPosition() const
{
	return m_Position;
}

const Vector3f& Transform::GetRotation() const
{
	return m_Rotation;
}

const Vector3f& Transform::GetScale() const
{
	return m_Scale;
}
