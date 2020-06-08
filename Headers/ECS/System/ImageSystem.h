#pragma once

#include <ECS/System/System.h>
#include <Components/Image.h>
#include <Components/Transform.h>

class ImageSystem : public System<Image, Transform>
{
    using BaseType = System<Image, Transform>;

    public:
        ImageSystem(EntityManager* pEntityManager);

    public:
        virtual void Update(const double& deltaTime) override;
};