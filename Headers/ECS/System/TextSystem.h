#pragma once

#include <ECS/System/System.h>
#include <ECS/EntityManager.h>
#include <Components/Text.h>
#include <Components/Transform.h>

class TextSystem : public System<Text, Transform>
{
    using BaseType = System<Text, Transform>;

    public:
        TextSystem(EntityManager* pEntityManager);

    public:
        virtual void Update(const double& deltaTime) override;
};