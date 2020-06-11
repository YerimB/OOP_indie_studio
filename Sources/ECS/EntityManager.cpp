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
		system->Update(0);
	}
	m_GuiEnvironment->drawAll();
}

void EntityManager::AddEntity(const Entity& entity)
{
	m_Entities.emplace(std::make_pair(entity.GetId(), entity));
	for (auto &elem : this->m_Systems)
		elem->OnEntityCreated(entity);
}

void EntityManager::RemoveEntity(const Entity& entity)
{
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
