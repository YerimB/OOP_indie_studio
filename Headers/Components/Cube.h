#pragma once

#include <ECS/Component.h>
#include <Core.hpp>
#include <GameManager.h>

class Cube : public Component
{
	public:
		static constexpr ComponentId Id = "Cube"_hash;

	public:
		Cube(SceneManager* pSceneManager);

	public:
		bool Initialize(void* args) override final;
		void Update(const float& deltaTime, GameManager* gameManager) override final;

	public:
		void SetPosition(const Vector3f& position);
		void SetRotation(const Vector3f& rotation);
		void SetScale(const Vector3f& scale);

	public:
		Vector3f GetPosition();
		Vector3f GetRotation();
		Vector3f GetScale();
		Box3f GetBounds();

	private:
		SceneManager* m_SceneManager;
		MeshNode* m_MeshNode;
};