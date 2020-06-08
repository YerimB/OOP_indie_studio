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
		bool Initialize(void* args) override final;
		void Update(const float& deltaTime) override final;
		void Add();

	public:
		void SetText(const std::string& text);
		void SetFont(GuiFont* font);

	public:
		const std::string& GetText() const;
		const GuiFont* GetFont() const;

	private:
		GuiEnvironment *m_GUIEnvironment = nullptr;
		GuiFont *m_Font = nullptr;
		std::string m_Text;
};