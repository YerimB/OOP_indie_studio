#pragma once

#include <Core.hpp>
#include <ECS/EntityManager.h>
#include <ECS/System/System.h>
#include <Components/Drawable.h>
#include <Components/Transform.h>
#include <Components/Collider.h>

class MoveSystem : public System<Drawable, Collider, Transform>
{
	using BaseType = System<Drawable, Collider, Transform>;

	public:
		MoveSystem(EntityManager* pEntityManager);
		~MoveSystem() override = default;

	public:
		void Update(const double& deltaTime) override final;
		static bool Collide(Drawable* drawable1, Drawable* drawable2);
};