/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Scene
*/

#ifndef SCENE_HPP_
#define SCENE_HPP_

#include <Core.hpp>

class Scene
{
    public:
        enum SceneID { // Add scene IDs here if needed.
            UNDEFINED = (-1), // Id Not Defined
			MENU, // Menu Id
            GAME, // Game Id
		};

    public:
        Scene();
        Scene(const SceneID &sceneId);
        void Load(GuiEnvironment *guiEnvironment, SceneManager *sceneManager);
        ~Scene();
    
    public:
        void SetID(const SceneID &newSceneId);
    
    public:
        const SceneID &GetID(void) const;

    private:
        SceneID m_ID = UNDEFINED;
};

#endif /* !SCENE_HPP_ */
