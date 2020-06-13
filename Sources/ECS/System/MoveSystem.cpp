#include <ECS/System/MoveSystem.h>
#include <Components/Cube.h>

MoveSystem::MoveSystem(EntityManager* pEntityManager) : BaseType(pEntityManager)
{
}

void MoveSystem::Update(const double& deltaTime)
{
	for (size_t i = 0; i < _components.size(); i += 1)
	{
		Drawable* drawable = std::get<Drawable*>(_components[i]);
		Collider* collider = std::get<Collider*>(_components[i]);
		Transform* transform = std::get<Transform*>(_components[i]);

		if (!drawable->GetDrawable())
			continue;

		std::array<Vector3f, 3> ts = {
			drawable->GetPosition(),
			drawable->GetRotation(),
			drawable->GetScale()
		};

		for (size_t j = 0; j < _components.size(); j += 1)
		{
			if (i == j)
				continue;

			Drawable* drawable2 = std::get<Drawable*>(_components[j]);
			Collider* collider2 = std::get<Collider*>(_components[j]);

			if (!drawable2->GetDrawable())
				continue;

			drawable->SetPosition(transform->GetPosition());
			drawable->SetRotation(transform->GetRotation());
			drawable->SetScale(transform->GetScale());

			if (MoveSystem::Collide(drawable, drawable2))
			{
				transform->SetPosition(ts[0]);
				transform->SetRotation(ts[1]);
				transform->SetScale(ts[2]);
				break;
			}
		}
		drawable->SetPosition(transform->GetPosition());
		drawable->SetRotation(transform->GetRotation());
		drawable->SetScale(transform->GetScale());
		if (drawable->GetEntityId() == 2974060393) {
			auto t = transform->GetPosition();
			auto r = transform->GetRotation();
			transform->SetPosition({t.X, t.Y - 0.5f, t.Z});
			transform->SetRotation({r.X, r.Y - 10, r.Z});
		}
	}
}

bool MoveSystem::Collide(Drawable* drawable1, Drawable* drawable2)
{
	return drawable1->GetBounds().intersectsWithBox(drawable2->GetBounds());
}