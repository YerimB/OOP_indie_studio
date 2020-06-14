/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Player
*/

#include <Components/Player.h>
#include <Components/Transform.h>

Player::Player(SceneManager* manager)
{
    this->_previousPos.fill(-1);
    this->m_SceneManager = manager;
}

bool Player::Initialize(void *args)
{
    if (!args)
        return false;
    this->m_Data = static_cast<PlayerData_t *>(args);
    return true;
}

void Player::Update(const float &dT, GameManager* gm)
{
    Entity &e = gm->GetEntityManager()->GetEntity(this->m_EntityId);
    auto transform = e.GetComponent<Transform>();

    this->UpdateMap(transform, &gm->m_globalVars);
    this->GetMovements(gm->GetInputManager(), e);
}

void Player::bindKey(const std::string &a, const irr::EKEY_CODE &code)
{
    this->m_Data->bindingsMap[a] = code;
}

void Player::GetMovements(InputManager *im, Entity &self)
{
    bool isMoving = false;
    Transform *transform = self.GetComponent<Transform>();
    Animator *animator = self.GetComponent<Animator>();

    if (im->IsKeyDown(m_Data->bindingsMap["UP"]))
    {
        auto position = transform->GetPosition();

        transform->SetPosition({ position.X + 0.5f, position.Y, position.Z });
        transform->SetRotation({ 0, 270, 0});
        isMoving = true;
    }
    if (im->IsKeyDown(m_Data->bindingsMap["LEFT"]))
    {
        auto position = transform->GetPosition();

        transform->SetPosition({ position.X, position.Y, position.Z + 0.5f });
        transform->SetRotation({ 0, 180, 0});
        isMoving = true;
    }
    if (im->IsKeyDown(m_Data->bindingsMap["DOWN"]))
    {
        auto position = transform->GetPosition();

        transform->SetPosition({ position.X - 0.5f, position.Y, position.Z });
        transform->SetRotation({ 0, 90, 0});
        isMoving = true;
    }
    if (im->IsKeyDown(m_Data->bindingsMap["RIGHT"]))
    {
        auto position = transform->GetPosition();

        transform->SetPosition({ position.X, position.Y, position.Z - 0.5f });
        transform->SetRotation({ 0, 0, 0});
        isMoving = true;
    }
    if (im->IsKeyDown(m_Data->bindingsMap["DROP"]))
    {
        std::cout << "Dropping the bomb." << std::endl;
    }
}

void Player::UpdateMap(Transform *pPos, GameVars_t *gVars)
{
    int x = pPos->GetPosition().X;
    int y = pPos->GetPosition().Z;
    auto s_pos = -(gVars->mapSize * 10.0f) / 2;
    std::array<int, 2> tmp = {round(gVars->mapSize - (y - s_pos)/10) - 1, round(gVars->mapSize - (x - s_pos)/10) - 1 };
	if (tmp != this->_previousPos)
	{
        if (this->_previousPos[0] != -1)
            gVars->map[_previousPos[1]][_previousPos[0]] = '0';
        gVars->map[tmp[1]][tmp[0]] = 'E';
        _previousPos = tmp;
		for(int i = 0; i < gVars->map.size(); i++)
		{
            std::cout << gVars->map[i] << std::endl;
		}
        std::cout << std::endl;
	}
}