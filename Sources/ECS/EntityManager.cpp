/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** EntityManager
*/

#include <ECS/EntityManager.h>

EntityManager::EntityManager(irr::scene::ISceneManager* manager, irr::gui::IGUIEnvironment* env, InputManager* im, GameManager* gameManager)
{
	m_SceneManager = manager;
	m_GuiEnvironment = env;
	m_InputManager = im;
	m_GameManager = gameManager;
	m_Time;
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
	// Get data from server and modify entities before systems update
	for (auto& system : m_Systems)
	{
		system->Update(m_Time.GetDeltaTime().count());
	}
	m_GuiEnvironment->drawAll();
}

void EntityManager::AddEntity(const Entity& entity)
{
	m_Entities.insert(std::make_pair(entity.GetId(), entity));
	for (auto &elem : this->m_Systems)
		elem->OnEntityCreated(entity);
}

void EntityManager::RemoveEntity(const Entity& entity)
{
	for (auto& elem : this->m_Systems)
		elem->OnEntityDestroyed(entity.GetId());
	m_Entities.erase(entity.GetId());
}

void EntityManager::AddSystem(BaseSystem* system)
{
	m_Systems.emplace_back(system);
}

void EntityManager::RemoveSystem(BaseSystem* system)
{
	auto findIt = std::find(m_Systems.begin(), m_Systems.end(), system);
	
	if (findIt != m_Systems.end())
		m_Systems.erase(findIt);
}

void EntityManager::ClearEntities()
{
	m_Entities.clear();
}

void EntityManager::ClearComponents()
{
	m_Components.clear();
}

void EntityManager::ClearSystems()
{
	m_Systems.clear();
}

void EntityManager::ClearAll()
{
	m_Entities.clear();
	m_Components.clear();
	m_Systems.clear();
}

Entity* EntityManager::GetEntity(const std::string& name)
{
	for (auto& entity : m_Entities)
	{
		if (entity.second.GetName() == name)
			return &entity.second;
	}

	return nullptr;
}

Entity* EntityManager::GetEntity(const size_t& id)
{
	for (auto& entity : m_Entities)
	{
		if (entity.second.GetId() == id)
			return &entity.second;
	}

	return nullptr;
}
