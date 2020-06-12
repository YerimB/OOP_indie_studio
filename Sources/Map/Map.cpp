#include <Map/Map.h>

Map::Map(GameManager* pGameManager)
{
	m_GameManager = pGameManager;
}

void Map::Initialize(const std::size_t& size, Scene *sc)
{
	auto map = Generation(size);
	int x = (size < 10 ? -(size * 10) : -40 * (size / 10));
	Vector3f position = {
        static_cast<float>(x),
        0,
		static_cast<float>(x - 10)
    };

	for (auto& line : map.GetMap())
	{
		for (auto& ch : line)
		{
			Entity cubeEntity("Block");
			Drawable* d0 = new Drawable(m_GameManager->GetSceneManager());
			Transform* t0 = new Transform(position);
			Collider* cl0 = new Collider();
			Cube* c0 = new Cube(m_GameManager->GetSceneManager());
			Texture *texture = nullptr;

			if (ch == '1')
				texture = sc->GetTexture("Block");
			else if (ch == '2')
				texture = sc->GetTexture("Star");
			else if (ch == '3')
				texture = sc->GetTexture("Pow");
			else continue;
			if (!c0->Initialize(texture))
				continue;
			c0->SetPosition(position);
			cubeEntity.AddComponent(t0, Transform::Id);
			cubeEntity.AddComponent(d0, Drawable::Id);
			cubeEntity.AddComponent(c0, Cube::Id);
			cubeEntity.AddComponent(cl0, Collider::Id);
			m_GameManager->GetEntityManager()->AddEntity(cubeEntity);
			position.X += 10;
		}
		position.X -= 90;
		position.Y += 10;
	}
}