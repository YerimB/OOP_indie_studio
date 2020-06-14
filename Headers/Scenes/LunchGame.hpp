/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** LunchGame
*/

#ifndef LUNCHGAME_HPP_
#define LUNCHGAME_HPP_

#include <Scenes/Scene.hpp>

class LunchGame : public Scene {
    public:
        LunchGame();
        ~LunchGame();
        void LoadSystems(GameManager*) override final;
		void LoadAssets(GameManager*) override final;
		void LoadElements(GameManager*) override final;

	public:
		void Load(GameManager* gameManager) override final;
		void Update(GameManager* gameManager) override final;
		void Unload(void) override final;
    private:
};

#endif /* !LUNCHGAME_HPP_ */
