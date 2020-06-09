/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Scene
*/

#ifndef SCENE_HPP_
#define SCENE_HPP_

#include <Core.hpp>

class GameManager;

class Scene
{
    public:
        enum SceneID { // Add scene IDs here if needed.
            UNDEFINED = (-1), // Id Not Defined
			MENU, // Menu Id
            GAME, // Game Id
		};

    public:
        Scene(const SceneID &sceneId);
        virtual void Load(GameManager* gameManager) = 0;
        virtual ~Scene() = default;

    public:
        void SetID(const SceneID &newSceneId);

    public:
        const SceneID &GetID(void) const;

    protected:
        SceneID m_ID = UNDEFINED;
};

#endif /* !SCENE_HPP_ */
