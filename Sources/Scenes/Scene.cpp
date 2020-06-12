/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Scene
*/

#include <Scenes/Scene.hpp>

Scene::Scene(const Scene::SceneID &sID) : m_ID(sID) {}

const bool Scene::AddMesh(AMesh *mesh, const std::string &id)
{
	if (m_LoadedMeshes.find(id) != m_LoadedMeshes.end() || !mesh)
		return (false);
	m_LoadedMeshes.emplace(std::move(mesh), id);
	return (true);
}

const bool Scene::AddTexture(Texture *texture, const std::string &id)
{
	if (m_LoadedTextures.find(id) != m_LoadedTextures.end() || !texture)
		return (false);
	m_LoadedTextures.emplace(std::move(texture), id);
	return (true);
}

void Scene::SetID(const SceneID& newSceneId)
{
	m_ID = newSceneId;
}

const Scene::SceneID& Scene::GetID(void) const
{
	return m_ID;
}

AMesh *Scene::GetMesh(const std::string &id)
{
	if (m_LoadedMeshes.find(id) == m_LoadedMeshes.end())
		return (nullptr);
	return (m_LoadedMeshes[id]);
}

Texture *Scene::GetTexture(const std::string &id)
{
	if (m_LoadedTextures.find(id) == m_LoadedTextures.end())
		return (nullptr);
	return (m_LoadedTextures[id]);
}