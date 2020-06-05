/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Component
*/

#pragma once

#include <string>
#include <Core.hpp>
#include <any>

class Component
{
	public:
		virtual ~Component() = default;

public:
	virtual bool Initialize(void *args) = 0;
	virtual void Update(const float& deltaTime) = 0;

	public:
		const ComponentId& GetId() const;
		const EntityId& GetEntityId() const;
		const std::size_t& GetIndex() const;

	public:
		void SetEntityId(const EntityId& entityId);

	private:
		EntityId m_EntityId;
		ComponentId m_Id;
		std::size_t m_Index;
};