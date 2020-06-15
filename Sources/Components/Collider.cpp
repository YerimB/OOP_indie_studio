/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Collider
*/

#include <Components/Collider.h>

Collider::Collider(const Tag& tag)
{
	m_Tag = tag;
}

bool Collider::Initialize(void *args)
{
    return true;
}

void Collider::Update(const float &deltaTime, GameManager *) {}

void Collider::SetTag(const Tag& tag)
{
	m_Tag = tag;
}

const Collider::Tag& Collider::GetTag() const
{
	return m_Tag;
}
