/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** PlayerAI
*/

#include <Components/PlayerAI.h>

PlayerAI::PlayerAI(SceneManager *manager) : Player::Player(manager)
{
    _backupMap.push_back("    ");
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
	if (_backupMap != map)
	{
        _backupMap = map;
        std::vector<std::string> tmp_map = map;
        tmp_map[1][1] = 'E';
        for (int i = 0; i < map.size(); i++)
        {
            std::cout << map[i] << std::endl;
        }
        AI a(tmp_map);
        _dir = a.getDir();
        isMoving = false;
        isMoving = true;
        if (_dir[0] == 1 && _dir[1] == 0) t->SetRotation({ 0, 270, 0 });
        if (_dir[0] == -1 && _dir[1] == 0) t->SetRotation({ 0, 90, 0 });
        if (_dir[0] == 0 && _dir[1] == 1) t->SetRotation({ 0, 180, 0 });
        if (_dir[0] == 0 && _dir[1] == -1) t->SetRotation({ 0, 0, 0 });


	}
    t->SetPosition({ p.X + static_cast<float>(_dir[0] / 2.0), p.Y, p.Z + static_cast<float>(_dir[1] / 2.0) });
    if (this->m_oldMoveState != isMoving)
        animator->PlayAnimation((isMoving) ? "Run" : "Idle");
    this->m_oldMoveState = isMoving;
}