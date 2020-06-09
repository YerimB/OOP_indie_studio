/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Drawable
*/

#include <Components/Drawable.h>

Drawable::Drawable(irr::scene::ISceneManager* manager)
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

void Drawable::Update(const float&) {}

irr::scene::IAnimatedMeshSceneNode* Drawable::GetDrawable()
{
	return m_AnimatedMesh;
}
