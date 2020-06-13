#include <Components/Cube.h>

Cube::Cube(SceneManager* pSceneManager) : Drawable(pSceneManager)
{
}

bool Cube::Initialize(void* args)
{
	if (!args)
		return false;
	Texture *texture = static_cast<Texture *>(args);
	Mesh *mesh = m_SceneManager->getGeometryCreator()->createCubeMesh({ 10.0f, 10.0f, 10.0f });
	if (!mesh)
		return false;
	m_Mesh = m_SceneManager->addMeshSceneNode(std::move(mesh));
	m_Mesh->setMaterialFlag(irr::video::EMF_LIGHTING, false);
	m_Mesh->setMaterialTexture(0, texture);
	//mesh->drop();
	return true;
}