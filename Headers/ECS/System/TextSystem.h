#pragma once

#include <ECS/System/System.h>
#include <ECS/EntityManager.h>
#include <Headers/Components/Text.h>
#include <Headers/Components/Transform.h>

class TextSystem : public System<Text, Transform>
{
    using BaseType = System<Text, Transform>;

    public:
        TextSystem(EntityManager* pEntityManager);

    public:
        virtual void Update(const double& deltaTime) override;
};