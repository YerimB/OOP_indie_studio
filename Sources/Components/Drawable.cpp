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
	m_Mesh = nullptr;
}

bool Drawable::Initialize(void* args)
{
	AMesh* mesh = static_cast<AMesh*>(args);

	m_Mesh = m_SceneManager->addAnimatedMeshSceneNode(mesh);

	if (!m_Mesh)
		return false;
	m_Mesh->setMaterialFlag(irr::video::EMF_LIGHTING, false);
	return true;
}

void Drawable::Update(const float& deltaTime, GameManager* gameManager) {}

void Drawable::SetPosition(const Vector3f& position)
{
	m_Mesh->setPosition(position);
}

void Drawable::SetRotation(const Vector3f& rotation)
{
	m_Mesh->setRotation(rotation);
}

void Drawable::SetScale(const Vector3f& scale)
{
	m_Mesh->setScale(scale);
}

void Drawable::SetTexture(Texture *texture)
{
	if (!texture)
		return;
	m_Mesh->setMaterialTexture(0, texture);
}

SceneNode* Drawable::GetDrawable()
{
	return m_Mesh;
}

Vector3f Drawable::GetPosition()
{
	return m_Mesh->getPosition();
}

Vector3f Drawable::GetRotation()
{
	return m_Mesh->getRotation();
}

Vector3f Drawable::GetScale()
{
	return m_Mesh->getScale();
}

Box3f Drawable::GetBounds()
{
	m_Mesh->updateAbsolutePosition();
	return m_Mesh->getTransformedBoundingBox();
}
