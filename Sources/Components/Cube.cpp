#include "..\..\Headers\Components\Cube.h"

Cube::Cube(SceneManager* pSceneManager)
{
}

bool Cube::Initialize(void* args)
{
	std::string texture = *static_cast<std::string*>(args);

	auto mesh = m_SceneManager->getGeometryCreator()->createCubeMesh({ 0, 0, 0 });
	m_MeshNode = m_SceneManager->addMeshSceneNode(mesh);
	
	return true;
}

void Cube::Update(const float& deltaTime, GameManager* gameManager)
{
}

void Cube::SetPosition(const Vector3f& position)
{
}

void Cube::SetRotation(const Vector3f& rotation)
{
}

void Cube::SetScale(const Vector3f& scale)
{
}

Vector3f Cube::GetPosition()
{
	return Vector3f();
}

Vector3f Cube::GetRotation()
{
	return Vector3f();
}

Vector3f Cube::GetScale()
{
	return Vector3f();
}

Box3f Cube::GetBounds()
{
	return Box3f();
}
