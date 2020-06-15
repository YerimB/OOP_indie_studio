/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Collider
*/

#ifndef COLLIDER_H_
#define COLLIDER_H_

#include <ECS/Component.h>
#include <Core.hpp>
#include <GameManager.h>

class Collider : public Component
{
    public:
		static constexpr ComponentId Id = "Collider"_hash;

	public:
		enum class Tag
		{
			None = -1,
			Player1 = 1,
			Player2 = 2,
			Player3 = 3,
			Player4 = 4,
		};
	
    public:
        explicit Collider(const Tag& tag);
    
    public:
        bool Initialize(void* args = nullptr) override final;
		void Update(const float& deltaTime, GameManager* gameManager) override final;
    
    public: // Setters
		void SetTag(const Tag& tag);

    public: // Getters
		[[nodiscard]] const Tag& GetTag() const;
    private:
		Tag m_Tag;
};

#endif /* !COLLIDER_H_ */