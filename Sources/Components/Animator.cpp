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
    AnimatorNode *tmp = nullptr;

    if (!args)
        return (false);
    m_AnimatedMesh = static_cast<AMeshNode *>(args);
    tmp = m_SceneManager->createSceneNodeAnimator("Animator");
    if (!tmp)
        return (false);
    m_AnimatedMesh->addAnimator(tmp);
    tmp->drop();
    return (true);
}

void Animator::Update(const float &dT, GameManager* gameManager) {}