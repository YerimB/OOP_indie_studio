#include <Map/Map.h>

Map::Map(GameManager* pGameManager)
{
	m_GameManager = pGameManager;
}

void Map::Initialize(const std::size_t& size)
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
			Entity e0("Block");
			Drawable* d0 = new Drawable(m_GameManager->GetSceneManager());
			Transform* t0 = new Transform(position);
			Collider* cl0 = new Collider();
			Cube* c0 = new Cube(m_GameManager->GetSceneManager());
			std::string texture;

			if (ch == '1')
				texture = "Assets/block.png";
			else if (ch == '2')
				texture = "Assets/star.jpeg";
			else if (ch == '3')
				texture = "Assets/pow.jpeg";

			c0->Initialize(&texture);
			t0->SetScale({ 10.0f, 10.0f, 10.0f });
			c0->SetScale({ 10.0f, 10.0f, 10.0f });
			c0->SetPosition(position);
			e0.AddComponent(t0, Transform::Id);
			e0.AddComponent(d0, Drawable::Id);
			e0.AddComponent(c0, Cube::Id);
			e0.AddComponent(cl0, Collider::Id);
			m_GameManager->GetEntityManager()->AddEntity(e0);
			position.X += 10;
		}

		position.X -= 90;
		position.Y += 10;
	}
}