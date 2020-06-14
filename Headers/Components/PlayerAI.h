/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** PlayerAI
*/

#ifndef PLAYERAI_H_
#define PLAYERAI_H_

#include <AI/AI.h>
#include <Components/Player.h>

class PlayerAI : public Player
{
    public:
        PlayerAI(SceneManager *manager);
    
    public:
        void Update(const float& deltaTime, GameManager* gameManager) final;
    
    protected:
        void GetMovements(GameManager *gm, Entity &self) override final;
	private:
		std::array<int, 2> _previousPos;
        std::array<int, 2> _dir;
        bool isMoving;
};

#endif /* !PLAYERAI_H_ */
