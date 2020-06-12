#include <Components/Cube.h>

Cube::Cube(SceneManager* pSceneManager)
{
	m_SceneManager = pSceneManager;
	m_MeshNode = nullptr;
}

bool Cube::Initialize(void* args)
{
	if (!args)
		return false;

	std::string texture = *static_cast<std::string*>(args);
	auto mesh = m_SceneManager->getGeometryCreator()->createCubeMesh({ 0, 0, 0 });

	if (!mesh)
		return false;
	m_MeshNode = m_SceneManager->addMeshSceneNode(mesh);
	return true;
}

void Cube::Update(const float& deltaTime, GameManager* gameManager)
{
}

void Cube::SetPosition(const Vector3f& position)
{
	m_MeshNode->setPosition(position);
}

void Cube::SetRotation(const Vector3f& rotation)
{
	m_MeshNode->setRotation(rotation);
}

void Cube::SetScale(const Vector3f& scale)
{
	m_MeshNode->setScale(scale);
}

void Cube::SetTexture(Texture* texture)
{
	m_MeshNode->setMaterialTexture(0, texture);
	m_MeshNode->setMaterialFlag(irr::video::EMF_LIGHTING, false);
}

Vector3f Cube::GetPosition()
{
	return m_MeshNode->getPosition();
}

Vector3f Cube::GetRotation()
{
	
	return m_MeshNode->getRotation();
}

Vector3f Cube::GetScale()
{
	return m_MeshNode->getScale();
}

Box3f Cube::GetBounds()
{
	return m_MeshNode->getTransformedBoundingBox();
}

MeshNode* Cube::GetCube()
{
	return m_MeshNode;
}
