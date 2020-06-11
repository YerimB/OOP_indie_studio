#pragma once

#include <vector>
#include <unordered_map>
#include <iostream>
#include <memory>

#include <Irrlicht/irrlicht.h>
#include <Core.hpp>
#include <ECS/Entity.h>
#include <Components/Button.h>

class InputManager : public irr::IEventReceiver
{
    public:
        InputManager(irr::IrrlichtDevice *device);

    public:
        virtual bool OnEvent(const irr::SEvent& event);
        virtual bool IsKeyDown(irr::EKEY_CODE keyCode) const;
        virtual bool IsButtonDown(const Button::ButtonID& id);
        virtual void ResetButton(const Button::ButtonID& id);

    private:
        irr::IrrlichtDevice* m_Device;
        std::vector<bool> m_KeyDown;
        std::unordered_map<Button::ButtonID, bool> m_Buttons;
        irr::SEvent::SJoystickEvent m_JoystickState;
        std::unordered_map<EntityId, Entity> m_Entities;
};