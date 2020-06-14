/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** PlayerAI
*/

#include <Components/PlayerAI.h>

PlayerAI::PlayerAI(SceneManager *manager) : Player::Player(manager)
{
    this->_previousPos.fill(-1);
}

void PlayerAI::Update(const float& dT, GameManager* gm)
{
    Entity &e = gm->GetEntityManager()->GetEntity(this->m_EntityId);
    Transform *transform = e.GetComponent<Transform>();

    this->UpdateMap(transform, &gm->m_globalVars);
    this->GetMovements(gm, e);
}

void PlayerAI::GetMovements(GameManager *gm, Entity &self)
{
    auto &map = gm->m_globalVars.map;
    Transform *t = self.GetComponent<Transform>();
    Vector3f p = t->GetPosition();
    Animator* animator = self.GetComponent<Animator>();
    Vector3f r = t->GetRotation();
    auto s_pos = -(gm->m_globalVars.mapSize * 10.0f) / 2;
    std::array<int, 2> tmp = {
        static_cast<int>(round(gm->m_globalVars.mapSize - (p.Z - s_pos) / 10) - 1.0f),
        static_cast<int>(round(gm->m_globalVars.mapSize - (p.X - s_pos) / 10) - 1.0f)
    };
	if (tmp != _previousPos)
	{
        std::cout << "Search for paths" << std::endl;
		std::vector<std::string> tmp_map = map;
        tmp_map[1][1] = 'E';
        AI a(tmp_map);
        for (int i = 0; i < tmp_map.size(); i++)
        {
            std::cout << tmp_map[i] << std::endl;
        }
        std::cout << std::endl;
        _dir = a.getDir();
        _previousPos = tmp;
        std::cout << "Path found" << std::endl;
        isMoving = false;
	} else {
        isMoving = true;
		if (_dir[0] == 1 && _dir[1] == 0) t->SetRotation({ 0, 270, 0 });
        if (_dir[0] == -1 && _dir[1] == 0) t->SetRotation({ 0, 90, 0 });
        if (_dir[0] == 0 && _dir[1] == 1) t->SetRotation({ 0, 180, 0 });
        if (_dir[0] == 0 && _dir[1] == -1) t->SetRotation({ 0, 0, 0 });
        t->SetPosition({ p.X  + static_cast<float>(_dir[0] / 2.0), p.Y, p.Z + static_cast<float>(_dir[1] / 2.0) });
    }
    if (this->m_oldMoveState != isMoving)
        animator->PlayAnimation((isMoving) ? "Run" : "Idle");
    this->m_oldMoveState = isMoving;
}