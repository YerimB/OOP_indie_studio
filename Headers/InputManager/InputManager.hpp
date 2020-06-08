#pragma once

#include <vector>
#include <unordered_map>
#include <iostream>
#include <memory>

#include <Irrlicht/irrlicht.h>
#include <Core.hpp>
#include <ECS/Entity.h>

using namespace irr;

class InputManager : public IEventReceiver
{
    public:
        InputManager(IrrlichtDevice *device);

    public:
        virtual bool OnEvent(const SEvent& event);
        virtual bool IsKeyDown(EKEY_CODE keyCode) const;

    private:
        IrrlichtDevice* m_Device;
        std::vector<bool> m_KeyDown;
        SEvent::SJoystickEvent m_JoystickState;
        std::unordered_map<EntityId, Entity> m_Entities;
};
