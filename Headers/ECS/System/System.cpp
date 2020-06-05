/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** System
*/

#include <System.h>

template <class... Comps>
template <size_t INDEX, class CompType, class... CompArgs>
const bool System<Comps...>::ProcessEntityComponent
(const ComponentId &compId, Component *pComponent, const CompTuple &tupleToFill)
{
    if (CompType::Id == compId) {
        std::get<INDEX>(tupleToFill) = static_cast<CompType *>(pComponent);
        return true;
    } else
        return (ProcessEntityComponent<INDEX + 1, CompArgs...>(
            compId, pComponent, tupleToFill
        ));
}

template <class... Comps>
template <size_t INDEX>
const bool System<Comps...>::ProcessEntityComponent
(const ComponentId &compId, Component *pComponent, const CompTuple &tupleToFill)
{
    return (false);
}

template <class... Comps>
void System<Comps...>::OnEntityCreated(const Entity &entity)
{
    CompTuple compTuple;
    std::size_t matchingComps = 0;

    for (auto &comPair : entity.GetComponents())
        if (this->ProcessEntityComponent<0, Comps...> \
        (compPair.first, compPair.second, compTuple)) {
            ++matchingComps;
            if (matchingComps == sizeof...(Comps)) {
                this->_components.emplace_back(std::move(compTuple));
                break;
            }
        }
}

template <class... Comps>
void System<Comps...>::OnEntityDestroyed(const Entity &entity)
{
    
}