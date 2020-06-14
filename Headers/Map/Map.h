#pragma once

#include <Map/Generation.h>
#include <ECS/EntityManager.h>
#include <ECS/ECS.h>

class Map
{
	public:
		Map(GameManager* pGameManager);
		~Map() = default;

	public:
		void Initialize(const std::size_t& size, Scene *sc);

	private:
		GameManager* m_GameManager;
};