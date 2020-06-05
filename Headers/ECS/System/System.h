/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** BaseSystem
*/

#pragma once

#include <vector>
#include <tuple>

#include <unordered_map>
#include <Core.hpp>
#include <ECS/Entity.h>
#include <ECS/System/BaseSystem.h>

template <class... Comps>
class System : public BaseSystem
{
	public:
		System(EntityManager *pEntityManager) : BaseSystem(pEntityManager) {}

	public:
        virtual void OnEntityCreated(const Entity &entity) final;
        virtual void OnEntityDestroyed(const Entity &entity) final;
	
	protected:
		using CompTuple = std::tuple<Shared<Comps>...>;
		std::vector<CompTuple> _components;
	
	private:
		template <size_t INDEX, class CompType, class... CompArgs> \
		const bool ProcessEntityComponent(const ComponentId &, Component *, const CompTuple &);
		template <size_t INDEX>
		const bool ProcessEntityComponent(const ComponentId &, Component *, const CompTuple &);
};

#include <ECS/System/System.inl>