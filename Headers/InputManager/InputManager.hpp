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
        enum class JoystickAxis
        {
            Left_Horizontal = 0,
            Left_Vertical = 1,
            Right_Horizontal = 2,
            Right_Vertical = 5
        };

        enum class ControllerButton
        {
            // Xbox                 // PS4
            X = 0,                  // Carré
            A = 1,                  // Croix
            B = 2,                  // Rond
            Y = 3,                  // Triangle
            LB = 4,                 // L1
            RB = 5,                 // R1
            LT = 6,                 // L2
            RT = 7,                 // R2
            Share = 8,
            Options = 9,
            LeftStickButton = 10,
            RightStickButton = 11,
            PowerButton = 12,
            Touchpad = 13           // Only PS4
        };

    public:
        virtual bool OnEvent(const irr::SEvent& event);
        virtual bool IsKeyDown(irr::EKEY_CODE keyCode) const;
        bool IsButtonDown(const Button::ButtonID& id);
        void ResetButton(const Button::ButtonID& id);
        virtual JoystickEvent& GetJoystickEvent();
        int GetAxisValue(const JoystickAxis& axis);
        bool IsControllerButtonDown(const ControllerButton& button);



    private:
        irr::IrrlichtDevice* m_Device;
        std::vector<bool> m_KeyDown;
        std::unordered_map<Button::ButtonID, bool> m_Buttons;
        JoystickEvent m_JoystickState;
        int m_DeadZone = 10000;
};