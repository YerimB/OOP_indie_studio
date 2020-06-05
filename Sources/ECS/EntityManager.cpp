/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** EntityManager
*/

#include <ECS/EntityManager.h>

EntityManager::EntityManager()
{

}

EntityManager::~EntityManager()
{

}

bool EntityManager::Initialize()
{
	return true;
}

void EntityManager::Update()
{

}

void EntityManager::AddEntity(const Entity& entity)
{
	m_Entities.emplace(std::make_pair(entity.GetId(), entity));
}

void EntityManager::RemoveEntity(const Entity& entity)
{
	m_Entities.erase(entity.GetId());
}
