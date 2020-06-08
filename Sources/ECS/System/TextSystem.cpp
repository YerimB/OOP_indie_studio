/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** TextSystem
*/

#include <ECS/System/TextSystem.h>
#include <string>

TextSystem::TextSystem(EntityManager* pEntityManager) : System<Text, Transform>(pEntityManager)
{

}

void TextSystem::Update(const double& deltaTime)
{
	for (auto& compTuple : _components)
	{
		Text* text = std::get<Text*>(compTuple);
		Transform* transform = std::get<Transform*>(compTuple);

		// Fuck you Irrlicht.
	}
}