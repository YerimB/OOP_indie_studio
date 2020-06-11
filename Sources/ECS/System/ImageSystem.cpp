#include <ECS/System/ImageSystem.h>

ImageSystem::ImageSystem(EntityManager* pEntityManager) : System<Image, Transform>(pEntityManager)
{
}

void ImageSystem::Update(const double& deltaTime)
{
	for (auto& compTuple : _components)
	{
		Image* img = std::get<Image*>(compTuple);
		Transform* transform = std::get<Transform*>(compTuple);

		auto& pos = transform->GetPosition();
		img->GetImage()->setRelativePosition(Position2i(static_cast<int>(pos.X), static_cast<int>(pos.Y)));

		img->GetImage()->draw();
	}
}