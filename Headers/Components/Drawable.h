/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Drawable
*/

#pragma once

#include <ECS/Component.h>
#include <Core.hpp>
#include <Irrlicht/irrlicht.h>

class Drawable : public Component
{
	public:
		static constexpr ComponentId Id = "Drawable"_hash;

	public:
		Drawable(SceneManager* manager);

	public:
		bool Initialize(void* args) override final;
		void Update(const float& deltaTime) override final;

	public:
		irr::scene::IAnimatedMeshSceneNode* GetDrawable();

	private:
		SceneManager* m_SceneManager;
		irr::scene::IAnimatedMeshSceneNode* m_AnimatedMesh;
};