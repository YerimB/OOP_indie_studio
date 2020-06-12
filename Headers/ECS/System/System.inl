#pragma once

#include <Core.hpp>
#include <ECS/System/System.h>
#include <iostream>

template <class... Comps>
template <size_t INDEX, class CompType, class... CompArgs>
const bool System<Comps...>::ProcessEntityComponent
(const ComponentId& compId, Component* pComponent, CompTuple& tupleToFill)
{
    if (CompType::Id == compId) {
        std::get<INDEX>(tupleToFill) = static_cast<CompType*>(pComponent);
        return true;
    }
    else
        return (ProcessEntityComponent<INDEX + 1, CompArgs...>(
            compId, pComponent, tupleToFill
        ));
}

template <class... Comps>
template <size_t INDEX>
const bool System<Comps...>::ProcessEntityComponent
(const ComponentId& compId, Component* pComponent, CompTuple& tupleToFill)
{
    return (false);
}

template <class... Comps>
void System<Comps...>::OnEntityCreated(const Entity& entity)
{
    CompTuple compTuple;
    std::size_t matchingComps = 0;

    for (auto &compPair : entity.GetComponents())
        if (this->ProcessEntityComponent<0, Comps...> \
            (compPair.first, compPair.second, compTuple)) {
            ++matchingComps;
            if (matchingComps == sizeof...(Comps)) {
                this->_components.emplace_back(std::move(compTuple));
                this->_entityIdToIndexMap.emplace(
                    entity.GetId(),
                    this->_components.size() - 1
                );
                std::cout << "Added Entity: " << entity.GetName() << std::endl;
                break;
            }
        }
}

template <class... Comps>
void System<Comps...>::OnEntityDestroyed(const EntityId &e_id)
{
    const auto findIt = this->_entityIdToIndexMap.find(e_id);

    if (findIt != this->_entityIdToIndexMap.end()) {
        this->_components[findIt->second] = std::move(this->_components.back());
        this->_components.pop_back();

        const auto *pMovedComp = std::get<0>(this->_components[findIt->second]);
        auto movedTupleIt = this->_entityIdToIndexMap.find(pMovedComp->GetEntityId());
        if (movedTupleIt == this->_entityIdToIndexMap.end())
            std::exit(84);
        movedTupleIt->second = findIt->second;
    }
}