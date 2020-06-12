/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Animator
*/

#include <Components/Animator.h>

Animator::Animator(SceneManager *p_Smgr)
{
    this->m_SceneManager = p_Smgr;
}

// Expected as parameter : (IAnimatedMeshSceneNode *)
bool Animator::Initialize(void *args)
{
    if (!args)
        return (false);
    m_AnimatedMesh = static_cast<AMeshNode *>(args);
    return (true);
}

const bool Animator::AddAnimation(const std::string &sID, const Vector3i &p)
{
    if (m_AnimationMap.find(sID) != m_AnimationMap.end() || p.X < 0 || p.Y < 0)
        return (false);
    m_AnimationMap.emplace(sID, p);
    return (true);
}

void Animator::PlayAnimation(const std::string &sID)
{
    Vector3i properties = m_AnimationMap.find(sID)->second;

    m_AnimatedMesh->setFrameLoop(properties.X, properties.Y);
    m_AnimatedMesh->setAnimationSpeed(properties.Z);
}

void Animator::StopAnimation()
{
    m_AnimatedMesh->setFrameLoop(0, 0);
    m_AnimatedMesh->setAnimationSpeed(0);
}

void Animator::Update(const float &dT, GameManager* gameManager) {}