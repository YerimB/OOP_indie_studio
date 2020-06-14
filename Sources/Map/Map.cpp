#include <Map/Map.h>

Map::Map(GameManager* pGameManager)
{
	m_GameManager = pGameManager;
}

void Map::Initialize(const std::size_t& size, Scene *sc)
{
	Generation map(size);
	Vector3f position = {
        (size * 10.0f) / 2,
        0,
        (size * 10.0f) / 2
    };

	{ // Create plane
		Entity plane("Ground");
		Transform* tp = new Transform({0, -10, 0});
		Collider* clp = new Collider();
		Cube* cp = new Cube(m_GameManager->GetSceneManager());

		if (cp->Initialize(sc->GetTexture("Star"))) {
			cp->SetScale({size * 0.90f, 0, size * 0.98f});
			tp->SetScale({size * 0.90f, 0, size * 0.98f});
			cp->SetPosition({0, -10, 0});
			plane.AddComponent(tp, Transform::Id);
			plane.AddComponent(cp, Cube::Id);
			plane.AddComponent(clp, Collider::Id);
			m_GameManager->GetEntityManager()->AddEntity(plane);
		}
	}
	if (size % 4 != 0 || size < 12)
		return;
	auto strMap = map.GetMap();
	m_GameManager->m_globalVars.mapSize = size;
	m_GameManager->m_globalVars.map = strMap;
	for (int idx = 0; idx < strMap.size(); ++idx)
	{
		for (auto& ch : strMap[idx])
		{
			std::string eType;

			if (ch == '1')
				eType = "Block";
			else if (ch == '2')
				eType = "Star";
			else if (ch == '3')
				eType = "Pow";
			else {
				position.Z -= 10;
				continue;
			}

			Entity cubeEntity(eType);
			Transform* t0 = new Transform(position);
			Collider* cl0 = new Collider();
			Cube* c0 = new Cube(m_GameManager->GetSceneManager());
			Texture *texture = sc->GetTexture(eType);

			if (!c0->Initialize(texture))
				continue;
			c0->SetPosition(position);
			cubeEntity.AddComponent(t0, Transform::Id);
			cubeEntity.AddComponent(c0, Cube::Id);
			cubeEntity.AddComponent(cl0, Collider::Id);
			m_GameManager->GetEntityManager()->AddEntity(cubeEntity);
			position.Z -= 10;
		}
		position.Z = ((size * 10) / 2.0f);
		position.X -= 10;
	}
	float corner = -(size * 10.0f) / 2;
	{ // Create player
		Entity player("Player01");
		PlayerAI* p0 = new PlayerAI(m_GameManager->GetSceneManager());
		Drawable* d0 = new Drawable(m_GameManager->GetSceneManager());
		Transform* t0 = new Transform({ corner + 20.0f, 0, corner + 20.0f });
		Collider* cl0 = new Collider();
		Animator* a0 = new Animator(m_GameManager->GetSceneManager());
		if (d0->Initialize(sc->GetMesh("Luigi")) && a0->Initialize(d0->GetDrawable()) && \
		p0->Initialize(&m_GameManager->m_globalVars.playersData[0])) {
			d0->SetPosition({corner + 10.0f, 0, corner + 10.0f});
			a0->AddAnimation("Idle", {0, 300, 30});
			a0->AddAnimation("Run", {301, 320, 30});
			a0->AddAnimation("Death", {321, 410, 30});
			a0->PlayAnimation("Idle");
			player.AddComponent(p0, Player::Id);
			player.AddComponent(d0, Drawable::Id);
			player.AddComponent(t0, Transform::Id);
			player.AddComponent(cl0, Collider::Id);
			player.AddComponent(a0, Animator::Id);
			m_GameManager->GetEntityManager()->AddEntity(player);
		}
	}
    auto camera = m_GameManager->GetSceneManager()->addCameraSceneNode(
		0,
		{ -70, size * 7.5f, 0 },
		{ 0, -50, 0 }
	);
}