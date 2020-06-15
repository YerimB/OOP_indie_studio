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

		if (!drawable->GetDrawable() /*|| collider->GetTag() == Collider::Tag::None*/)
			continue;

		std::array<Vector3f, 3> ts = {
			drawable->GetPosition(),
			drawable->GetRotation(),
			drawable->GetScale()
		};
		drawable->SetPosition(transform->GetPosition());
		drawable->SetRotation(transform->GetRotation());
		drawable->SetScale(transform->GetScale());
		for (size_t j = 0; j < _components.size(); j += 1)
		{
			if (i == j)
				continue;

			Drawable* drawable2 = std::get<Drawable*>(_components[j]);
			Collider* collider2 = std::get<Collider*>(_components[j]);
			
			if (!drawable2->GetDrawable())
				continue;
			if (/*collider->GetTag() != collider2->GetTag() &&*/ MoveSystem::Collide(drawable, drawable2))
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
	}
}

bool MoveSystem::Collide(Drawable* drawable1, Drawable* drawable2)
{
	return drawable1->GetBounds().intersectsWithBox(drawable2->GetBounds());
}