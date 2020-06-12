#pragma once

#include <Map/Generation.h>
#include <ECS/EntityManager.h>
#include <Components/Cube.h>
#include <Components/Drawable.h>
#include <Components/Transform.h>
#include <Components/Collider.h>

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