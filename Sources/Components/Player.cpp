/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Player
*/

#include <Components/Player.h>
#include <Components/Transform.h>
#include <Components/Drawable.h>
#include <Components/Collider.h>

Player::Player(SceneManager* manager)
{
    this->_previousPos.fill(-1);
    this->m_SceneManager = manager;
    this->m_Data = nullptr;
    this->_previousPos = { 0, 0 };
}

bool Player::Initialize(void *args)
{
    if (!args)
        return false;
    this->m_Data = static_cast<PlayerData_t *>(args);
    return true;
}

void Player::Update(const float &, GameManager* gm)
{
    auto *e = gm->GetEntityManager()->GetEntity(this->m_EntityId);
    auto *transform = e->GetComponent<Transform>();

    this->UpdateMap(transform, &gm->m_globalVars);
    this->GetMovements(gm, *e);
}

void Player::BindKey(const std::string &a, const irr::EKEY_CODE &code) const
{
    this->m_Data->bindingsMap[a] = code;
}

void Player::DropBomb(Entity& self, GameManager* gm)
{
    m_Bomb = new Entity("Bomb" + std::to_string(Id));
    auto* timer = new Timer();
    auto* transform = new Transform();
    auto* drawable = new Drawable(gm->GetSceneManager());
    auto duration = 1.0f;

    if (!timer->Initialize(&duration) || !transform->Initialize(nullptr) || \
    !drawable->Initialize(gm->GetCurrentScene()->GetMesh("Bomb")))
        return;

    auto gVars = gm->m_globalVars;
    const auto s_pos = -(gVars.mapSize * 10.0f) / 2.0f;
    const auto dpPos = self.GetComponent<Transform>()->GetPosition();
    Vector2f tmp = {
        round(gVars.mapSize - (dpPos.X - s_pos) / 10.0f),
        round(gVars.mapSize - (dpPos.Z - s_pos) / 10.0f)
    };
    this->m_BombPos.set({static_cast<int>(tmp.X), static_cast<int>(tmp.Y)});
    gVars.map[tmp.X][tmp.Y] = 'B';
    tmp.X = -(s_pos + tmp.X * 10.0f);
    tmp.Y = -(s_pos + tmp.Y * 10.0f);

    transform->SetPosition({tmp.X, 0, tmp.Y});
    drawable->SetPosition(transform->GetPosition());

    m_Bomb->AddComponent(timer, Timer::Id);
    m_Bomb->AddComponent(transform, Transform::Id);
    m_Bomb->AddComponent(drawable, Drawable::Id);
    gm->GetEntityManager()->AddEntity(*m_Bomb);
}

void Player::DestroyBlocks(GameManager* gm) const
{
    auto* t = m_Bomb->GetComponent<Transform>();
    const int x = t->GetPosition().X;
    const int y = t->GetPosition().Z;
    const auto sPos = -(gm->m_globalVars.mapSize * 10.0f) / 2.0f;

    Vector2i tmp = {
        static_cast<int>(round(gm->m_globalVars.mapSize - (x - sPos) / 10.0f)),
        static_cast<int>(round(gm->m_globalVars.mapSize - (y - sPos) / 10.0f))
    };
    gm->m_globalVars.map[tmp.X][tmp.Y] = '0';
    if (gm->m_globalVars.map[tmp.X + 1][tmp.Y] == '2')
        gm->m_globalVars.map[tmp.X + 1][tmp.Y] = '0';
    if (gm->m_globalVars.map[tmp.X - 1][tmp.Y] == '2')
        gm->m_globalVars.map[tmp.X - 1][tmp.Y] = '0';
    if (gm->m_globalVars.map[tmp.X][tmp.Y + 1] == '2')
        gm->m_globalVars.map[tmp.X][tmp.Y + 1] = '0';
    if (gm->m_globalVars.map[tmp.X][tmp.Y - 1] == '2')
        gm->m_globalVars.map[tmp.X][tmp.Y - 1] = '0';

    Explosion(gm, m_BombPos);
}

