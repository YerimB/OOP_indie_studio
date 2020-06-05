#pragma once

#include <ECS/Component.h>
#include <Core.hpp>

class Text : public Component
{
	public:
		static constexpr ComponentId Id = __COUNTER__;

	public:
		Text(const std::string& text);

	public:
		bool Initialize(void* args) override final;
		void Update(const float& deltaTime) override final;

	public:
		void SetText(const std::string& text);

	public:
		const std::string GetText() const;

	private:
		std::string m_Text;
};