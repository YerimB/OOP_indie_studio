/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** PlayerAI
*/

#include <Components/PlayerAI.h>

#include "Components/Drawable.h"

PlayerAI::PlayerAI(SceneManager *manager) : Player::Player(manager)
{
    _backupMap.push_back("    ");
    _target.fill(0);
    this->_previousPos.fill(-1);
    abs_pos.fill(-10);
    freeze = false;
}

void PlayerAI::Update(const float& dT, GameManager* gm)
{
    Entity *e = gm->GetEntityManager()->GetEntity(this->m_EntityId);
    Transform *transform = e->GetComponent<Transform>();

    this->UpdateMap(transform, &gm->m_globalVars);
    this->GetMovements(gm, *e);
}


void PlayerAI::UpdateMap(Transform* pPos, GameVars_t* gVars)
{
    int x = pPos->GetPosition().X;
    int y = pPos->GetPosition().Z;
    auto s_pos = -(gVars->mapSize * 10.0f) / 2.0f;
    std::array<int, 2> tmp = {
        static_cast<int>(round(gVars->mapSize - (y - s_pos) / 10.0f)),
        static_cast<int>(round(gVars->mapSize - (x - s_pos) / 10.0f))
    };
    if (tmp != this->_previousPos)
    {
        if (this->_previousPos[0] != -1)
            if (gVars->map[_previousPos[1]][_previousPos[0]] != 'B')
				gVars->map[_previousPos[1]][_previousPos[0]] = '0';
    	if (gVars->map[tmp[1]][tmp[0]] != 'B')
			gVars->map[tmp[1]][tmp[0]] = '1';
        gVars->playersData[m_Data->playerID - 1].position.Y = tmp[0];
        gVars->playersData[m_Data->playerID - 1].position.X = tmp[1];
        _previousPos = tmp;
    }
}

void PlayerAI::GetMovements(GameManager *gm, Entity &self)
{
    auto &map = gm->m_globalVars.map;
    Transform *t = self.GetComponent<Transform>();
    Vector3f p = t->GetPosition();
    Animator* animator = self.GetComponent<Animator>();
    Vector3f r = t->GetRotation();


	if (abs(abs_pos[0] - t->GetPosition().X) >=10 || abs(abs_pos[1] - t->GetPosition().Z) >= 10 ||
        (abs_pos[0] == t->GetPosition().X && abs_pos[1] == t->GetPosition().Z))
	{
        abs_pos = {
            t->GetPosition().X,
            t->GetPosition().Z,
        };
        auto s_pos = -(gm->m_globalVars.mapSize * 10.0f) / 2.0f;
        std::array<int, 2> tmp = {
            static_cast<int>(round(gm->m_globalVars.mapSize - (t->GetPosition().Z - s_pos) / 10.0f)),
            static_cast<int>(round(gm->m_globalVars.mapSize - (t->GetPosition().X - s_pos) / 10.0f))
        };
        _backupMap = map;
        std::vector<std::string> tmp_map = map;
		tmp_map[tmp[1]][tmp[0]] = 'O';
		for (int i = 0; i < gm->m_globalVars.playersData.size(); i++)
		{
            if (gm->m_globalVars.playersData[i].isActive)
            {
                std::array<int, 2> tmp_pos = {
                    gm->m_globalVars.playersData[i].position.Y,
                    gm->m_globalVars.playersData[i].position.X
                };
                tmp_map[tmp_pos[1]][tmp_pos[0]] = 'E';
            }
		}
        AI a(tmp_map);
        if (map[_target[0]][_target[1]] == 'B')
        {
            if (a.isInBombRange())
            {
                _dir = a.getDir();
                isMoving = true;
            } else {
                _dir = std::array<int, 2>({ 0, 0 });
                isMoving = false;
            }
        }
        else
        {
            isMoving = true;
            _dir = a.getDir();
            if (tmp_map[tmp[1] - _dir[0]][tmp[0] - _dir[1]] == '2' || tmp_map[tmp[1] - _dir[0]][tmp[0] - _dir[1]] == 'E')
            {
                _target = std::array<int, 2>({
					tmp[1],
                	tmp[0]
                });
            	if (tmp_map[tmp[1] + _dir[0]][tmp[0] + _dir[1]] == '0')
            	{
                    _dir[0] = -_dir[0];
                    _dir[1] = -_dir[1];
            	}
                else if (tmp_map[tmp[1] - _dir[1]][tmp[0] - _dir[0]] == '0')
                {
                    int tmp = _dir[0];
                    _dir[0] = _dir[1];
                    _dir[1] = tmp;
                } else
                {
                    _dir[0] = -_dir[0];
                    _dir[1] = -_dir[1];
                    int tmp = _dir[0];
                    _dir[0] = _dir[1];
                    _dir[1] = tmp;
                }
                if (!this->m_Bomb)
                    DropBomb(self, gm);
            }
        }
        if (_dir[0] == 1 && _dir[1] == 0) t->SetRotation({ 0, 270, 0 });
        if (_dir[0] == -1 && _dir[1] == 0) t->SetRotation({ 0, 90, 0 });
        if (_dir[0] == 0 && _dir[1] == 1) t->SetRotation({ 0, 180, 0 });
        if (_dir[0] == 0 && _dir[1] == -1) t->SetRotation({ 0, 0, 0 });
	}
    if (m_Bomb != nullptr && m_Bomb->GetComponent<Timer>()->GetDuration() <= 0) {
        DestroyBlocks(gm);
        m_Bomb->GetComponent<Drawable>()->GetDrawable()->remove();
        m_Bomb = nullptr;
    }
    t->SetPosition({ p.X + static_cast<float>(_dir[0] / 2.0), p.Y, p.Z + static_cast<float>(_dir[1] / 2.0) });
    if (this->m_oldMoveState != isMoving)
        animator->PlayAnimation((isMoving) ? "Run" : "Idle");
    this->m_oldMoveState = isMoving;
}