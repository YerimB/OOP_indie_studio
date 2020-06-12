/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Drawable
*/

#include <Components/Drawable.h>

Drawable::Drawable(SceneManager* manager)
{
	m_SceneManager = manager;
	m_AnimatedMesh = nullptr;
}

bool Drawable::Initialize(void* args)
{
	std::string mesh = *static_cast<std::string*>(args);

	m_AnimatedMesh = m_SceneManager->addAnimatedMeshSceneNode(m_SceneManager->getMesh(mesh.c_str()));

	if (!m_AnimatedMesh)
		return false;
	m_AnimatedMesh->setMaterialFlag(irr::video::EMF_LIGHTING, false);
	return true;
}

void Drawable::Update(const float& deltaTime, GameManager* gameManager) {}

void Drawable::SetPosition(const Vector3f& position)
{
	m_AnimatedMesh->setPosition(position);
}

void Drawable::SetRotation(const Vector3f& rotation)
{
	m_AnimatedMesh->setRotation(rotation);
}

void Drawable::SetScale(const Vector3f& scale)
{
	m_AnimatedMesh->setScale(scale);
}

irr::scene::IAnimatedMeshSceneNode* Drawable::GetDrawable()
{
	return m_AnimatedMesh;
}

Vector3f Drawable::GetPosition()
{
	return m_AnimatedMesh->getPosition();
}

Vector3f Drawable::GetRotation()
{
	return m_AnimatedMesh->getRotation();
}

Vector3f Drawable::GetScale()
{
	return m_AnimatedMesh->getScale();
}

Box3f Drawable::GetBounds()
{
	return m_AnimatedMesh->getTransformedBoundingBox();
}
