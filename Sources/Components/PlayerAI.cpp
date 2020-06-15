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
    abs_pos.fill(-10);
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
        round(gVars->mapSize - (y - s_pos) / 10.0f),
        round(gVars->mapSize - (x - s_pos) / 10.0f)
    };
    if (tmp != this->_previousPos)
    {
        if (this->_previousPos[0] != -1)
            gVars->map[_previousPos[1]][_previousPos[0]] = '0';
        gVars->map[tmp[1]][tmp[0]] = '1';
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
            round(gm->m_globalVars.mapSize - (t->GetPosition().Z - s_pos) / 10.0f),
            round(gm->m_globalVars.mapSize - (t->GetPosition().X - s_pos) / 10.0f)
        };
        _backupMap = map;
        std::vector<std::string> tmp_map = map;
        tmp_map[tmp[1]][tmp[0]] = 'O';
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