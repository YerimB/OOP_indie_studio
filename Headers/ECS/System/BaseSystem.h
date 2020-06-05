/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** BaseSystem
*/

#ifndef BASESYSTEM_H_
#define BASESYSTEM_H_

class Entity;
class EntityManager;

class BaseSystem
{
    public:
        explicit BaseSystem(Shared<EntityManager> pEntityManager) :
            _EntityManager(pEntityManager) {};
        virtual ~BaseSystem() = default;

    public:
        virtual void OnEntityCreated(const Entity &entity) = 0;
        virtual void OnEntityDestroyed(const EntityId &id) = 0;
        virtual void Update(const double &detlaTime) = 0;

    protected:
        Shared<EntityManager> _EntityManager;
};

#endif /* !BASESYSTEM_H_ */
