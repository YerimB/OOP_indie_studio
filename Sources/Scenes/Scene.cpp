/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Scene
*/

#include <Scenes/Scene.hpp>

Scene::Scene(const Scene::SceneID &sID) : m_ID(sID) {}

void Scene::SetID(const SceneID &sID)
{
    this->m_ID = sID;
}

const Scene::SceneID &Scene::GetID(void) const
{
    return (this->m_ID);
}