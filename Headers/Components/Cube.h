#pragma once

#include <ECS/Component.h>
#include <Components/Drawable.h>
#include <Core.hpp>
#include <GameManager.h>

class Cube : public Drawable
{
	public:
		static constexpr ComponentId Id = "Cube"_hash;

	public:
		Cube(SceneManager* pSceneManager);

	public:
		bool Initialize(void* args) override final;
};