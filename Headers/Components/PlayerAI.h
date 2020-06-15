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
        void UpdateMap(Transform* pPos, GameVars_t* gVars);
        void GetMovements(GameManager *gm, Entity &self) override final;
	private:
		std::array<int, 2> _previousPos;
        std::array<float, 2> abs_pos;
        std::array<int, 2> _dir;
        bool isMoving;
        std::array<int, 2> _target;
        std::vector<std::string> _backupMap;
        bool freeze;
};

#endif /* !PLAYERAI_H_ */
