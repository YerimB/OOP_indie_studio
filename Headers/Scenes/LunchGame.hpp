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
        void Load(GameManager* gameManager) override final;
    private:
};

#endif /* !LUNCHGAME_HPP_ */
