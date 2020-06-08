/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Text
*/

#pragma once

#include <ECS/Component.h>
#include <Core.hpp>

class Text : public Component
{
	public:
		static constexpr ComponentId Id = "Text"_hash;

	public:
		Text(GuiEnvironment *GUIEnv);

	public:
		bool Initialize(void* args = nullptr) override final;
		void Update(const float& deltaTime) override final;

	public:
		void SetText(const std::string& text);
		void SetFont(GuiFont* font);
		void SetPosition(const Vector2i &v);
		void SetColor(const Color &newColor = {255, 255, 255, 255});

	public:
		const std::string& GetContent() const;
		const GuiFont* GetFont() const;
		const GuiText* GetText() const;

	private:
		GuiEnvironment *m_GUIEnvironment = nullptr;
		GuiFont *m_Font = nullptr;
		GuiText *m_Text = nullptr;
		std::string m_content;
};