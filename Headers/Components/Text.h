#pragma once

#include <ECS/Component.h>
#include <Core.hpp>

class Text : public Component
{
	public:
		static constexpr ComponentId Id = __COUNTER__;

	public:
		Text();

	public:
		bool Initialize(void* args) override final;
		void Update(const float& deltaTime) override final;

	public:
		void SetText(const std::string& text);
		void SetFont(GuiFont* font);

	public:
		const std::string& GetText() const;
		const GuiFont* GetFont() const;

	private:
		GuiFont* m_Font;
		std::string m_Text;
};