void Player::Explosion(GameManager* gm, const Vector2i& pos) const
{
    auto* e = gm->GetEntityManager()->GetEntity("Star_" + std::to_string(pos.X) + "_" + std::to_string(pos.Y - 1));
    if (e != nullptr) {
        e->GetComponent<Drawable>()->GetDrawable()->remove();
        gm->GetEntityManager()->RemoveEntity(*e);
    }

    e = gm->GetEntityManager()->GetEntity("Star_" + std::to_string(pos.X) + "_" + std::to_string(pos.Y + 1));
    if (e != nullptr) {
        e->GetComponent<Drawable>()->GetDrawable()->remove();
        gm->GetEntityManager()->RemoveEntity(*e);
    }

    e = gm->GetEntityManager()->GetEntity("Star_" + std::to_string(pos.X + 1) + "_" + std::to_string(pos.Y));
    if (e != nullptr) {
        e->GetComponent<Drawable>()->GetDrawable()->remove();
        gm->GetEntityManager()->RemoveEntity(*e);
    }

    e = gm->GetEntityManager()->GetEntity("Star_" + std::to_string(pos.X - 1) + "_" + std::to_string(pos.Y));
    if (e != nullptr) {
        e->GetComponent<Drawable>()->GetDrawable()->remove();
        gm->GetEntityManager()->RemoveEntity(*e);
    }
}

void Player::GetMovements(GameManager *gm, Entity &self)
{
    auto isMoving = false;
    auto* im = gm->GetInputManager();
    auto* transform = self.GetComponent<Transform>();
    auto* animator = self.GetComponent<Animator>();

    if (im->IsKeyDown(m_Data->bindingsMap["UP"]))
    {
        const auto position = transform->GetPosition();

        transform->SetPosition({ position.X + 0.5f, position.Y, position.Z });
        transform->SetRotation({ 0, 270, 0});
        isMoving = true;
    }
    if (im->IsKeyDown(m_Data->bindingsMap["LEFT"]))
    {
        const auto position = transform->GetPosition();

        transform->SetPosition({ position.X, position.Y, position.Z + 0.5f });
        transform->SetRotation({ 0, 180, 0});
        isMoving = true;
    }
    if (im->IsKeyDown(m_Data->bindingsMap["DOWN"]))
    {
        const auto position = transform->GetPosition();

        transform->SetPosition({ position.X - 0.5f, position.Y, position.Z });
        transform->SetRotation({ 0, 90, 0});
        isMoving = true;
    }
    if (im->IsKeyDown(m_Data->bindingsMap["RIGHT"]))
    {
       const auto position = transform->GetPosition();

        transform->SetPosition({ position.X, position.Y, position.Z - 0.5f });
        transform->SetRotation({ 0, 0, 0});
        isMoving = true;
    }
    if (im->IsKeyDown(m_Data->bindingsMap["DROP"]))
    {
        if (m_Bomb == nullptr)
            DropBomb(self, gm);
    }
    if (m_Bomb != nullptr && m_Bomb->GetComponent<Timer>()->GetDuration() <= 0) {
        DestroyBlocks(gm);
        m_Bomb->GetComponent<Drawable>()->GetDrawable()->remove();
        gm->GetEntityManager()->RemoveEntity(*m_Bomb);
        m_Bomb = nullptr;
    }
    if (this->m_oldMoveState != isMoving)
        animator->PlayAnimation((isMoving) ? "Run" : "Idle");
    this->m_oldMoveState = isMoving;
}

void Player::UpdateMap(Transform *pPos, GameVars_t *gVars)
{
    const int x = pPos->GetPosition().X;
    const int y = pPos->GetPosition().Z;
    const auto sPos = -(gVars->mapSize * 10.0f) / 2;
    std::array<int, 2> tmp = {
        static_cast<int>(round(gVars->mapSize - (y - sPos) / 10.0f)),
        static_cast<int>(round(gVars->mapSize - (x - sPos) / 10.0f))
    };
	
    if (tmp != this->_previousPos)
    {
        if (this->_previousPos[0] != -1)
            gVars->map[_previousPos[1]][_previousPos[0]] = '0';
        if (gVars->map[tmp[1]][tmp[0]] != 'B')
            gVars->map[tmp[1]][tmp[0]] = 'E';
        _previousPos = tmp;
    }
}