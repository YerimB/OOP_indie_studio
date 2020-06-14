/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Drawable
*/

#pragma once

#include <ECS/Component.h>
#include <Core.hpp>
#include <GameManager.h>

class Drawable : public Component
{
	public:
		static constexpr ComponentId Id = "Drawable"_hash;

	public:
		Drawable(SceneManager* manager);

	public:
		bool Initialize(void* args) override final;
		void Update(const float& deltaTime, GameManager* gameManager) override final;

	public:
		void SetPosition(const Vector3f& position);
		void SetRotation(const Vector3f& rotation);
		void SetScale(const Vector3f& scale);
		void SetTexture(Texture *texture);

	public:
		Vector3f GetPosition();
		Vector3f GetRotation();
		Vector3f GetScale();
		Box3f GetBounds();
		AMeshNode* GetDrawable();

	private:
		SceneManager* m_SceneManager;
		AMeshNode* m_AnimatedMesh;
};