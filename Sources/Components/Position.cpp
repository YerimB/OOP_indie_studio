#include <Components/Position.h>


Position::Position() : Component()
{
	//Id = std::hash<std::string>{}("Position");
	m_Position = Vector2f(0, 0);
}

Position::Position(const Vector2f& position)
{
	m_Position = position;
}

bool Position::Initialize()
{
	return true;
}

void Position::Update()
{
}

const Vector2f& Position::GetPosition() const
{
	return m_Position;
}

void Position::SetPosition(const Vector2f& position)
{
	m_Position = position;
}
