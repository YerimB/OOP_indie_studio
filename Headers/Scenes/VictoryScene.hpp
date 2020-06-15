/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** VictoryScene
*/

#ifndef VICTORYSCENE_HPP_
#define VICTORYSCENE_HPP_

#include <Scenes/Scene.hpp>

class VictoryScene : public Scene {
    public:
        VictoryScene();
        ~VictoryScene();
        void LoadSystems(GameManager*) override final;
		void LoadAssets(GameManager*) override final;
		void LoadElements(GameManager*) override final;

	public:
		void Load(GameManager*) override final;
		void Update(GameManager*) override final;
		void Unload(void) override final;
    private:
};

#endif /* !VICTORYSCENE_HPP_ */
