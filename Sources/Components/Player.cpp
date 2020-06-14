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
    Transform *transform = e.GetComponent<Transform>();

    this->UpdateMap(transform, &gm->m_globalVars);
    this->GetMovements(gm, e);
}

void Player::bindKey(const std::string &a, const irr::EKEY_CODE &code)
{
    this->m_Data->bindingsMap[a] = code;
}

void Player::DropBomb(Entity& self, GameManager* gm)
{
    m_Bomb = new Entity("Bomb" + std::to_string(Id));
    Timer *timer = new Timer();
    Transform* transform = new Transform();
    Drawable* drawable = new Drawable(gm->GetSceneManager());
    float duration = 0.01f;

    timer->Initialize(&duration);
    transform->Initialize(nullptr);
    drawable->Initialize(gm->GetSceneManager()->getMesh("Assets/bob-omb.b3d"));

    transform->SetPosition(self.GetComponent<Transform>()->GetPosition());
    drawable->SetPosition(transform->GetPosition());

    m_Bomb->AddComponent(std::move(timer), Timer::Id);
    m_Bomb->AddComponent(std::move(transform), Transform::Id);
    m_Bomb->AddComponent(std::move(drawable), Drawable::Id);
    gm->GetEntityManager()->AddEntity(*m_Bomb);
}
void Player::GetMovements(GameManager *gm, Entity &self)
{
    bool isMoving = false;
    InputManager *im = gm->GetInputManager();
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
        if (m_Bomb == nullptr)
            DropBomb(self, gm);
    }
    if (m_Bomb != nullptr && m_Bomb->GetComponent<Timer>()->GetDuration() <= 0) {
        m_Bomb->GetComponent<Drawable>()->GetDrawable()->remove();
        m_Bomb = nullptr;
    }
    if (this->m_oldMoveState != isMoving)
        animator->PlayAnimation((isMoving) ? "Run" : "Idle");
    this->m_oldMoveState = isMoving;
}

int get_round(float nb)
{
    float whole, fractional;

    fractional = std::modf(nb, &whole);
    if (fractional > 0.1)
        return static_cast<int>(whole + 1);
    return static_cast<int>(whole);
}

void Player::UpdateMap(Transform *pPos, GameVars_t *gVars)
{
    int x = pPos->GetPosition().X;
    int y = pPos->GetPosition().Z;
    auto s_pos = -(gVars->mapSize * 10.0f) / 2;
    std::array<int, 2> tmp = {
        get_round(gVars->mapSize - (y - s_pos) / 10 ),
        get_round(gVars->mapSize - (x - s_pos) / 10 )
    };
	if (tmp != this->_previousPos)
	{
        if (this->_previousPos[0] != -1)
            gVars->map[_previousPos[1]][_previousPos[0]] = '0';
        gVars->map[tmp[1]][tmp[0]] = 'O';
        _previousPos = tmp;
	}
}