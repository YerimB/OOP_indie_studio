/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Scene
*/

#ifndef SCENE_HPP_
#define SCENE_HPP_

#include <Core.hpp>
#include <unordered_map>

class GameManager;

class Scene
{
        public:
        enum SceneID { // Add scene IDs here if needed.
            UNDEFINED = (-1), // Id Not Defined
			MENU, // Menu Id
            LUNCH_GAME, // Lunch Game ID
            GAME, // Game Id
            CONTROLLER,
            VICTORY,
        };

        public:
            Scene(const SceneID& sceneId);
            virtual void Load(GameManager* gameManager) = 0;
            virtual void Update(GameManager* gameManager) = 0;
            virtual void Unload(void) = 0;
            virtual ~Scene() = default;

        public:
            const bool AddMesh(AMesh*, const std::string & id);
            const bool AddTexture(Texture*, const std::string & id);

        public:
            void SetID(const SceneID & newSceneId);

        public:
            const SceneID& GetID(void) const;
            AMesh* GetMesh(const std::string & id);
            Texture* GetTexture(const std::string & id);

        protected:
            virtual void LoadSystems(GameManager*) = 0;
            virtual void LoadAssets(GameManager*) = 0;
            virtual void LoadElements(GameManager*) = 0;

        protected:
            SceneID m_ID = UNDEFINED;
            std::unordered_map<std::string, AMesh*> m_LoadedMeshes;
            std::unordered_map<std::string, Texture*> m_LoadedTextures;
};

#endif /* !SCENE_HPP_ */
