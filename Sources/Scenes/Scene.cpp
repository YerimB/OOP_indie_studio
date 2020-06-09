/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Scene
*/

#include <Scenes/Scene.hpp>

Scene::Scene(const Scene::SceneID &sID) : m_ID(sID) {}

void Scene::SetID(const SceneID& newSceneId)
{
	m_ID = newSceneId;
}

const Scene::SceneID& Scene::GetID(void) const
{
	return m_ID;
}
