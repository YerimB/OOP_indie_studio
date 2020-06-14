/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** TextSystem
*/

#include <ECS/System/TextSystem.h>
#include <string>

TextSystem::TextSystem(EntityManager* pEntityManager) :
BaseType(pEntityManager) {}

void TextSystem::Update(const double& deltaTime)
{
	for (auto& compTuple : _components)
	{
		Text* text = std::get<Text*>(compTuple);
		Transform* transform = std::get<Transform*>(compTuple);

		auto position = transform->GetPosition();
		text->SetPosition(Vector2i(static_cast<int>(position.X), static_cast<int>(position.Y)));
	}
}