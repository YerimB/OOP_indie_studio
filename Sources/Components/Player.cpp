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
    InputManager *im = gm->GetInputManager();
    auto transform = e.GetComponent<Transform>();

    this->UpdateMap(transform, &gm->m_globalVars);
    if (im->IsKeyDown(m_Data->bindingsMap["UP"]))
    {
        auto position = transform->GetPosition();

        transform->SetPosition({ position.X + 0.5f, position.Y, position.Z });
        transform->SetRotation({ 0, 90, 0});
    }
    if (im->IsKeyDown(m_Data->bindingsMap["LEFT"]))
    {
        auto position = transform->GetPosition();

        transform->SetPosition({ position.X, position.Y, position.Z + 0.5f });
        transform->SetRotation({ 0, 0, 0});
    }
    if (im->IsKeyDown(m_Data->bindingsMap["DOWN"]))
    {
        auto position = transform->GetPosition();

        transform->SetPosition({ position.X - 0.5f, position.Y, position.Z });
        transform->SetRotation({ 0, 270, 0});
    }
    if (im->IsKeyDown(m_Data->bindingsMap["RIGHT"]))
    {
        auto position = transform->GetPosition();

        transform->SetPosition({ position.X, position.Y, position.Z - 0.5f });
        transform->SetRotation({ 0, 180, 0});
    }
    if (im->IsKeyDown(m_Data->bindingsMap["DROP"]))
    {
        std::cout << "Dropping the bomb." << std::endl;
    }
}

void Player::bindKey(const std::string &a, const irr::EKEY_CODE &code)
{
    this->m_Data->bindingsMap[a] = code;
}

void Player::UpdateMap(Transform *pPos, GameVars_t *gVars)
{
    // YUNO
}