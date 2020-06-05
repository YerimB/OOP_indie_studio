#pragma once

#include <ECS/Component.h>
#include <Core.hpp>

class Drawable : public Component
{
	public:
		static constexpr ComponentId Id = __COUNTER__;

	public:
		Drawable();

	public:
		bool Initialize(void* args) override final;
		void Update(const float& deltaTime) override final;
};